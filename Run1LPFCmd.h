#pragma once


// CRun1LPFCmd dialog

class CRun1LPFCmd : public CDialogEx
{
	DECLARE_DYNAMIC(CRun1LPFCmd)

public:
	CRun1LPFCmd(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRun1LPFCmd();

// Dialog Data
	enum { IDD = IDD_DIA_RUN1LPFCMD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
   CString m_sInput;
};
