#pragma once


// CTTYWindow dialog

class CTTYWindow : public CDialogEx
{
	DECLARE_DYNAMIC(CTTYWindow)

public:
	CTTYWindow(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTTYWindow();

// Dialog Data
	enum { IDD = IDD_DIA_TTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   void OnClose();
   void PostNcDestroy();

	DECLARE_MESSAGE_MAP()
public:
   virtual BOOL OnInitDialog();
   CString m_sText;
   afx_msg void OnSize( UINT nType, int cx, int cy );
};
