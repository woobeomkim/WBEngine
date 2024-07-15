#include "WBGameObjectRed.h"

WB::GameObjectRed::GameObjectRed()
{
}

WB::GameObjectRed::~GameObjectRed()
{
}

void WB::GameObjectRed::Update()
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		mX -= 0.01f;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		mX += 0.01f;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		mY -= 0.01f;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		mY += 0.01f;
	}
}

void WB::GameObjectRed::LateUpdate()
{
}

void WB::GameObjectRed::Render(HDC hdc)
{
	// 파랑 브러쉬 생성
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));

	// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

	Ellipse (hdc, 1400 + mX, 700 + mY, 1500 + mX, 800 + mY);

	// 다시 흰색 원본브러쉬로 선택
	SelectObject(hdc, oldBrush);

	// 파랑 브러쉬 삭제
	DeleteObject(redBrush);
	SelectObject(hdc, oldBrush);
}

void WB::GameObjectRed::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}
