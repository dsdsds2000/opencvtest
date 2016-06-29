
// opencvtestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "opencvtest.h"
#include "opencvtestDlg.h"
#include "afxdialogex.h"
#include "CvvImage.h"
#include "cv.h"
#include "highgui.h"
#include "DS_opencv.h"
#include "lsd.h"

using namespace std;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CopencvtestDlg �Ի���



CopencvtestDlg::CopencvtestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OPENCVTEST_DIALOG, pParent)
	, m_edit_H_low(_T(""))
	, m_edit_H_high(_T(""))
	, m_edit_S_low(_T(""))
	, m_edit_S_high(_T(""))
	, m_edit_V_low(_T(""))
	, m_edit_V_high(_T(""))
	, m_edit_V_high2(_T(""))
	, m_edit_S_low2(_T(""))
	, m_edit_S_high2(_T(""))
	, m_edit_H_low2(_T(""))
	, m_edit_H_high2(_T(""))
	, m_edit_filter_order(_T(""))
	, m_edit_filter_times(_T(""))
	, m_radio_input(0)
	, m_edit_caminput(_T(""))
	, m_edit_filter_order2(_T(""))
	, m_edit_filter_times2(_T(""))
	, m_edit_filter_order3(_T(""))
	, m_edit_filter_times3(_T(""))
	, m_edit_point_x(_T(""))
	, m_edit_point_y(_T(""))
	, m_edit_point_H(_T(""))
	, m_edit_point_S(_T(""))
	, m_edit_point_V(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CopencvtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_H_LOW, m_edit_H_low);
	DDX_Text(pDX, IDC_EDIT_H_HIGH, m_edit_H_high);
	DDX_Text(pDX, IDC_EDIT_S_LOW, m_edit_S_low);
	DDX_Text(pDX, IDC_EDIT_S_HIGH, m_edit_S_high);
	DDX_Text(pDX, IDC_EDIT_V_LOW, m_edit_V_low);
	DDX_Text(pDX, IDC_EDIT_V_HIGH, m_edit_V_high);
	DDX_Text(pDX, IDC_EDIT_V_LOW2, m_edit_V_low2);
	DDX_Text(pDX, IDC_EDIT_V_HIGH2, m_edit_V_high2);
	DDX_Text(pDX, IDC_EDIT_S_LOW2, m_edit_S_low2);
	DDX_Text(pDX, IDC_EDIT_S_HIGH2, m_edit_S_high2);
	DDX_Text(pDX, IDC_EDIT_H_LOW2, m_edit_H_low2);
	DDX_Text(pDX, IDC_EDIT_H_HIGH2, m_edit_H_high2);
	DDX_Text(pDX, IDC_EDIT_FILTER_ORDER, m_edit_filter_order);
	DDX_Text(pDX, IDC_EDIT_FILTER_TIMES, m_edit_filter_times);
	DDX_Radio(pDX, IDC_RADIO_FILE, m_radio_input);
	DDX_Text(pDX, IDC_EDIT_CAMINPUT, m_edit_caminput);
	DDX_Text(pDX, IDC_EDIT_FILTER_ORDER2, m_edit_filter_order2);
	DDX_Text(pDX, IDC_EDIT_FILTER_TIMES2, m_edit_filter_times2);
	DDX_Text(pDX, IDC_EDIT_FILTER_ORDER3, m_edit_filter_order3);
	DDX_Text(pDX, IDC_EDIT_FILTER_TIMES3, m_edit_filter_times3);
	DDX_Text(pDX, IDC_EDIT_POINT_X, m_edit_point_x);
	DDX_Text(pDX, IDC_EDIT_POINT_Y, m_edit_point_y);
	DDX_Text(pDX, IDC_EDIT_POINT_H, m_edit_point_H);
	DDX_Text(pDX, IDC_EDIT_POINT_S, m_edit_point_S);
	DDX_Text(pDX, IDC_EDIT_POINT_V, m_edit_point_V);
}

