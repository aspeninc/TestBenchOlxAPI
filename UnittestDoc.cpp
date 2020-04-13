
/* UnittestDoc.cpp : implementation of the CUnittestDoc class

   Copyright (c) 1987-2019 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestBenchOlxAPI.h"
#endif

#include "UnittestDoc.h"
#include <propkey.h>
#include <AtlBase.h>
#include <AtlConv.h>
#include "TTYWindow.h"
#include "olxapi.h"
#include "Run1LPFCmd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CUnittestDoc, CDocument)

BEGIN_MESSAGE_MAP(CUnittestDoc, CDocument)
   ON_COMMAND( ID_TEST_DATAACCESS, &CUnittestDoc::OnTestDataAccess )
   ON_UPDATE_COMMAND_UI( ID_TEST_DATAACCESS, &CUnittestDoc::OnUpdateTestDataAccess )
   ON_COMMAND( ID_TEST_FAULTSIMULATION, &CUnittestDoc::OnTestFaultSimulation )
   ON_UPDATE_COMMAND_UI( ID_TEST_FAULTSIMULATION, &CUnittestDoc::OnUpdateTestFaultSimulation )
   ON_UPDATE_COMMAND_UI( ID_TEST_DIFFANDMERGE, &CUnittestDoc::OnUpdateTestDiffandMerge )
   ON_COMMAND( ID_TEST_DIFFANDMERGE, &CUnittestDoc::OnTestDiffandMerge )
   ON_COMMAND( ID_TEST_RUN1LPFCMD, &CUnittestDoc::OnTestRun1lPFCmd )
   ON_UPDATE_COMMAND_UI( ID_TEST_RUN1LPFCMD, &CUnittestDoc::OnUpdateTestRun1LPFCmd )
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
   int nRet;
   CString sMsg;
   m_nFileOpen = 0;
   nRet = OlxAPILoadDataFile( (char*)lpszPathName, FALSE );
   if ( OLXAPI_FAILURE == nRet ) {// Retry with readonly flag
      nRet = OlxAPILoadDataFile( (char*)lpszPathName, TRUE );
      if ( OLRXAPI_FAILURE == nRet  ) {
            AfxMessageBox( OlxAPIErrorString() );
            return FALSE;
      }
      m_nFileOpen = 2;
      sMsg = "File had been openned as read-only.";
   } else {
      m_nFileOpen = 1;
      sMsg = "File had been openned successfully.";
   }
   if ( nRet == OLXAPI_DATAFILEANOMALIES )
      sMsg += CString("\n") + OlxAPIErrorString();
   AfxMessageBox( sMsg );
   if (  nRet == OLXAPI_DATAFILEANOMALIES ) {
      char szFilePath[MAX_PATH], szLine[512];
      GetTempPath( MAX_PATH, szFilePath );
      strcat( szFilePath, pszPSTTYLogFileName );
      FILE *fLogFile = fopen( szFilePath, "rt" );
      if ( fLogFile ) {
         sMsg = "";
         while ( !feof( fLogFile ) ) {
            if ( fgets( szLine, 512, fLogFile ) )
                 sMsg += szLine + CString("\r\n");
         }
         ShowTTY( sMsg, FALSE );
      }
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

   if ( OLRXAPI_OK != OlxAPIGetData( HND_SYS, SY_nNObus, &NObus ) ) {
      AfxMessageBox( OlxAPIErrorString() );
      return;
   }
   sTTYText.Format( "OLR Network: %s\r\n\r\nNObus = %d", OlxAPIGetOlrFileName(), NObus );
   nHnd = 0;
   while ( OLRXAPI_OK == OlxAPIGetEquipment( TC_BUS, &nHnd ) ) {
      if ( OLRXAPI_OK != OlxAPIGetData( nHnd, BUS_sName, szName ) ) {
         AfxMessageBox( OlxAPIErrorString() );
         return;
      }
      if ( OLRXAPI_OK != OlxAPIGetData( nHnd, BUS_dKVnominal, &dKV ) ) {
         AfxMessageBox( OlxAPIErrorString() );
         return;
      }
      sT.Format( "%s %gkV", szName, dKV );
      sTTYText += "\r\n" + sT;
   }
//   ttyDlg.DoModal();
   ShowTTY( sTTYText, FALSE );
}
/////////////////////////////////////////////////////////////////////////////////////////
void CUnittestDoc::OnUpdateTestDiffandMerge( CCmdUI *pCmdUI ) {
   pCmdUI->Enable( m_nFileOpen == 0 ? TRUE : FALSE );  // No open file 
}

void CUnittestDoc::OnTestDiffandMerge() {
   void TestDiffNMerge();
   TestDiffNMerge();
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
      if ( OLRXAPI_OK != OlxAPIGetEquipment(TC_BUS, &nBusHnd) ) {
         AfxMessageBox( OlxAPIErrorString() );
         return;
      }
      if ( OLRXAPI_FAILED == OlxAPIDoFault( nBusHnd, nFltConn, dFltOpt, nOutageOpt, nOutageLst, dFltR, dFltX, nClearPrev ) ) {
         AfxMessageBox( OlxAPIErrorString() );
         return;
      }
      if ( OLRXAPI_FAILED == OlxAPIPickFault( SF_FIRST, 1 ) ) {
         AfxMessageBox( OlxAPIErrorString() );
         return;
      }
      strTTY = OlxAPIFaultDescription( 0 );
      nBrHnd = 0;
      while ( OLRXAPI_OK == OlxAPIGetBusEquipment( nBusHnd, TC_BRANCH, &nBrHnd ) ) {
         if ( OLRXAPI_FAILED == OlxAPIGetSCVoltage( nBrHnd, vdOut1, vdOut2, 4 ) ) {
            AfxMessageBox( OlxAPIErrorString() );
            return;
         }
         if ( OLRXAPI_FAILED == OlxAPIGetSCCurrent( nBrHnd, vdIOut1, vdIOut2, 4 ) ) {
            AfxMessageBox( OlxAPIErrorString() );
            return;
         }
         if ( OLRXAPI_FAILED == OlxAPIGetData( nBrHnd, BR_nBus2Hnd, &nBus2Hnd ) ) {
            AfxMessageBox( OlxAPIErrorString() );
            return;
         }
         strText.Format( "%s Va=%.1f@%.1f Vb=%.1f@%.1f Vc=%.1f@%.1f\r\n"
                         "%s Va=%.1f@%.1f Vb=%.1f@%.1f Vc=%.1f@%.1f\r\n"
                         "Ia=%.1f@%.1f Ib=%.1f@%.1f Ic=%.1f@%.1f",
                         OlxAPIFullBusName( nBusHnd ), vdOut1[0], vdOut2[0], vdOut1[1], vdOut2[1], vdOut1[2], vdOut2[2],
                         OlxAPIFullBusName( nBus2Hnd ), vdOut1[3], vdOut2[3], vdOut1[4], vdOut2[4], vdOut1[5], vdOut2[5],
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

/////////////////////////////////////////////////////////////////////////////////////////
//
void CUnittestDoc::OnTestRun1lPFCmd() {
   CRun1LPFCmd dlg;

   if ( IDOK != dlg.DoModal() )
      return;
   if ( OLRXAPI_FAILED == OlxAPIRun1LPFCommand( dlg.m_sInput.GetBuffer() ) ) {
      AfxMessageBox( OlxAPIErrorString() );
      return;
   } else {
      AfxMessageBox( "Command excuted successfully." );
   }
}

void CUnittestDoc::OnUpdateTestRun1LPFCmd( CCmdUI *pCmdUI ) {
   pCmdUI->Enable( TRUE );
}
//
/////////////////////////////////////////////////////////////////////////////////////////
