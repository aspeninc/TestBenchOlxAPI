#pragma once

// CDiffAndMerge dialog

class CDiffAndMerge : public CDialogEx
{
	DECLARE_DYNAMIC(CDiffAndMerge)

public:
	CDiffAndMerge(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDiffAndMerge();

// Dialog Data
	enum { IDD = IDD_DIA_COMPNMERGE };
   CString m_strPathName[5]; // 0-2: File A, B, Base; 3-Diff; 4-Merged
   BOOL m_bDoMerge, m_bDo1L;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
   afx_msg void OnBnClickedButtonA();
   afx_msg void OnBnClickedButtonB();
   afx_msg void OnBnClickedButtonDiffFile();
   virtual void OnOK();
   virtual BOOL OnInitDialog();
   afx_msg void OnBnClickedButtonBase();
   afx_msg void OnBnClickedMerge();
   afx_msg void OnBnClickedCompare();
   afx_msg void OnBnClickedButtonmerge();
};