BEGIN_MESSAGE_MAP(CopencvtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CopencvtestDlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_PROC, &CopencvtestDlg::OnBnClickedButtonProc)
	ON_BN_CLICKED(IDC_BUTTON_FILTER, &CopencvtestDlg::OnBnClickedButtonFilter)
	ON_BN_CLICKED(IDC_BUTTON_PROC2, &CopencvtestDlg::OnBnClickedButtonProc2)
	ON_STN_DBLCLK(IDC_RENDER, &CopencvtestDlg::OnStnDblclickRender)
	//ON_STN_CLICKED(IDC_RESULT, &CopencvtestDlg::OnStnClickedResult)
	ON_STN_DBLCLK(IDC_RESULT2, &CopencvtestDlg::OnStnDblclickResult2)
	ON_STN_DBLCLK(IDC_RESULT, &CopencvtestDlg::OnStnDblclickResult)
	ON_STN_DBLCLK(IDC_RESULT3, &CopencvtestDlg::OnStnDblclickResult3)
	ON_STN_DBLCLK(IDC_RESULT4, &CopencvtestDlg::OnStnDblclickResult4)
	ON_BN_CLICKED(IDC_BUTTON_PROC3, &CopencvtestDlg::OnBnClickedButtonProc3)
	ON_BN_CLICKED(IDC_BUTTON_PROC4, &CopencvtestDlg::OnBnClickedButtonProc4)
	ON_STN_DBLCLK(IDC_RESULT5, &CopencvtestDlg::OnStnDblclickResult5)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE, &CopencvtestDlg::OnBnClickedButtonCapture)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, &CopencvtestDlg::OnBnClickedButtonPause)
	ON_WM_TIMER()
	ON_STN_DBLCLK(IDC_RESULT6, &CopencvtestDlg::OnStnDblclickResult6)
	ON_STN_DBLCLK(IDC_RESULT7, &CopencvtestDlg::OnStnDblclickResult7)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CopencvtestDlg ��Ϣ�������

BOOL CopencvtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_edit_H_low.Format("%d", 0);
	m_edit_H_high.Format("%d", 0);
	m_edit_S_low.Format("%d", 0);
	m_edit_S_high.Format("%d", 0);
	m_edit_V_low.Format("%d", 140);
	m_edit_V_high.Format("%d", 255);
	m_edit_S_low2.Format("%d", 0);
	m_edit_S_high2.Format("%d", 0);
	m_edit_V_low2.Format("%d", 0);
	m_edit_V_high2.Format("%d", 120);
	m_edit_H_low2.Format("%d", 7);
	m_edit_H_high2.Format("%d", 12);
	m_edit_filter_order.Format("%d", 3);
	m_edit_filter_times.Format("%d", 1);
	m_edit_filter_order2.Format("%d", 3);
	m_edit_filter_times2.Format("%d", 1);
	m_edit_filter_order3.Format("%d", 3);
	m_edit_filter_times3.Format("%d", 0);
	m_edit_caminput.Format("%d", 0);
	UpdateData(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CopencvtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CopencvtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		if (matGlobal1.cols > 0)
		{
			IplImage img = matGlobal1;
			CDC* pDC = GetDlgItem(IDC_RENDER)->GetDC();
			HDC hDC = pDC->GetSafeHdc();
			CvvImage cimg;
			cimg.CopyOf(&img);
			CRect rect;
			GetDlgItem(IDC_RENDER)->GetClientRect(&rect);
			cimg.DrawToHDC(hDC, &rect);
			ReleaseDC(pDC);
		}
		if (matGlobal2.cols > 0)
		{
			IplImage img = matGlobal2;
			CDC* pDC = GetDlgItem(IDC_RESULT)->GetDC();
			HDC hDC = pDC->GetSafeHdc();
			CvvImage cimg;
			cimg.CopyOf(&img);
			CRect rect;
			GetDlgItem(IDC_RESULT)->GetClientRect(&rect);
			cimg.DrawToHDC(hDC, &rect);
			ReleaseDC(pDC);
		}
		if (matGlobal3.cols > 0)
		{
			IplImage img = matGlobal3;
			CDC* pDC = GetDlgItem(IDC_RESULT3)->GetDC();
			HDC hDC = pDC->GetSafeHdc();
			CvvImage cimg;
			cimg.CopyOf(&img);
			CRect rect;
			GetDlgItem(IDC_RESULT3)->GetClientRect(&rect);
			cimg.DrawToHDC(hDC, &rect);
			ReleaseDC(pDC);
		}
		if (matGlobal4.cols > 0)
		{
			IplImage img = matGlobal4;
			CDC* pDC = GetDlgItem(IDC_RESULT4)->GetDC();
			HDC hDC = pDC->GetSafeHdc();
			CvvImage cimg;
			cimg.CopyOf(&img);
			CRect rect;
			GetDlgItem(IDC_RESULT4)->GetClientRect(&rect);
			cimg.DrawToHDC(hDC, &rect);
			ReleaseDC(pDC);
		}
		if (matGlobal5.cols > 0)
		{
			IplImage img = matGlobal5;
			CDC* pDC = GetDlgItem(IDC_RESULT2)->GetDC();
			HDC hDC = pDC->GetSafeHdc();
			CvvImage cimg;
			cimg.CopyOf(&img);
			CRect rect;
			GetDlgItem(IDC_RESULT2)->GetClientRect(&rect);
			cimg.DrawToHDC(hDC, &rect);
			ReleaseDC(pDC);
		}
		if (matGlobal6.cols > 0)
		{
			IplImage img = matGlobal6;
			CDC* pDC = GetDlgItem(IDC_RESULT5)->GetDC();
			HDC hDC = pDC->GetSafeHdc();
			CvvImage cimg;
			cimg.CopyOf(&img);
			CRect rect;
			GetDlgItem(IDC_RESULT5)->GetClientRect(&rect);
			cimg.DrawToHDC(hDC, &rect);
			ReleaseDC(pDC);
		}
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CopencvtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CopencvtestDlg::OnBnClickedButtonLoad()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if (0 == m_radio_input)
	{
		CString tFileName;
		CFileDialog tDlg(TRUE);
		if (tDlg.DoModal() == IDOK) {
			tFileName = tDlg.GetPathName();
			sFilePath = tFileName.GetBuffer(0);
		}

		matGlobal1 = cv::imread(sFilePath, 1);//ԭʼ����
	}
	else if (1 == m_radio_input)
	{
		VideoCap.open(atoi(m_edit_caminput));
		if (!VideoCap.isOpened())
		{
			MessageBox("camera open failed !", "error", MB_OK);
			return;
		}
		VideoCap >> matGlobal1;
		VideoCap.release();
	}
	if (!matGlobal1.data)
	{
		MessageBox("no image loaded !", "error", MB_OK);
		return;
	}
	cv::imwrite("..\\matGlobal1.jpg", matGlobal1);
	IplImage img = matGlobal1;
	CDC* pDC = GetDlgItem(IDC_RENDER)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(&img);
	CRect rect;
	GetDlgItem(IDC_RENDER)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);
	for (int i = 0; i < 11; i++)
	{
		if (p_img[i])
			cvReleaseImage(&p_img[i]);
		p_img[i] = cvCloneImage(&img);//���

	}
	cvCvtColor(p_img[0], p_img[10], CV_BGR2HSV);
}


