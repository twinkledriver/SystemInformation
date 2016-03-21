#include "afxwin.h"
#include "Resource.h"

#if !defined(AFX_SYSTEMINFOTESTDLG_H__B644FC25_83FB_498B_A681_93CE0442F796__INCLUDED_)
#define AFX_SYSTEMINFOTESTDLG_H__B644FC25_83FB_498B_A681_93CE0442F796__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cpuUsage.h"
#define DIV 1024

class CSystemInfoTestDlg : public CDialog
{
// Construction
public:
	void GetCurrentNetSpeed();
	CCpuUsage m_cpuUsage;
	CSystemInfoTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSystemInfoTestDlg)
	enum { IDD = IDD_SYSTEMINFOTEST_DIALOG };
	CListBox	m_list;
	int		m_CpuStat;
	int		m_TotalPageFile;
	int		m_TotalPhys;
	int		m_AvailPhys;
	int		m_pm;
	float		m_BandOut;
	float		m_BandIn;
		DWORD dwLastOut; 
			DWORD dwLastIn; 
	int	m_LastOut;
	int	m_LastIn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemInfoTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSystemInfoTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void GetDiskInfo();
private:
	void SendUDPBloadCast();
};

#endif 