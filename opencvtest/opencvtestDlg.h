
// opencvtestDlg.h : ͷ�ļ�
//

#pragma once

#include "cv.h"
#include "afxwin.h"
#include "highgui.hpp"
//#include <string>


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
	std::string sFilePath;//ԭʼ·��
	cv::Mat matGlobal1;//ԭʼ����
	cv::Mat matGlobal2;
	cv::Mat matGlobal3;
	cv::Mat matGlobal4;
	cv::Mat matGlobal5;
	cv::Mat matGlobal6;
	cv::Mat matGlobal7;
	cv::Mat matGlobal8;
	IplImage *p_img[10];
	IplImage *p_imgs[2];//��ͨ��
	cv::VideoCapture VideoCap;
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
	CString m_edit_H_low2;
	CString m_edit_H_high2;
	afx_msg void OnBnClickedButtonProc2();
	afx_msg void OnStnDblclickRender();
	//	afx_msg void OnStnClickedResult();
	afx_msg void OnStnDblclickResult2();
	afx_msg void OnStnDblclickResult();
	afx_msg void OnStnDblclickResult3();
	afx_msg void OnStnDblclickResult4();
	afx_msg void OnBnClickedButtonProc3();
	CString m_edit_filter_order;
	CString m_edit_filter_times;
	afx_msg void OnBnClickedButtonProc4();
	afx_msg void OnStnDblclickResult5();
	int m_radio_input;
	CString m_edit_caminput;
	afx_msg void OnBnClickedButtonCapture();
	afx_msg void OnBnClickedButtonPause();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_edit_filter_order2;
	CString m_edit_filter_times2;
	afx_msg void OnStnDblclickResult6();
	afx_msg void OnStnDblclickResult7();
};
