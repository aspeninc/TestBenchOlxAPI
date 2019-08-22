
/* UnittestDoc.h : interface of the CUnittestDoc class
   Copyright (c) 1987-2019 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/

#pragma once


class CUnittestDoc : public CDocument
{
protected: // create from serialization only
	CUnittestDoc();
	DECLARE_DYNCREATE(CUnittestDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument( LPCTSTR lpszPathName );
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CUnittestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   BOOL m_nFileOpen;  // 0-No; 1-ReadWrite; 2-Readonly;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
   afx_msg void OnTestDataAccess();
   afx_msg void OnUpdateTestDataAccess( CCmdUI *pCmdUI );
   afx_msg void OnTestFaultSimulation();
   afx_msg void OnUpdateTestFaultSimulation( CCmdUI *pCmdUI );
};
