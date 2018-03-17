#pragma once


// COutputView 뷰입니다.

class COutputView : public CView
{
	DECLARE_DYNCREATE(COutputView)

protected:
	COutputView();           // 동적 만들기에 사용되는 protected 생성자입니다.
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
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
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


