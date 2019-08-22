
/* UnittestDoc.cpp : implementation of the CUnittestDoc class

   Copyright (c) 1987-2019 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestBenchOlrxAPI.h"
#endif

#include "UnittestDoc.h"
#include <propkey.h>
#include <AtlBase.h>
#include <AtlConv.h>
#include "TTYWindow.h"
#include "olrxapi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CUnittestDoc, CDocument)

BEGIN_MESSAGE_MAP(CUnittestDoc, CDocument)
   ON_COMMAND( ID_TEST_DATAACCESS, &CUnittestDoc::OnTestDataAccess )
   ON_UPDATE_COMMAND_UI( ID_TEST_DATAACCESS, &CUnittestDoc::OnUpdateTestDataAccess )
   ON_COMMAND( ID_TEST_FAULTSIMULATION, &CUnittestDoc::OnTestFaultSimulation )
   ON_UPDATE_COMMAND_UI( ID_TEST_FAULTSIMULATION, &CUnittestDoc::OnUpdateTestFaultSimulation )
END_MESSAGE_MAP()


// CUnittestDoc construction/destruction

CUnittestDoc::CUnittestDoc()
{
   m_nFileOpen = 0;

}

CUnittestDoc::~CUnittestDoc()
{
}

BOOL CUnittestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


// CUnittestDoc serialization

void CUnittestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CUnittestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CUnittestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CUnittestDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CUnittestDoc diagnostics

#ifdef _DEBUG
void CUnittestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUnittestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////////////////
// CUnittestDoc commands 
//
void ShowTTY( CString sText, BOOL bAppend );
BOOL CUnittestDoc::OnOpenDocument( LPCTSTR lpszPathName ) {
   if ( OLRXAPI_OK != OlrxAPILoadDataFile( (char*)lpszPathName, FALSE ) ) {
      if ( OLRXAPI_OK != OlrxAPILoadDataFile( (char*)lpszPathName, TRUE ) ) {
         AfxMessageBox( OlrxAPIErrorString() );
         m_nFileOpen = 0;
         return FALSE;
      }
      m_nFileOpen = 2;
      AfxMessageBox( "File had been openned in read-only mode." );
   } else {
      m_nFileOpen = 1;
      AfxMessageBox( "File had been openned successfully" );
   }
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////
void CUnittestDoc::OnUpdateTestDataAccess( CCmdUI *pCmdUI ) {
   pCmdUI->Enable( m_nFileOpen == 0 ? FALSE : TRUE );
}

void CUnittestDoc::OnTestDataAccess() {
//   CTTYWindow ttyDlg;
   int NObus, nHnd;
   double dKV;
   char szName[100];
   CString sT, sTTYText;

   if ( OLRXAPI_OK != OlrxAPIGetData( HND_SYS, SY_nNObus, &NObus ) ) {
      AfxMessageBox( OlrxAPIErrorString() );
      return;
   }
   sTTYText.Format( "OLR Network: %s\r\n\r\nNObus = %d", OlrxAPIGetOlrFileName(), NObus );
   nHnd = 0;
   while ( OLRXAPI_OK == OlrxAPIGetEquipment( TC_BUS, &nHnd ) ) {
      if ( OLRXAPI_OK != OlrxAPIGetData( nHnd, BUS_sName, szName ) ) {
         AfxMessageBox( OlrxAPIErrorString() );
         return;
      }
      if ( OLRXAPI_OK != OlrxAPIGetData( nHnd, BUS_dKVnominal, &dKV ) ) {
         AfxMessageBox( OlrxAPIErrorString() );
         return;
      }
      sT.Format( "%s %gkV", szName, dKV );
      sTTYText += "\r\n" + sT;
   }
//   ttyDlg.DoModal();
   ShowTTY( sTTYText, FALSE );
}

/////////////////////////////////////////////////////////////////////////////////////////
void CUnittestDoc::OnUpdateTestFaultSimulation( CCmdUI *pCmdUI ) {
   OnUpdateTestDataAccess( pCmdUI );
}

void CUnittestDoc::OnTestFaultSimulation() {
   BOOL bOK = FALSE;
   int nBusHnd = 0, nBrHnd, nBus2Hnd;
   int nFltConn[4], nOutageOpt[4], nOutageLst[500], nClearPrev = 1;
   double dFltOpt[15], dFltR = 0.0, dFltX = 0.0, vdOut1[9], vdOut2[9], vdIOut1[12], vdIOut2[12];
   CString strText, strTTY;

   SecureZeroMemory( dFltOpt, 15 * sizeof(double) );
   SecureZeroMemory( nFltConn, 4 * sizeof(int) );
   SecureZeroMemory( nOutageOpt, 4 * sizeof(int) );
   SecureZeroMemory( nOutageLst, 500 * sizeof(int) );

   nFltConn[0] = 0;  // 3LG
   nFltConn[1] = 0;  // 2LG
   nFltConn[2] = 1;  // 1LG
   nFltConn[3] = 0;  // LL

   dFltOpt[0] = 1;

   ShowTTY( "", FALSE );

   nBusHnd = 0;
   do {
      if ( OLRXAPI_OK != OlrxAPIGetEquipment(TC_BUS, &nBusHnd) ) {
         AfxMessageBox( OlrxAPIErrorString() );
         return;
      }
      if ( OLRXAPI_FAILED == OlrxAPIDoFault( nBusHnd, nFltConn, dFltOpt, nOutageOpt, nOutageLst, dFltR, dFltX, nClearPrev ) ) {
         AfxMessageBox( OlrxAPIErrorString() );
         return;
      }
      if ( OLRXAPI_FAILED == OlrxAPIPickFault( SF_FIRST, 1 ) ) {
         AfxMessageBox( OlrxAPIErrorString() );
         return;
      }
      strTTY = OlrxAPIFaultDescription( 0 );
      nBrHnd = 0;
      while ( OLRXAPI_OK == OlrxAPIGetBusEquipment( nBusHnd, TC_BRANCH, &nBrHnd ) ) {
         if ( OLRXAPI_FAILED == OlrxAPIGetSCVoltage( nBrHnd, vdOut1, vdOut2, 4 ) ) {
            AfxMessageBox( OlrxAPIErrorString() );
            return;
         }
         if ( OLRXAPI_FAILED == OlrxAPIGetSCCurrent( nBrHnd, vdIOut1, vdIOut2, 4 ) ) {
            AfxMessageBox( OlrxAPIErrorString() );
            return;
         }
         if ( OLRXAPI_FAILED == OlrxAPIGetData( nBrHnd, BR_nBus2Hnd, &nBus2Hnd ) ) {
            AfxMessageBox( OlrxAPIErrorString() );
            return;
         }
         strText.Format( "%s Va=%.1f@%.1f Vb=%.1f@%.1f Vc=%.1f@%.1f\r\n"
                         "%s Va=%.1f@%.1f Vb=%.1f@%.1f Vc=%.1f@%.1f\r\n"
                         "Ia=%.1f@%.1f Ib=%.1f@%.1f Ic=%.1f@%.1f",
                         OlrxAPIFullBusName( nBusHnd ), vdOut1[0], vdOut2[0], vdOut1[1], vdOut2[1], vdOut1[2], vdOut2[2],
                         OlrxAPIFullBusName( nBus2Hnd ), vdOut1[3], vdOut2[3], vdOut1[4], vdOut2[4], vdOut1[5], vdOut2[5],
                         vdIOut1[0], vdIOut2[0], vdIOut1[1], vdIOut2[1], vdIOut1[2], vdIOut2[2] );
         strTTY += "\r\n" + strText;
      }
      ShowTTY( strTTY, TRUE );
      if ( IDYES != AfxMessageBox( "Continue?", MB_YESNO ) )
         break;
   } while ( nBusHnd > 0 );
}

//
/////////////////////////////////////////////////////////////////////////////////////////



