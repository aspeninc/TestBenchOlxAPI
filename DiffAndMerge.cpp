/* DiffAndMerge.cpp : implementation file

   Copyright (c) 1987-2019 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/


#include "stdafx.h"
#include "TestBenchOlxAPI.h"
#include "DiffAndMerge.h"
#include "afxdialogex.h"
#include "OlxAPI.h"

// CDiffAndMerge dialog

IMPLEMENT_DYNAMIC(CDiffAndMerge, CDialogEx)

CDiffAndMerge::CDiffAndMerge(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiffAndMerge::IDD, pParent)
{
   m_strPathName[0] = "";
   m_strPathName[1] = "";
   m_strPathName[2] = "";
   m_strPathName[3] = "";
   m_bDoMerge = FALSE;
}

CDiffAndMerge::~CDiffAndMerge()
{
}

void CDiffAndMerge::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiffAndMerge, CDialogEx)
   ON_BN_CLICKED( IDC_BUTTONA, &CDiffAndMerge::OnBnClickedButtonA )
   ON_BN_CLICKED( IDC_BUTTONB, &CDiffAndMerge::OnBnClickedButtonB )
   ON_BN_CLICKED( IDC_BUTTONBASE, &CDiffAndMerge::OnBnClickedButtonBase )
   ON_BN_CLICKED( IDC_BUTTONDIFF, &CDiffAndMerge::OnBnClickedButtonDiffFile )
   ON_BN_CLICKED( IDOK2, &CDiffAndMerge::OnBnClickedMerge )
   ON_BN_CLICKED( IDOK, &CDiffAndMerge::OnBnClickedCompare )
END_MESSAGE_MAP()


// CDiffAndMerge message handlers
BOOL CDiffAndMerge::OnInitDialog() {
   CDialogEx::OnInitDialog();

   SetDlgItemText( IDC_EDITA, m_strPathName[0] );
   SetDlgItemText( IDC_EDITB, m_strPathName[1] );
   SetDlgItemText( IDC_EDITBASE, m_strPathName[2] );

   CheckDlgButton( IDC_CHECK_1L, TRUE );

   return TRUE;  // return TRUE unless you set the focus to a control
   // EXCEPTION: OCX Property Pages should return FALSE
}

void CDiffAndMerge::OnBnClickedButtonA() {
   CFileDialog cFD( TRUE, "*.OLR", NULL, NULL,
                    "OneLiner Data File (*.OLR)|*.OLR||" );
   cFD.m_ofn.lpstrTitle = "File A";
   if ( cFD.DoModal() != IDOK )
      return;
   SetDlgItemText( IDC_EDITA, cFD.GetPathName() );
}

void CDiffAndMerge::OnBnClickedButtonB() {
   CFileDialog cFD( TRUE, "*.OLR", NULL, NULL,
                    "OneLiner Data File (*.OLR)|*.OLR||" );
   cFD.m_ofn.lpstrTitle = "File B";
   if ( cFD.DoModal() != IDOK )
      return;
   SetDlgItemText( IDC_EDITB, cFD.GetPathName() );
}

void CDiffAndMerge::OnBnClickedButtonBase() {
   CFileDialog cFD( TRUE, "*.OLR", NULL, NULL,
                    "OneLiner Data File (*.OLR)|*.OLR||" );
   cFD.m_ofn.lpstrTitle = "File A and B Common Base";
   if ( cFD.DoModal() != IDOK )
      return;
   SetDlgItemText( IDC_EDITBASE, cFD.GetPathName() );
}

void CDiffAndMerge::OnBnClickedButtonDiffFile() {
   CFileDialog cFD( FALSE, "*.XML", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
                    "OneLiner Diff File (*.XML)|*.XML||" );
   cFD.m_ofn.lpstrTitle = "Diff File";
   if ( cFD.DoModal() != IDOK )
      return;
   SetDlgItemText( IDC_EDITDIFF, cFD.GetPathName() );
}

void CDiffAndMerge::OnBnClickedButtonmerge() {
   CFileDialog cFD( FALSE, "*.OLR", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
                    "OneLiner Data File (*.OLR)|*.OLR||" );
   cFD.m_ofn.lpstrTitle = "Merged File";
   if ( cFD.DoModal() != IDOK )
      return;
   SetDlgItemText( IDC_EDITMERGE, cFD.GetPathName() );
}

void CDiffAndMerge::OnBnClickedMerge() {
   m_bDoMerge = TRUE;
   OnOK();
}

void CDiffAndMerge::OnBnClickedCompare() {
   m_bDoMerge = FALSE;
   OnOK();
}

void CDiffAndMerge::OnOK() {
   FILE *fFile;

   GetDlgItemText( IDC_EDITA, m_strPathName[0] );
   if ( m_strPathName[0] != "" && m_strPathName[0] != "N/A" ) {
      fFile = fopen( m_strPathName[0], "r" );
      if ( !fFile ) {
         MessageBox( "File A path name is invalid." );
         return;
      }
      fclose( fFile );
   }
   GetDlgItemText( IDC_EDITB, m_strPathName[1] );
   if ( m_strPathName[1] == "" ) {
      MessageBox( "File B path name is missing." );
      return;
   }
   fFile = fopen( m_strPathName[1], "r" );
   if ( !fFile ) {
      MessageBox( "File B path name is invalid." );
      return;
   }
   fclose( fFile );
   if ( m_strPathName[0] == m_strPathName[1] ) {
      MessageBox( "File A and B cannot be the same." );
      return;
   }
   GetDlgItemText( IDC_EDITBASE, m_strPathName[2] );
   if ( m_strPathName[0] == m_strPathName[2] ) {
      MessageBox( "File A and Base cannot be the same." );
      return;
   }
   if ( m_strPathName[1] == m_strPathName[2] ) {
      MessageBox( "File B and Base cannot be the same." );
      return;
   }
   if ( m_strPathName[2] != "" && m_strPathName[2] != "N/A" ) {
      fFile = fopen( m_strPathName[2], "r" );
      if ( !fFile ) {
         MessageBox( "Base path name is invalid." );
         return;
      }
      fclose( fFile );
   }
   GetDlgItemText( IDC_EDITDIFF, m_strPathName[3] );
   if ( m_strPathName[3] != "" && m_strPathName[3] != "N/A" ) {
      fFile = fopen( m_strPathName[3], "w" );
      if ( !fFile ) {
         MessageBox( "Diff path name is invalid." );
         return;
      }
      fclose( fFile );
      DeleteFile( m_strPathName[3] );
   }
   GetDlgItemText( IDC_EDITMERGE, m_strPathName[4] );
   if ( m_strPathName[4] != "" && m_strPathName[4] != "N/A" ) {
      fFile = fopen( m_strPathName[4], "w" );
      if ( !fFile ) {
         MessageBox( "Merged path name is invalid." );
         return;
      }
      fclose( fFile );
      DeleteFile( m_strPathName[3] );
   }
   m_bDo1L = IsDlgButtonChecked( IDC_CHECK_1L ) ? FALSE:TRUE;
   CDialogEx::OnOK();
}

//
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <string>

void TestDiffNMerge() {
   CDiffAndMerge dlg;

   if ( IDOK != dlg.DoModal() )
      return;
   CString sFileA = dlg.m_strPathName[0];
   CString sFileB = dlg.m_strPathName[1];
   CString sFileBase = dlg.m_strPathName[2];
   CString sPath = sFileA;
   sPath = sPath.Left( sPath.ReverseFind( '\\' ) + 1 );

   // MergedAB must be the same as B
   // Merge A to B
   CString sFileDiff = sPath + CString( "Diff_A_B.xlm" );
   CString sFileMerged = sPath + CString( "MergedAB.olr" );
   CString sXML = 
      CString( "<DIFFANDMERGE " ) +
      CString( "FILEPATHA =\"" ) + sFileA + CString( "\" " ) +
      CString( "FILEPATHB =\"" ) + sFileB + CString( "\" " ) +
//      CString( "FILEPATHBASE =\"" ) + sFileBase + CString( "\" " ) +
      CString( "FILEPATHDIFF =\"" ) + sFileDiff + CString( "\" " ) +
      CString( "FILEPATHMERGED =\"" ) + sFileMerged + CString( "\" " ) +
      CString( " />" );
   if ( OLRXAPI_OK != OlxAPIRun1LPFCommand( sXML.GetBuffer() ) )
      AfxMessageBox( OlxAPIErrorString() );
   // MergedAB and B must be the same
   sFileDiff = sPath + CString( "Diff_MergedAB_B.xlm" );
   sXML = 
      CString( "<DIFFANDMERGE " ) +
      CString( "FILEPATHA =\"" ) + sFileMerged + CString( "\" " ) +
      CString( "FILEPATHB =\"" ) + sFileB + CString( "\" " ) +
//      CString( "FILEPATHBASE =\"" ) + sFileBase + CString( "\" " ) +
      CString( "FILEPATHDIFF =\"" ) + sFileDiff + CString( "\" " ) +
      CString( " />" );
   if ( OLRXAPI_OK != OlxAPIRun1LPFCommand( sXML.GetBuffer() ) )
      AfxMessageBox( OlxAPIErrorString() );
   std::ifstream diffFile( sFileDiff );
   std::string line;
   int nChange = 0;
   if ( diffFile.is_open() ) {
      while ( std::getline( diffFile, line ) ) {
         CString sT( line.c_str() );
         if ( sT.Find( "CHANGEREC" ) > -1 ) {
            ++nChange;
         }
      }
   }
   if ( nChange )
      AfxMessageBox( "Error: MergedAB != B" );
   else
      AfxMessageBox( "MergedAB == B" );
}



