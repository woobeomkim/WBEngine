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
	// �Ķ� �귯�� ����
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));

	// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

	Ellipse (hdc, 1400 + mX, 700 + mY, 1500 + mX, 800 + mY);

	// �ٽ� ��� �����귯���� ����
	SelectObject(hdc, oldBrush);

	// �Ķ� �귯�� ����
	DeleteObject(redBrush);
	SelectObject(hdc, oldBrush);
}

void WB::GameObjectRed::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}
