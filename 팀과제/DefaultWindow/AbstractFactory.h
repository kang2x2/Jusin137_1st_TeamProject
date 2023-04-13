#pragma once
#include "Obj.h"

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory(){}
	~CAbstractFactory(){}

public:
	static CObj* Create() {
		CObj* pTemp = new T;
		pTemp->Initialize();
		return pTemp;
	}
	static CObj* Create(float _fX, float _fY) {
		CObj* pTemp = new T;
		pTemp->Initialize();
		return pTemp;
	}
};

