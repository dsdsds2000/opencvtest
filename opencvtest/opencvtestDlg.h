
// opencvtestDlg.h : ͷ�ļ�
//

#pragma once

#include "cv.h"
#include "afxwin.h"

// CopencvtestDlg �Ի���
class CopencvtestDlg : public CDialogEx
{
	// ����
public:
	CopencvtestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCVTEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	cv::Mat matGlobal1;//ԭʼ����
	cv::Mat matGlobal2;
	cv::Mat matGlobal3;
	cv::Mat matGlobal4;
	IplImage *p_img[8];	
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonProc();
	void ChangeHSV(IplImage* img, int method);
	CString m_edit_H_low;
	CString m_edit_H_high;
	CString m_edit_S_low;
	CString m_edit_S_high;
	CString m_edit_V_low;
	CString m_edit_V_high;
	afx_msg void OnBnClickedButtonFilter();
	CString m_edit_V_low2;
	CString m_edit_V_high2;
	CString m_edit_S_low2;
	CString m_edit_S_high2;
};
