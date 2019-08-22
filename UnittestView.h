
/* UnittestView.h : interface of the CUnittestView class
   Copyright (c) 1987-2019 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/

#pragma once


class CUnittestView : public CView
{
protected: // create from serialization only
	CUnittestView();
	DECLARE_DYNCREATE(CUnittestView)

// Attributes
public:
	CUnittestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CUnittestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UnittestView.cpp
inline CUnittestDoc* CUnittestView::GetDocument() const
   { return reinterpret_cast<CUnittestDoc*>(m_pDocument); }
#endif

