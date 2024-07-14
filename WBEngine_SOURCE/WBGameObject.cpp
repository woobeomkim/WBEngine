#include "WBGameObject.h"

WB::GameObject::GameObject()
{
}

WB::GameObject::~GameObject()
{
}

void WB::GameObject::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mX -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mX += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mY -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		mY += 0.01f;
	}

}

void WB::GameObject::LateUpdate()
{
}

void WB::GameObject::Render(HDC hdc)
{
	// �Ķ� �귯�� ����
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

	// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

	// �ٽ� ��� �����귯���� ����
	SelectObject(hdc, oldBrush);

	// �Ķ� �귯�� ����
	DeleteObject(blueBrush);
	SelectObject(hdc, oldBrush);
}

void WB::GameObject::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}
