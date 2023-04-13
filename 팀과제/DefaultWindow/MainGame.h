#pragma once

#include "Define.h"
#include "Player.h"
#include "AbstractFactory.h"

class CMainGame
{
public:
	void		Initialize(void);
	void		Update(void);
	void		Late_Update(void);
	void		Render();
	void		Release(void);

private:
	HDC			m_DC;
	int			m_iFPS;
	TCHAR		m_szFPS[32];
	DWORD		m_dwTime;

	list<CObj*>		m_ObjList[OBJ_END];
public:
	CMainGame();
	~CMainGame();
};

