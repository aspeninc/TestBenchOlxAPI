/* TTYWindow.cpp : implementation file

   Copyright (c) 1987-2019 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/

#include "stdafx.h"
#include "TestBenchOlrxAPI.h"
#include "TTYWindow.h"
#include "afxdialogex.h"


CTTYWindow *pTTYWindow = NULL;
// CTTYWindow dialog

IMPLEMENT_DYNAMIC(CTTYWindow, CDialogEx)

CTTYWindow::CTTYWindow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTTYWindow::IDD, pParent)
   , m_sText( _T( "" ) )
{
   m_sText = "";

}

CTTYWindow::~CTTYWindow()
{
}

void CTTYWindow::DoDataExchange(CDataExchange* pDX)
{
   CDialogEx::DoDataExchange( pDX );
   DDX_Text( pDX, IDC_EDIT1, m_sText );
}


BEGIN_MESSAGE_MAP(CTTYWindow, CDialogEx)
   ON_WM_SIZE()
END_MESSAGE_MAP()


// CTTYWindow message handlers


BOOL CTTYWindow::OnInitDialog()
{
   CDialogEx::OnInitDialog();


   return TRUE;  // return TRUE unless you set the focus to a control
   // EXCEPTION: OCX Property Pages should return FALSE
}


void CTTYWindow::OnSize( UINT nType, int cx, int cy ) {
   CDialogEx::OnSize( nType, cx, cy );
   CWnd *pEdit;
   if ( !(pEdit = GetDlgItem( IDC_EDIT1 )) )
      return;
   CRect cRect, cRect1;
   GetClientRect( &cRect );
   pEdit->GetWindowRect( &cRect1 );
   ScreenToClient( &cRect1 );
   cRect1.right = cRect.right - cRect1.left;
   cRect1.bottom = cRect.bottom - cRect1.top;
   pEdit->MoveWindow( &cRect1 );
}

void CTTYWindow::OnClose() {
	DestroyWindow();
}

void CTTYWindow::PostNcDestroy() {
	CDialog::PostNcDestroy();
   pTTYWindow = NULL;
   delete this;
}

void ShowTTY( CString sText, BOOL bAppend ) {
   if ( pTTYWindow == NULL ) {
      pTTYWindow = new CTTYWindow;
      pTTYWindow->Create( CTTYWindow::IDD, NULL );
   }
   if ( !bAppend || pTTYWindow->m_sText.GetLength() == 0 )
      pTTYWindow->m_sText = sText;
   else
      pTTYWindow->m_sText += "\r\n" + sText;
   pTTYWindow->UpdateData( FALSE );
   pTTYWindow->SendDlgItemMessage( IDC_EDIT1, EM_SETSEL, pTTYWindow->m_sText.GetLength(), pTTYWindow->m_sText.GetLength() );
   pTTYWindow->ShowWindow( SW_NORMAL );
}