void CopencvtestDlg::OnBnClickedButtonProc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	for (int i = 0; i < atoi(m_edit_filter_times3); i++)
	{
		cvSmooth(p_img[0], p_img[1], CV_MEDIAN, atoi(m_edit_filter_order3));
		cvCvtColor(p_img[1], p_img[2], CV_BGR2HSV);
		cvCvtColor(p_img[2], p_img[0], CV_HSV2BGR);
		//Sleep(100);
	}

	cvCvtColor(p_img[0], p_img[2], CV_BGR2HSV);
	ChangeHSV(p_img[2], 1);
	cvCvtColor(p_img[2], p_img[3], CV_HSV2BGR);
	matGlobal2 = cv::Mat(p_img[3], 1);//����ȫ�ֱ������󼶴���
	cv::imwrite("..\\matGlobal2.jpg", matGlobal2);

	CDC* pDC = GetDlgItem(IDC_RESULT)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(p_img[3]);
	CRect rect;
	GetDlgItem(IDC_RESULT)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);


	cvCvtColor(p_img[3], p_img[4], CV_BGR2HSV);
	ChangeHSV(p_img[4], 2);
	cvCvtColor(p_img[4], p_img[5], CV_HSV2BGR);
	matGlobal3 = cv::Mat(p_img[5], 1);//����ȫ�ֱ������󼶴���
	cv::imwrite("..\\matGlobal3.jpg", matGlobal3);


	pDC = GetDlgItem(IDC_RESULT3)->GetDC();
	hDC = pDC->GetSafeHdc();
	cimg.CopyOf(p_img[5]);
	GetDlgItem(IDC_RESULT3)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);


	cvCvtColor(p_img[3], p_img[6], CV_BGR2HSV);
	ChangeHSV(p_img[6], 3);
	cvCvtColor(p_img[6], p_img[7], CV_HSV2BGR);
	matGlobal4 = cv::Mat(p_img[7], 1);//����ȫ�ֱ������󼶴���
	cv::imwrite("..\\matGlobal4.jpg", matGlobal4);

	pDC = GetDlgItem(IDC_RESULT4)->GetDC();
	hDC = pDC->GetSafeHdc();
	cimg.CopyOf(p_img[7]);
	GetDlgItem(IDC_RESULT4)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);







	//cvCvtColor(p_img[7], p_img[6], CV_BGR2HSV);
	//ChangeHSV(p_img[6], 5);
	//cvCvtColor(p_img[6], p_img[7], CV_HSV2BGR);

	//IplImage img = matGlobal1;//ǳ����
	//if (p_imgs[0])//�ֶ��ͷ���һ�ε�
	//	cvReleaseImage(&p_imgs[0]);
	//p_imgs[0] = cvCreateImage(cvGetSize(&img), img.depth, 1);//��ͨ��
	//cvCvtColor(p_img[7], p_imgs[0], CV_BGR2GRAY);
	//matGlobal4 = cv::Mat(p_imgs[0]);//����ȫ�ֱ������󼶴���
	//cv::imwrite("..\\matGlobal4.jpg", matGlobal4);



	//for (int i = 0; i < 2; i++)
	//{
	//	cvSmooth(p_img[5], p_img[1], CV_MEDIAN, 5);
	//	cvCvtColor(p_img[1], p_img[4], CV_BGR2HSV);
	//	cvCvtColor(p_img[4], p_img[5], CV_HSV2BGR);		
	//}
	//matGlobal5 = cv::Mat(p_img[1]);//����ȫ�ֱ������󼶴���
	//cv::imwrite("..\\matGlobal5.jpg", matGlobal5);

	/*CDC* pDC = GetDlgItem(IDC_RESULT2)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(p_img[1]);
	CRect rect;
	GetDlgItem(IDC_RESULT2)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);*/

}


