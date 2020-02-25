
/* UnittestView.cpp : implementation of the CUnittestView class

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
#include "UnittestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUnittestView

IMPLEMENT_DYNCREATE(CUnittestView, CView)

BEGIN_MESSAGE_MAP(CUnittestView, CView)
END_MESSAGE_MAP()

// CUnittestView construction/destruction

CUnittestView::CUnittestView()
{
	// TODO: add construction code here

}

CUnittestView::~CUnittestView()
{
}

BOOL CUnittestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CUnittestView drawing

void CUnittestView::OnDraw(CDC* /*pDC*/)
{
	CUnittestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CUnittestView diagnostics

#ifdef _DEBUG
void CUnittestView::AssertValid() const
{
	CView::AssertValid();
}

void CUnittestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUnittestDoc* CUnittestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUnittestDoc)));
	return (CUnittestDoc*)m_pDocument;
}
#endif //_DEBUG


// CUnittestView message handlers
