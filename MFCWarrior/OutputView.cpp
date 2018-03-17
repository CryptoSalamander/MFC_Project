// OutputView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCWarrior.h"
#include "OutputView.h"
#include "MFCWarriorDoc.h"
#include "InputView.h"
#include "CodeView.h"
// COutputView

IMPLEMENT_DYNCREATE(COutputView, CView)

COutputView::COutputView()
{
	cRun = FALSE;
	x = 80, y = 100;
	left = FALSE;
	first = TRUE;
	treeon = TRUE;
	fx = 200, fy = 100;
	ax = 980, ay = 150;
}

COutputView::~COutputView()
{
}

BEGIN_MESSAGE_MAP(COutputView, CView)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// COutputView 그리기입니다.

void COutputView::OnDraw(CDC* pDC)
{
	CMFCWarriorDoc * pDoc = (CMFCWarriorDoc *)GetDocument();

	CClientDC dc(this);
	CBitmap w1, w2, w3, s1, s2, s3, sw1, sw2, sw3, tr, ar;
	BITMAP w1info, w2info, w3info,s1info,s2info,s3info,sw1info,sw2info,sw3info,trinfo,arinfo;
	CDC warrior1, warrior2, warrior3, shield1, shield2, shield3,sword1, sword2, sword3,tree,arrow;
	CBitmap n1, b1, m1, m2, f1, monster_map;
	BITMAP n1info, b1info, magic1info, magic2info, fireinfo, monsterinfo;
	CDC NPC1, balloon, magic1, magic2, fire1, monster;
	BOOL fireball = TRUE;
	//1단계
	if (pDoc->stage == 0)
	{
		if (cRun == TRUE)
		{
			AfxMessageBox(_T("실행됬어요!"));
	
		}
	}
	else if (pDoc->stage == 1)
	{
		fpButton->ShowWindow(SW_HIDE);
		if (x != 1000) {
			if (first == TRUE) {
				w1.LoadBitmap(IDB_WARRIOR);
				w1.GetBitmap(&w1info);
				warrior1.CreateCompatibleDC(&dc);
				warrior1.SelectObject(&w1);
				pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));
			}
			first = FALSE;
			if (cRun == TRUE) {
				if (left == TRUE) {
					w2.LoadBitmap(IDB_WARRIOR_LEFT);
					w2.GetBitmap(&w2info);
					warrior2.CreateCompatibleDC(&dc);
					warrior2.SelectObject(&w2);
					pDC->TransparentBlt(x, y, w2info.bmWidth / 4, w2info.bmHeight / 4, &warrior2, 0, 0, w2info.bmWidth, w2info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = FALSE;
				}
				else {
					w3.LoadBitmap(IDB_WARRIOR_RIGHT);
					w3.GetBitmap(&w3info);
					warrior3.CreateCompatibleDC(&dc);
					warrior3.SelectObject(&w3);
					pDC->TransparentBlt(x, y, w3info.bmWidth / 4, w3info.bmHeight / 4, &warrior3, 0, 0, w3info.bmWidth, w3info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = TRUE;
				}
				Sleep(100);
				Invalidate();
			}
		}
		if (x == 1000)
		{
			pDoc->stage++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			Invalidate();
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();
		}
	}
	else if (pDoc->stage == 2) {
		if (x != 1000) {
			if (x == 450)
				treeon = FALSE;
			if (treeon == TRUE) {
				tr.LoadBitmap(IDB_TREE);
				tr.GetBitmap(&trinfo);
				tree.CreateCompatibleDC(&dc);
				tree.SelectObject(&tr);
				pDC->TransparentBlt(500, y, trinfo.bmWidth/2, trinfo.bmHeight/2, &tree, 0, 0, trinfo.bmWidth, trinfo.bmHeight, RGB(255, 255, 255));
			}
			if (first == TRUE) {
				w1.LoadBitmap(IDB_WARRIOR);
				w1.GetBitmap(&w1info);
				warrior1.CreateCompatibleDC(&dc);
				warrior1.SelectObject(&w1);
				pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));
			}
			first = FALSE;
			if (cRun == TRUE) {
				//pDC->TransparentBlt(x, y, sw1info.bmWidth / 4, sw1info.bmHeight / 4, &sword1, 0, 0, sw1info.bmWidth, sw1info.bmHeight, RGB(255, 255, 255));
				if (left == TRUE) {
					sw2.LoadBitmap(IDB_SWORD_LEFT);
					sw2.GetBitmap(&sw2info);
					sword2.CreateCompatibleDC(&dc);
					sword2.SelectObject(&sw2);
					pDC->TransparentBlt(x, y, sw2info.bmWidth / 4, sw2info.bmHeight / 4, &sword2, 0, 0, sw2info.bmWidth, sw2info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = FALSE;
				}
				else {
					sw3.LoadBitmap(IDB_SWORD_RIGHT);
					sw3.GetBitmap(&sw3info);
					sword3.CreateCompatibleDC(&dc);
					sword3.SelectObject(&sw3);
					pDC->TransparentBlt(x, y, sw3info.bmWidth / 4, sw3info.bmHeight / 4, &sword3, 0, 0, sw3info.bmWidth, sw3info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = TRUE;
				}
				Sleep(100);
				Invalidate();
			}
		}
		if (x == 1000)
		{
			pDoc->stage++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			Invalidate();	
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();
		}
	}
	else if (pDoc->stage == 3)
	{
		if (x != 1000) {
			if (first == TRUE) {
				sw1.LoadBitmap(IDB_SWORD);
				sw1.GetBitmap(&sw1info);
				sword1.CreateCompatibleDC(&dc);
				sword1.SelectObject(&sw1);
				pDC->TransparentBlt(x, y, sw1info.bmWidth / 4, sw1info.bmHeight / 4, &sword1, 0, 0, sw1info.bmWidth, sw1info.bmHeight, RGB(255, 255, 255));
			}
			first = FALSE;
			if (cRun == TRUE) {
				if (left == TRUE) {
					s2.LoadBitmap(IDB_SHIELD_LEFT);
					s2.GetBitmap(&s2info);
					shield2.CreateCompatibleDC(&dc);
					shield2.SelectObject(&s2);
					pDC->TransparentBlt(x, y, s2info.bmWidth / 4, s2info.bmHeight / 4, &shield2, 0, 0, s2info.bmWidth, s2info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = FALSE;
				}
				else {
					s3.LoadBitmap(IDB_SHIELD_RIGHT);
					s3.GetBitmap(&s3info);
					shield3.CreateCompatibleDC(&dc);
					shield3.SelectObject(&s3);
					pDC->TransparentBlt(x, y, s3info.bmWidth / 4, s3info.bmHeight / 4, &shield3, 0, 0, s3info.bmWidth, s3info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = TRUE;
				}
				if (x <= 900) {
					ar.LoadBitmap(IDB_ARROW);
					ar.GetBitmap(&arinfo);
					arrow.CreateCompatibleDC(&dc);
					arrow.SelectObject(&ar);
					pDC->TransparentBlt(ax, ay, arinfo.bmWidth / 4, arinfo.bmHeight / 4, &arrow, 0, 0, arinfo.bmWidth, arinfo.bmHeight, RGB(255, 0, 0));
					if (ax == x + 50 || ax == x + 40)
						ax = 980;
					else
						ax -= 10;
				}
				Sleep(100);
				Invalidate();
			}
		}
		if (x == 1000)
		{
			pDoc->stage++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			Invalidate();
		
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();
		}
	}
	else if (pDoc->stage == 4)
	{
		if (x != 1000) {
			if (first == TRUE) {
				w1.LoadBitmap(IDB_SHIELD);
				w1.GetBitmap(&w1info);
				warrior1.CreateCompatibleDC(&dc);
				warrior1.SelectObject(&w1);
				pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));
			}
			first = FALSE;
			if (cRun == TRUE) {
				if (left == TRUE) {
					w2.LoadBitmap(IDB_SHIELD_LEFT);
					w2.GetBitmap(&w2info);
					warrior2.CreateCompatibleDC(&dc);
					warrior2.SelectObject(&w2);
					pDC->TransparentBlt(x, y, w2info.bmWidth / 4, w2info.bmHeight / 4, &warrior2, 0, 0, w2info.bmWidth, w2info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = FALSE;
				}
				else {
					w3.LoadBitmap(IDB_SHIELD_RIGHT);
					w3.GetBitmap(&w3info);
					warrior3.CreateCompatibleDC(&dc);
					warrior3.SelectObject(&w3);
					pDC->TransparentBlt(x, y, w3info.bmWidth / 4, w3info.bmHeight / 4, &warrior3, 0, 0, w3info.bmWidth, w3info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = TRUE;
				}
				Sleep(100);
				Invalidate();
			}
		}
		if (x == 1000)
		{
			pDoc->stage++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			pDoc->str_com = FALSE;
			Invalidate();
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();
		}

	}
	else if (pDoc->stage == 5)
	{
		n1.LoadBitmap(IDB_NPC);
		n1.GetBitmap(&n1info);
		NPC1.CreateCompatibleDC(&dc);
		NPC1.SelectObject(&n1);
		pDC->TransparentBlt(200, 100, n1info.bmWidth / 4, n1info.bmHeight / 4, &NPC1, 0, 0, n1info.bmWidth, n1info.bmHeight, RGB(255, 255, 255));

		if (x != 1000) {
			if (first == TRUE) {
				b1.LoadBitmap(IDB_BALLOON);
				b1.GetBitmap(&b1info);
				balloon.CreateCompatibleDC(&dc);
				balloon.SelectObject(&b1);
				pDC->TransparentBlt(150, 50, b1info.bmWidth * 5, b1info.bmHeight * 2, &balloon, 0, 0, b1info.bmWidth, b1info.bmHeight, RGB(255, 0, 0));

				pDC->SetTextColor(RGB(0, 0, 0));
				pDC->SetBkMode(TRANSPARENT);
				pDC->TextOut(200, 70, CString("What time is it now?"));

				sw1.LoadBitmap(IDB_SHIELD);
				sw1.GetBitmap(&sw1info);
				sword1.CreateCompatibleDC(&dc);
				sword1.SelectObject(&sw1);
				pDC->TransparentBlt(x, y, sw1info.bmWidth / 4, sw1info.bmHeight / 4, &sword1, 0, 0, sw1info.bmWidth, sw1info.bmHeight, RGB(255, 255, 255));
			}
			first = FALSE;

			if (cRun == TRUE) {
				if (left == TRUE) {
					s2.LoadBitmap(IDB_SHIELD_LEFT);
					s2.GetBitmap(&s2info);
					shield2.CreateCompatibleDC(&dc);
					shield2.SelectObject(&s2);
					pDC->TransparentBlt(x, y, s2info.bmWidth / 4, s2info.bmHeight / 4, &shield2, 0, 0, s2info.bmWidth, s2info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = FALSE;
				}
				else {
					s3.LoadBitmap(IDB_SHIELD_RIGHT);
					s3.GetBitmap(&s3info);
					shield3.CreateCompatibleDC(&dc);
					shield3.SelectObject(&s3);
					pDC->TransparentBlt(x, y, s3info.bmWidth / 4, s3info.bmHeight / 4, &shield3, 0, 0, s3info.bmWidth, s3info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = TRUE;
				}
				Sleep(100);
				Invalidate();
			}
		}
		if (x == 1000)
		{
			pDoc->stage ++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			Invalidate();
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();
		}
	}
	else if (pDoc->stage == 6)
	{
		if (x != 800) {
			if (first == TRUE) 
			{

				if (left == TRUE) {
					w2.LoadBitmap(IDB_SHIELD_LEFT);
					w2.GetBitmap(&w2info);
					warrior2.CreateCompatibleDC(&dc);
					warrior2.SelectObject(&w2);
					pDC->TransparentBlt(x, y, w2info.bmWidth / 4, w2info.bmHeight / 4, &warrior2, 0, 0, w2info.bmWidth, w2info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = FALSE;
				}
				else {
					w3.LoadBitmap(IDB_SHIELD_RIGHT);
					w3.GetBitmap(&w3info);
					warrior3.CreateCompatibleDC(&dc);
					warrior3.SelectObject(&w3);
					pDC->TransparentBlt(x, y, w3info.bmWidth / 4, w3info.bmHeight / 4, &warrior3, 0, 0, w3info.bmWidth, w3info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = TRUE;
				}
				Sleep(100);
				Invalidate();
			}
		
		}
		if (x == 800)
		{
			w1.LoadBitmap(IDB_SHIELD);
			w1.GetBitmap(&w1info);

			warrior1.CreateCompatibleDC(&dc);
			warrior1.SelectObject(&w1);

			pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));
			if (cRun == TRUE)
			{
				x += 10;
			}
		}
		if (x == 1000)
		{
			pDoc->stage++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			Invalidate();
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();
		}
	}
	else if (pDoc->stage == 7)
	{
		if (x != 1000) {
			if (first == TRUE) {
				w1.LoadBitmap(IDB_SHIELD);
				w1.GetBitmap(&w1info);
				warrior1.CreateCompatibleDC(&dc);
				warrior1.SelectObject(&w1);
				pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));
				m1.LoadBitmap(IDB_MAGIC1);
				m1.GetBitmap(&magic1info);
				magic1.CreateCompatibleDC(&dc);
				magic1.SelectObject(&m1);
				pDC->TransparentBlt(450, 80, magic1info.bmWidth*3/4, magic1info.bmHeight*3/4, &magic1, 0, 0, magic1info.bmWidth, magic1info.bmHeight, RGB(255, 0, 0));
			}
			first = FALSE;

			if (cRun == TRUE) {

				m2.LoadBitmap(IDB_MAGIC2);
				m2.GetBitmap(&magic2info);
				magic2.CreateCompatibleDC(&dc);
				magic2.SelectObject(&m2);
				pDC->TransparentBlt(450, 80, magic2info.bmWidth*3/4, magic2info.bmHeight*3/4, &magic2, 0, 0, magic2info.bmWidth, magic2info.bmHeight, RGB(255, 0, 0));

				if (left == TRUE) {
					w2.LoadBitmap(IDB_SHIELD_LEFT);
					w2.GetBitmap(&w2info);
					warrior2.CreateCompatibleDC(&dc);
					warrior2.SelectObject(&w2);
					pDC->TransparentBlt(x, y, w2info.bmWidth / 4, w2info.bmHeight / 4, &warrior2, 0, 0, w2info.bmWidth, w2info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = FALSE;
				}
				else {
					w3.LoadBitmap(IDB_SHIELD_RIGHT);
					w3.GetBitmap(&w3info);
					warrior3.CreateCompatibleDC(&dc);
					warrior3.SelectObject(&w3);
					pDC->TransparentBlt(x, y, w3info.bmWidth / 4, w3info.bmHeight / 4, &warrior3, 0, 0, w3info.bmWidth, w3info.bmHeight, RGB(255, 255, 255));
					x += 10;
					left = TRUE;
				}
				Sleep(100);
				Invalidate();
			}
		}
		if (x == 1000)
		{
			pDoc->stage ++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			Invalidate();
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();
		}
	
	}
	else if (pDoc->stage == 8)
	{
		if (x != 1000) {
			if (first == TRUE) {
				w1.LoadBitmap(IDB_SHIELD);
				w1.GetBitmap(&w1info);
				warrior1.CreateCompatibleDC(&dc);
				warrior1.SelectObject(&w1);
				pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));

				monster_map.LoadBitmap(IDB_MONSTER);
				monster_map.GetBitmap(&monsterinfo);
				monster.CreateCompatibleDC(&dc);
				monster.SelectObject(&monster_map);
				pDC->TransparentBlt(800, y, monsterinfo.bmWidth, monsterinfo.bmHeight, &monster, 0, 0, monsterinfo.bmWidth, monsterinfo.bmHeight, RGB(0, 0, 255));

			}
			first = FALSE;
			if (cRun == TRUE) {
				if (fx != 750) {
					w1.LoadBitmap(IDB_SHIELD);
					w1.GetBitmap(&w1info);
					warrior1.CreateCompatibleDC(&dc);
					warrior1.SelectObject(&w1);
					pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));

					monster_map.LoadBitmap(IDB_MONSTER);
					monster_map.GetBitmap(&monsterinfo);
					monster.CreateCompatibleDC(&dc);
					monster.SelectObject(&monster_map);
					pDC->TransparentBlt(800, y, monsterinfo.bmWidth, monsterinfo.bmHeight, &monster, 0, 0, monsterinfo.bmWidth, monsterinfo.bmHeight, RGB(0, 0, 255));

					f1.LoadBitmap(IDB_FIREBALL);
					f1.GetBitmap(&fireinfo);
					fire1.CreateCompatibleDC(&dc);
					fire1.SelectObject(&f1);
					pDC->TransparentBlt(fx, fy, fireinfo.bmWidth * 2, fireinfo.bmHeight * 2, &fire1, 0, 0, fireinfo.bmWidth, fireinfo.bmHeight, RGB(0, 0, 255));
					fx += 10;
				}
				else {
					if (left == TRUE) {
						w2.LoadBitmap(IDB_SHIELD_LEFT);
						w2.GetBitmap(&w2info);
						warrior2.CreateCompatibleDC(&dc);
						warrior2.SelectObject(&w2);
						pDC->TransparentBlt(x, y, w2info.bmWidth / 4, w2info.bmHeight / 4, &warrior2, 0, 0, w2info.bmWidth, w2info.bmHeight, RGB(255, 255, 255));
						x += 10;
						left = FALSE;
					}
					else {
						w3.LoadBitmap(IDB_SHIELD_RIGHT);
						w3.GetBitmap(&w3info);
						warrior3.CreateCompatibleDC(&dc);
						warrior3.SelectObject(&w3);
						pDC->TransparentBlt(x, y, w3info.bmWidth / 4, w3info.bmHeight / 4, &warrior3, 0, 0, w3info.bmWidth, w3info.bmHeight, RGB(255, 255, 255));
						x += 10;
						left = TRUE;
					}
				}
				Sleep(100);
				Invalidate();

			}
		}
		if (x == 1000)
		{
			pDoc->stage++;
			x = 80;
			first = TRUE;
			cRun = FALSE;
			Invalidate();
			pDoc->str_com = FALSE;
			pDoc->code_input.RemoveAll();
			pDoc->input_view->Invalidate();
			pDoc->code_view->Invalidate();

		}
	}
}


