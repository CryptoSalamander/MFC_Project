#pragma once


// COutputView ���Դϴ�.

class COutputView : public CView
{
	DECLARE_DYNCREATE(COutputView)

protected:
	COutputView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~COutputView();
	CButton* pButton;
	CButton* fpButton;
	BOOL cRun;
	int x, y;
	BOOL left;
	BOOL first;
	BOOL treeon;
	CTime time;
	CString TimeData;
	int fx, fy;
	int ax, ay;

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnInitialUpdate();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};