void CopencvtestDlg::ChangeHSV(IplImage* img, int method)
{
	UpdateData();
	uchar H_low = atoi(m_edit_H_low);
	uchar H_high = atoi(m_edit_H_high);
	uchar S_low = atoi(m_edit_S_low);
	uchar S_high = atoi(m_edit_S_high);
	uchar V_low = atoi(m_edit_V_low);
	uchar V_high = atoi(m_edit_V_high);
	uchar S_low2 = atoi(m_edit_S_low2);
	uchar S_high2 = atoi(m_edit_S_high2);
	uchar V_low2 = atoi(m_edit_V_low2);
	uchar V_high2 = atoi(m_edit_V_high2);
	uchar H_low2 = atoi(m_edit_H_low2);
	uchar H_high2 = atoi(m_edit_H_high2);

	if (1 == method)
	{
		for (int y = 0; y < img->height; y++)
		{
			uchar* ptr = (uchar*)(img->imageData + y * img->widthStep);
			for (int x = 0; x < img->width; x++)
			{
				//ptr[3 * x] = 0;//H
				//ptr[3 * x + 1] = 255;//S
				//ptr[3 * x + 2] = 255;//V

				if (ptr[3 * x] >= H_low && ptr[3 * x] <= H_high)
				{
					//ptr[3 * x + 1] = 255;//S
					//ptr[3 * x + 2] = 255;//V	
				}
				/*else if (ptr[3 * x + 1] >= S_low && ptr[3 * x + 1] <= S_high)
				{

				}
				else if (ptr[3 * x + 2] >= V_low && ptr[3 * x + 2] <= V_high)
				{

				}*/
				else
				{
					ptr[3 * x + 1] = 0;//S
					ptr[3 * x + 2] = 0;//V
				}
			}
		}
	}
	if (2 == method)
	{
		for (int y = 0; y < img->height; y++)
		{
			uchar* ptr = (uchar*)(img->imageData + y * img->widthStep);
			for (int x = 0; x < img->width; x++)
			{
				//ptr[3 * x] = 0;//H
				//ptr[3 * x + 1] = 255;//S
				//ptr[3 * x + 2] = 255;//V

				//if (ptr[3 * x] >= H_low && ptr[3 * x] <= H_high)
				//{
					//ptr[3 * x + 1] = 255;//S
					//ptr[3 * x + 2] = 255;//V
				if (ptr[3 * x + 1] >= S_low && ptr[3 * x + 1] <= S_high)
				{
					if (ptr[3 * x + 2] >= V_low && ptr[3 * x + 2] <= V_high)
					{

					}
					else
					{
						ptr[3 * x + 1] = 0;//S
						ptr[3 * x + 2] = 0;//V
					}
				}
				else
				{
					ptr[3 * x + 1] = 0;//S
					ptr[3 * x + 2] = 0;//V
				}

				//}
				//else
				//{
					//ptr[3 * x + 1] = 0;//S
					//ptr[3 * x + 2] = 0;//V
				//}
			}
		}
	}
	if (3 == method)
	{
		for (int y = 0; y < img->height; y++)
		{
			uchar* ptr = (uchar*)(img->imageData + y * img->widthStep);
			for (int x = 0; x < img->width; x++)
			{
				//ptr[3 * x] = 0;//H
				//ptr[3 * x + 1] = 255;//S
				//ptr[3 * x + 2] = 255;//V

				//if (ptr[3 * x] >= H_low && ptr[3 * x] <= H_high)
				//{
				//ptr[3 * x + 1] = 255;//S
				//ptr[3 * x + 2] = 255;//V
				if (ptr[3 * x + 1] >= S_low2 && ptr[3 * x + 1] <= S_high2)
				{
					if (ptr[3 * x + 2] >= V_low2 && ptr[3 * x + 2] <= V_high2)
					{

					}
					else
					{
						ptr[3 * x + 1] = 0;//S
						ptr[3 * x + 2] = 0;//V
					}
				}
				else
				{
					ptr[3 * x + 1] = 0;//S
					ptr[3 * x + 2] = 0;//V
				}

				//}
				//else
				//{
				//ptr[3 * x + 1] = 0;//S
				//ptr[3 * x + 2] = 0;//V
				//}
			}
		}
	}
	if (4 == method)
	{
		for (int y = 0; y < img->height; y++)
		{
			uchar* ptr = (uchar*)(img->imageData + y * img->widthStep);
			for (int x = 0; x < img->width; x++)
			{
				//ptr[3 * x] = 0;//H
				//ptr[3 * x + 1] = 255;//S
				//ptr[3 * x + 2] = 255;//V

				if (ptr[3 * x] >= H_low2 && ptr[3 * x] <= H_high2)
				{
					//ptr[3 * x + 1] = 255;//S
					//ptr[3 * x + 2] = 255;//V	
				}
				/*else if (ptr[3 * x + 1] >= S_low && ptr[3 * x + 1] <= S_high)
				{

				}
				else if (ptr[3 * x + 2] >= V_low && ptr[3 * x + 2] <= V_high)
				{

				}*/
				else
				{
					ptr[3 * x + 1] = 0;//S
					ptr[3 * x + 2] = 0;//V
				}
			}
		}
	}
	if (5 == method)
	{
		for (int y = 0; y < img->height; y++)
		{
			uchar* ptr = (uchar*)(img->imageData + y * img->widthStep);
			for (int x = 0; x < img->width; x++)
			{
				//ptr[3 * x] = 0;//H
				//ptr[3 * x + 1] = 255;//S
				//ptr[3 * x + 2] = 255;//V
				if (ptr[3 * x + 2] > 0)
				{
					ptr[3 * x] = 0;//H
					ptr[3 * x + 1] = 0;//S
					ptr[3 * x + 2] = 155;//V
				}
			}
		}
	}
}


