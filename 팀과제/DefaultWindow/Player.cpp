#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo = { 400.f, WINCY-50.f, 100.f, 100.f };
	m_fSpeed = 10.f;
}

int CPlayer::Update(void)
{
	Key_Input();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_LEFT))
		if (!(m_tRect.left <= 100)) {
			m_tInfo.fX -= m_fSpeed;
		}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (!(m_tRect.right >= WINCX - 100)) {
			m_tInfo.fX += m_fSpeed;
		}
	}
}

void CPlayer::Late_Update(void)
{
}
