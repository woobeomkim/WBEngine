#include "WBGameObject.h"
#include "WBInput.h"
#include "WBTime.h"

WB::GameObject::GameObject()
{
}

WB::GameObject::~GameObject()
{
}

void WB::GameObject::Update()
{
	const int speed = 100.0f;
	if (Input::GetKey(eKeyCode::A))
	{
		mX -= speed * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::D))
	{
		mX += speed * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::W))
	{
		mY -= speed * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::S))
	{
		mY += speed * Time::DeltaTime();
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