void CopencvtestDlg::OnBnClickedButtonFilter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//IplImage *p_img4 = cvCreateImage(cvGetSize(&img), img.depth, 1);//��ͨ��
	//cvCvtColor(p_img3, p_img4, CV_BGR2GRAY);
	UpdateData();
	for (int i = 0; i < atoi(m_edit_filter_times); i++)
	{
		cvSmooth(p_img[5], p_img[1], CV_MEDIAN, atoi(m_edit_filter_order));
		cvCvtColor(p_img[1], p_img[4], CV_BGR2HSV);
		cvCvtColor(p_img[4], p_img[5], CV_HSV2BGR);
		//Sleep(100);
	}
	matGlobal5 = cv::Mat(p_img[5], 1);//����ȫ�ֱ������󼶴���
	cv::imwrite("..\\matGlobal5.jpg", matGlobal5);

	CDC* pDC = GetDlgItem(IDC_RESULT2)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(p_img[5]);
	CRect rect;
	GetDlgItem(IDC_RESULT2)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);

	for (int i = 0; i < atoi(m_edit_filter_times2); i++)
	{
		cvSmooth(p_img[7], p_img[1], CV_MEDIAN, atoi(m_edit_filter_order2));
		cvCvtColor(p_img[1], p_img[6], CV_BGR2HSV);
		cvCvtColor(p_img[6], p_img[7], CV_HSV2BGR);
	}
	//cvCvtColor(p_img[7], p_img[6], CV_BGR2HSV);
	//ChangeHSV(p_img[6], 4);
	//cvCvtColor(p_img[6], p_img[7], CV_HSV2BGR);
	//for (int i = 0; i < atoi(m_edit_filter_times2); i++)
	//{
	//	cvSmooth(p_img[7], p_img[1], CV_MEDIAN, atoi(m_edit_filter_order2));
	//	cvCvtColor(p_img[1], p_img[6], CV_BGR2HSV);
	//	cvCvtColor(p_img[6], p_img[7], CV_HSV2BGR);
	//}
	matGlobal6 = cv::Mat(p_img[7], 1);//����ȫ�ֱ������󼶴���
	cv::imwrite("..\\matGlobal6.jpg", matGlobal6);

	pDC = GetDlgItem(IDC_RESULT5)->GetDC();
	hDC = pDC->GetSafeHdc();
	//CvvImage cimg;
	cimg.CopyOf(p_img[7]);
	//CRect rect;
	GetDlgItem(IDC_RESULT5)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);
}


