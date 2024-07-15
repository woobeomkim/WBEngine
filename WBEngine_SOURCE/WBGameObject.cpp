#include "WBGameObject.h"
#include "WBInput.h"

WB::GameObject::GameObject()
{
}

WB::GameObject::~GameObject()
{
}

void WB::GameObject::Update()
{
	if (Input::GetKey(eKeyCode::A))
	{
		mX -= 0.01f;
	}
	if (Input::GetKey(eKeyCode::D))
	{
		mX += 0.01f;
	}
	if (Input::GetKey(eKeyCode::W))
	{
		mY -= 0.01f;
	}
	if (Input::GetKey(eKeyCode::S))
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
