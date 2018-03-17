// CodeView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCWarrior.h"
#include "CodeView.h"
#include "OutputView.h"
#include "MFCWarriorDoc.h"


// CCodeView

IMPLEMENT_DYNCREATE(CCodeView, CView)

CCodeView::CCodeView()
{

}

CCodeView::~CCodeView()
{
}

BEGIN_MESSAGE_MAP(CCodeView, CView)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CCodeView �׸����Դϴ�.

void CCodeView::OnDraw(CDC* pDC)
{
	CMFCWarriorDoc * pDoc = (CMFCWarriorDoc *)GetDocument();
	pDoc->code_view = this;
	//CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	pDC->SetTextColor(RGB(255, 255, 255));
	pDC->SetBkMode(TRANSPARENT);
	CFont font;
	font.CreatePointFont(150, _T("����"));
	pDC->SelectObject(font);

	if (pDoc->stage == 1)
	{
		CString Stage_1_output;
		Stage_1_output = "void CChildView::OnPaint()\n{\n        CPaintDC dc(this);\n        (                 );\n}";
		pDC->DrawText(Stage_1_output, rect, DT_LEFT);
	}
	else if (pDoc->stage == 2)
	{
		CString Stage_2_output;
		Stage_2_output = "void CChildView::OnPaint()\n{\n        CPaintDC dc(this);\n        CBitmap bitmap;\n        BITMAP bitmapinfo;\n        CDC dcmem\n        bitmap.LoadBitmap(IDB_SWORD);\n        bitmap.GetBitmap(&bitmapinfo);\n        dcmem.CreateCompatibleDC(&&dc);\n        dcmem.SelectObject(&&bitmap);\n        (                                                                            )\n}";
		pDC->DrawText(Stage_2_output, rect, DT_LEFT);
	}
	else if (pDoc->stage == 3)
	{
		CString Stage_3_output;
		Stage_3_output = "void CChildView::OnPaint()\n{\n        CPaintDC dc(this);\n        (                    )\n}";
		pDC->DrawText(Stage_3_output, rect, DT_LEFT);
	}
	else if (pDoc->stage == 4)
	{
		CString Stage_4_output;
		Stage_4_output = "void CChildView::OnPaint()\n{\n        CPaintDC dc(this);\n        dc.MoveTo(400,100);\n        (                 )\n}\n";
		pDC->DrawText(Stage_4_output, rect, DT_LEFT);
	}
	else if (pDoc->stage == 5)
	{
		CString Stage_5_output;
		Stage_5_output = "void CChildView::OnPaint()\n{\n        CTime time; \n        CString TimeData;\n        (                                  )\n\n        TimeData.Format(_T(\"���� �ð��� %d�� %d�� %d���Դϴ�.\"),time.GetHour(), time.GetMinute(), time.GetSecond());\n        AfxMessageBox(TimeData);\n}";

		pDC->DrawText(Stage_5_output, rect, DT_LEFT);
	}
	else if (pDoc->stage == 6)
	{
		CString Stage_6_output;
		Stage_6_output = "void CChildView::OnPaint()\n{\n        CArray<int> array;\n        array.SetSize(5);\n        (             )\n}\n";
			pDC->DrawText(Stage_6_output, rect, DT_LEFT);
	}
	else if (pDoc->stage == 7)
	{
		CString Stage_7_output;
		Stage_7_output = "void CChildView::OnPaint()\n{\n        CPaintDC dc(this);\n        CRgn original, new, circle;\n        new.CreateCircle(0,0,1,1);\n        original.CreateCircle(x, y, x + a, y + a);\n        circle.CreateCircle(x, y, x + a, y + a);\n        (                 )\n}\n";

		pDC->DrawText(Stage_7_output, rect, DT_LEFT);
	}
	else if (pDoc->stage == 8)
	{
		CString Stage_8_output;
		Stage_8_output = "void CChildView::OnPaint()\n{\n        CPaintDC dc(this);\n        (                     )\n        dc.SelectObject(&&brush);\n        dc.Ellipse(80, 100, 180, 200);\n}\n";
		pDC->DrawText(Stage_8_output, rect, DT_LEFT);
	}
}


// CCodeView �����Դϴ�.

#ifdef _DEBUG
void CCodeView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CCodeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCodeView �޽��� ó�����Դϴ�.


BOOL CCodeView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBrush backBrush(RGB(68, 68, 68));
	CBrush * pOldBrush = pDC->SelectObject(&backBrush);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);
	return TRUE;
}