// COutputView 진단입니다.

#ifdef _DEBUG
void COutputView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void COutputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// COutputView 메시지 처리기입니다.


BOOL COutputView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CBrush backBrush(RGB(10, 10,10));
	CBrush * pOldBrush = pDC->SelectObject(&backBrush);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);*/
	CMFCWarriorDoc * pDoc = (CMFCWarriorDoc *)GetDocument();
	if (pDoc->stage == 0)
		fpButton->ShowWindow(SW_SHOW);
	else
		pButton->ShowWindow(SW_SHOW);
	CClientDC dc(this);
	CBitmap bitmap, w1;
	BITMAP bmpinfo, w1info;
	CDC dcmem, warrior1;
	if (pDoc->stage == 4)
	{
		if (cRun == TRUE)
		{
			bitmap.LoadBitmapW(IDB_LINECLIFF);
		}
		else
		{
			bitmap.LoadBitmap(IDB_CLIFF);
		}
	}
	else if (pDoc->stage == 0)
	{
		bitmap.LoadBitmap(IDB_STARTBACK);
		w1.LoadBitmap(IDB_SHIELD);
		w1.GetBitmap(&w1info);
		warrior1.CreateCompatibleDC(&dc);
		warrior1.SelectObject(&w1);
	}
	else
	{
		bitmap.LoadBitmap(IDB_BACKGROUND);
	}
	CRect rect;
	GetClientRect(&rect);
	bitmap.GetBitmap(&bmpinfo);
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);
	pDC->StretchBlt(0, 0, bmpinfo.bmWidth/11*7, bmpinfo.bmHeight/11*10, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	if (pDoc->stage == 0)
		pDC->TransparentBlt(x, y, w1info.bmWidth / 4, w1info.bmHeight / 4, &warrior1, 0, 0, w1info.bmWidth, w1info.bmHeight, RGB(255, 255, 255));
	else if (pDoc->stage == 1)
	{
		CString str1;
		str1.Format(_T("Stage 1 : AfxMessageBox를 이용하여 \"앞으로가\"라는 메세지를 용사에게 전해주세요!"));
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.right / 2-250, rect.top+20, str1);
	}
	else if(pDoc->stage == 2)
	{
		CString str1;
		str1.Format(_T("Stage 2 : 만들어진 sword 비트맵을 출력하여 나무를 제거하고 지나가세요"));
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.right / 2 - 250, rect.top + 20, str1);
	}
	else if (pDoc->stage == 3) {
		CString str1;
		str1.Format(_T("Stage 3 : Rectangle()함수를 이용해서 방패 만드세요.단, x좌표 : 100 y좌표 : 150 가로 : 50 세로 100"));
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.right / 2 - 250, rect.top + 20, str1);
	}
	else if (pDoc->stage == 4)
	{
		CString str1;
		str1.Format(_T("Stage 4 : 길이 막혔습니다. MoveTo와 LineTo함수를 통해 길을 만들어주세요. 목적지 좌표 : (700,100)"));
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.right / 2 - 250, rect.top + 20, str1);
	}
	else if (pDoc->stage == 5) {
		CString str1;
		str1.Format(_T("Stage 5 : CTime::CurrentTime을 이용하여 현재시간을 받으세요"));
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.right / 2 - 250, rect.top + 20, str1);
	}
	else if (pDoc->stage == 6)
	{
		CBitmap lo;
		BITMAP loinfo;
		CDC lock;
		if (cRun == TRUE)
		{
			lo.LoadBitmap(IDB_DOOROPEN);
		}
		else
		{
			lo.LoadBitmap(IDB_DOOR);
		}
		lo.GetBitmap(&loinfo);
		lock.CreateCompatibleDC(&dc);
		lock.SelectObject(&lo);
		pDC->TransparentBlt(950, 60, loinfo.bmWidth / 2, loinfo.bmHeight / 2, &lock, 0, 0, loinfo.bmWidth, loinfo.bmHeight, RGB(255, 255, 255));
	}
	else if (pDoc->stage == 7) {
		CString str1;
		str1.Format(_T("Stage 7 : CombineRgn()함수를 new에 original과 circle을 합쳐 마법진을 완성해 주세요!"));
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.right / 2 - 250, rect.top + 20, str1);
	}
	else if (pDoc->stage == 8) {
		CString str1;
		str1.Format(_T("Stage 8 : CBrush로 붉은색 brush를 생성하세요!"));
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetBkMode(TRANSPARENT);
		dc.TextOut(rect.right / 2 - 250, rect.top + 20, str1);
	}
	return TRUE;
}