void CopencvtestDlg::OnBnClickedButtonProc2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	cvCvtColor(p_img[5], p_img[4], CV_BGR2HSV);
	ChangeHSV(p_img[4], 5);
	cvCvtColor(p_img[4], p_img[5], CV_HSV2BGR);
	matGlobal7 = cv::Mat(p_img[5], 1);//����ȫ�ֱ������󼶴���
	cv::imwrite("..\\matGlobal7.jpg", matGlobal7);

	CDC* pDC = GetDlgItem(IDC_RESULT6)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(p_img[5]);
	CRect rect;
	GetDlgItem(IDC_RESULT4)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);

	cvCvtColor(p_img[7], p_img[6], CV_BGR2HSV);
	ChangeHSV(p_img[6], 5);
	cvCvtColor(p_img[6], p_img[7], CV_HSV2BGR);
	matGlobal8 = cv::Mat(p_img[7], 1);//����ȫ�ֱ������󼶴���
	cv::imwrite("..\\matGlobal8.jpg", matGlobal8);

	pDC = GetDlgItem(IDC_RESULT7)->GetDC();
	hDC = pDC->GetSafeHdc();
	//CvvImage cimg;
	cimg.CopyOf(p_img[7]);
	//CRect rect;
	GetDlgItem(IDC_RESULT7)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);
}


void CopencvtestDlg::OnStnDblclickRender()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal1.jpg", NULL, NULL, SW_SHOWNORMAL);
}


//void CopencvtestDlg::OnStnClickedResult()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}


void CopencvtestDlg::OnStnDblclickResult2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal5.jpg", NULL, NULL, SW_SHOWNORMAL);
}


void CopencvtestDlg::OnStnDblclickResult()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal2.jpg", NULL, NULL, SW_SHOWNORMAL);
}


void CopencvtestDlg::OnStnDblclickResult3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal3.jpg", NULL, NULL, SW_SHOWNORMAL);
}


void CopencvtestDlg::OnStnDblclickResult4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal4.jpg", NULL, NULL, SW_SHOWNORMAL);
}


