#include "stdafx.h"
#include "MainGame.h"

CMainGame::CMainGame()
	: m_dwTime(GetTickCount()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);

	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());

}

void CMainGame::Update(void)
{
	for (size_t i = OBJ_PLAYER; i < OBJ_END; ++i) {
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end();) {

			int iEvent = (*iter)->Update();

			if (iEvent == OBJ_DEAD) {
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			} 
			else {
				++iter;
			}
		}
	}
}

void CMainGame::Late_Update(void)
{
	for (size_t i = OBJ_PLAYER; i < OBJ_END; ++i) {
		for (auto& iter : m_ObjList[i]) {
			iter->Late_Update();
		}
	}
}

void CMainGame::Render()
{
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount()) {
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, 100, 0, WINCX - 100, WINCY);
	TextOut(m_DC, WINCX - 75, 10, m_szFPS, lstrlen(m_szFPS));

	for (size_t i = OBJ_PLAYER; i < OBJ_END; ++i) {
		for (auto& iter : m_ObjList[i]) {
			iter->Render(m_DC);
		}
	}
	
}

void CMainGame::Release(void)
{
	for (size_t i = OBJ_PLAYER; i < OBJ_END; ++i) {
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), CDeleteObj());
		m_ObjList[i].clear();
	}

	ReleaseDC(g_hWnd, m_DC);
}