void COutputView::OnInitialUpdate()
{
	pButton = new CButton();
	fpButton = new CButton();
	fpButton->Create(_T("START"), BS_PUSHBUTTON, CRect(350, 200, 550, 300), this, 101);
	pButton->Create(_T("RUN"), BS_PUSHBUTTON, CRect(0, 0, 200, 50), this, 100);
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


BOOL COutputView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	CMFCWarriorDoc * pDoc = (CMFCWarriorDoc *)GetDocument();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (wParam == 101) {
		fpButton->ShowWindow(SW_HIDE);
		pDoc->stage++;
		Invalidate();
		pDoc->code_view->Invalidate();

	}
	if (wParam == 100) {
		if (pDoc->str_com)
		{
			if (pDoc->stage == 1)
				AfxMessageBox(_T("앞으로 가"));
			if (pDoc->stage == 5)
			{
				time = CTime::GetCurrentTime();
				TimeData.Format(_T("현재 시각은 %d시 %d분 %d초입니다."),
					time.GetHour(), time.GetMinute(), time.GetSecond());
				AfxMessageBox(TimeData);
			}
			cRun = TRUE;
		}
		if (cRun == TRUE)
			Invalidate();
		else AfxMessageBox(_T("코드를 다시 확인하세요."));
	}
	return CView::OnCommand(wParam, lParam);
}
