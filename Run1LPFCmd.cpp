// Run1LPFCmd.cpp : implementation file
// 
// Copyright (c) 1987-2020 Advanced Systems for Power Engineering, Inc. (ASPEN).
//   All rights reserved. 
//

#include "stdafx.h"
#include "TestBenchOlxAPI.h"
#include "Run1LPFCmd.h"
#include "afxdialogex.h"


// CRun1LPFCmd dialog

IMPLEMENT_DYNAMIC(CRun1LPFCmd, CDialogEx)

CRun1LPFCmd::CRun1LPFCmd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRun1LPFCmd::IDD, pParent)
   , m_sInput( "" ) {

}

CRun1LPFCmd::~CRun1LPFCmd()
{
}

void CRun1LPFCmd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sInput);
}


BEGIN_MESSAGE_MAP(CRun1LPFCmd, CDialogEx)
END_MESSAGE_MAP()


// CRun1LPFCmd message handlers