void CopencvtestDlg::OnBnClickedButtonProc3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//cvCvtColor(p_img[7], p_img[6], CV_BGR2HSV);
	//ChangeHSV(p_img[6], 4);
	//cvCvtColor(p_img[6], p_img[7], CV_HSV2BGR);
	//matGlobal4 = cv::Mat(p_img[7]);//����ȫ�ֱ������󼶴���
	//cv::imwrite("..\\matGlobal4.jpg", matGlobal4);

	Point pt1 = Point(0, 0);
	Point pt2 = Point(110, 110);

	if (p_imgs[0])//�ֶ��ͷ���һ�ε�
		cvReleaseImage(&p_imgs[0]);
	p_imgs[0] = cvCreateImage(cvGetSize(p_img[1]), p_img[1]->depth, 1);//��ͨ��
	cvCvtColor(p_img[5], p_imgs[0], CV_BGR2GRAY);
	Mat tmp(p_imgs[0], 1);
	matGlobal7 = cv::Mat(p_img[5], 1);//��ʼ��
	tmp.convertTo(matGlobal7, CV_64FC1);
	//line(matGlobal7, pt1, pt2, Scalar(0, 255, 0), 1);
	int cols = matGlobal7.cols;
	int rows = matGlobal7.rows;
	if (linedata[0])
		free(linedata[0]);
	linedata[0] = lsd(&n_line_out[0], matGlobal7.ptr<double>(0), cols, rows);
	//matGlobal7.convertTo(matGlobal7, CV_8UC3);
	matGlobal7 = cv::Mat(p_img[5], 1);
	if (linedata[0])
	{
		for (int i = 0; i < n_line_out[0]; i++)
		{
			pt1 = Point(*(linedata[0] + i * 7), *(linedata[0] + i * 7 + 1));
			pt2 = Point(*(linedata[0] + i * 7 + 2), *(linedata[0] + i * 7 + 3));
			line_width[0] = *(linedata[0] + i * 7 + 4);
			line(matGlobal7, pt1, pt2, Scalar(0, 255, 0), 1);// line_width);
		}
	}
	//free(linedata[0]);
	//linedata[0] = 0;

	*p_img[8] = IplImage(matGlobal7);
	cv::imwrite("..\\matGlobal7.jpg", matGlobal7);
	CDC* pDC = GetDlgItem(IDC_RESULT6)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(p_img[8]);
	CRect rect;
	GetDlgItem(IDC_RESULT6)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);

	if (p_imgs[1])//�ֶ��ͷ���һ�ε�
		cvReleaseImage(&p_imgs[1]);
	p_imgs[1] = cvCreateImage(cvGetSize(p_img[1]), p_img[1]->depth, 1);//��ͨ��
	cvCvtColor(p_img[7], p_imgs[1], CV_BGR2GRAY);
	tmp = Mat(p_imgs[1], 1);
	matGlobal8 = cv::Mat(p_img[7], 1);//��ʼ��
	tmp.convertTo(matGlobal8, CV_64FC1);
	cols = matGlobal8.cols;
	rows = matGlobal8.rows;
	//line_width = 0;
	//n_line_out = 0;
	if (linedata[1])
		free(linedata[1]);
	linedata[1] = lsd(&n_line_out[1], matGlobal8.ptr<double>(0), cols, rows);
	matGlobal8 = cv::Mat(p_img[7], 1);
	if (linedata[1])
	{
		for (int i = 0; i < n_line_out[1]; i++)
		{
			pt1 = Point(*(linedata[1] + i * 7), *(linedata[1] + i * 7 + 1));
			pt2 = Point(*(linedata[1] + i * 7 + 2), *(linedata[1] + i * 7 + 3));
			line_width[1] = *(linedata[1] + i * 7 + 4);
			line(matGlobal8, pt1, pt2, Scalar(0, 0, 255), 1);// line_width);
		}
	}
	//free(linedata[1]);
	//linedata[1] = 0;

	//matGlobal8.convertTo(matGlobal8, CV_8UC3);
	*p_img[9] = IplImage(matGlobal8);
	cv::imwrite("..\\matGlobal8.jpg", matGlobal8);
	pDC = GetDlgItem(IDC_RESULT7)->GetDC();
	hDC = pDC->GetSafeHdc();
	//CvvImage cimg;
	cimg.CopyOf(p_img[9]);
	//CRect rect;
	GetDlgItem(IDC_RESULT7)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);
}


void CopencvtestDlg::OnBnClickedButtonProc4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Point pt1 = Point(0, 0);
	Point pt2 = Point(110, 110);

	for (int i = 0; i < n_line_out[0]; i++)
	{
		pt1 = Point(*(linedata[0] + i * 7), *(linedata[0] + i * 7 + 1));
		pt2 = Point(*(linedata[0] + i * 7 + 2), *(linedata[0] + i * 7 + 3));
		line_width[0] = *(linedata[0] + i * 7 + 4);
		line(matGlobal2, pt1, pt2, Scalar(0, 255, 0), 1);// line_width);
	}
	for (int i = 0; i < n_line_out[1]; i++)
	{
		pt1 = Point(*(linedata[1] + i * 7), *(linedata[1] + i * 7 + 1));
		pt2 = Point(*(linedata[1] + i * 7 + 2), *(linedata[1] + i * 7 + 3));
		line_width[1] = *(linedata[1] + i * 7 + 4);
		line(matGlobal2, pt1, pt2, Scalar(0, 0, 255), 1);// line_width);
	}

	//free(linedata[0]);
	//linedata[0] = 0;

	cv::imwrite("..\\matGlobal2.jpg", matGlobal2);
	IplImage img = matGlobal2;
	CDC* pDC = GetDlgItem(IDC_RESULT)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(&img);
	CRect rect;
	GetDlgItem(IDC_RESULT)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);
}


void CopencvtestDlg::OnStnDblclickResult5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal6.jpg", NULL, NULL, SW_SHOWNORMAL);
}


void CopencvtestDlg::OnBnClickedButtonCapture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!VideoCap.isOpened())
	{
		VideoCap.open(atoi(m_edit_caminput));
	}
	if (!VideoCap.isOpened())
	{
		MessageBox("camera open failed !", "error", MB_OK);
		return;
	}
	SetTimer(0, 20, NULL);
}


void CopencvtestDlg::OnBnClickedButtonPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(0);
	VideoCap >> matGlobal1;
	VideoCap.release();
	cv::imwrite("..\\matGlobal1.jpg", matGlobal1);
	IplImage img = matGlobal1;
	CDC* pDC = GetDlgItem(IDC_RENDER)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage cimg;
	cimg.CopyOf(&img);
	CRect rect;
	GetDlgItem(IDC_RENDER)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);
	for (int i = 0; i < 9; i++)
	{
		if (p_img[i])
			cvReleaseImage(&p_img[i]);
		p_img[i] = cvCloneImage(&img);//���
	}
}


void CopencvtestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case 0:
	{
		VideoCap >> matGlobal1;
		IplImage img = matGlobal1;
		CDC* pDC = GetDlgItem(IDC_RENDER)->GetDC();
		HDC hDC = pDC->GetSafeHdc();
		CvvImage cimg;
		cimg.CopyOf(&img);
		CRect rect;
		GetDlgItem(IDC_RENDER)->GetClientRect(&rect);
		cimg.DrawToHDC(hDC, &rect);
		ReleaseDC(pDC);

		break;
	}
	default:
	{
		MessageBox("enter timer default");
		break;
	}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CopencvtestDlg::OnStnDblclickResult6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal7.jpg", NULL, NULL, SW_SHOWNORMAL);
}


void CopencvtestDlg::OnStnDblclickResult7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(NULL, "open", "..\\matGlobal8.jpg", NULL, NULL, SW_SHOWNORMAL);
}


void CopencvtestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rectPIC;
	GetDlgItem(IDC_RENDER)->GetWindowRect(rectPIC);
	int PicWidth = rectPIC.Width();
	int PicHeight = rectPIC.Height();

	m_edit_point_x.Format("%.0f", (point.x - rectPIC.left) / (double)PicWidth * matGlobal1.cols);
	m_edit_point_y.Format("%.0f", (point.y - rectPIC.top) / (double)PicHeight * matGlobal1.rows);

	IplImage* img = p_img[10];
	if (img && atoi(m_edit_point_x) >= 0 && atoi(m_edit_point_x) < img->width && atoi(m_edit_point_y) >= 0 && atoi(m_edit_point_y) < img->height)
	{
		uchar* ptr = (uchar*)(img->imageData + atoi(m_edit_point_y) * img->widthStep);
		m_edit_point_H.Format("%u", ptr[3 * atoi(m_edit_point_x)]);//H
		m_edit_point_S.Format("%u", ptr[3 * atoi(m_edit_point_x) + 1]);//S
		m_edit_point_V.Format("%u", ptr[3 * atoi(m_edit_point_x) + 2]);//V
	}

	UpdateData(0);

	CDialogEx::OnMouseMove(nFlags, point);
}


BOOL CopencvtestDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_MOUSEMOVE)
	{
		OnMouseMove(NULL, pMsg->pt);
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
