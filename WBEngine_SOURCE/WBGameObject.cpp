#include "WBGameObject.h"
#include "WBInput.h"
#include "WBTime.h"

WB::GameObject::GameObject() :mX(0),mY(0)
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
	// 파랑 브러쉬 생성
	HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));

	// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
	HPEN olePen = (HPEN)SelectObject(hdc, redPen);

	Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

	// 다시 흰색 원본브러쉬로 선택
	SelectObject(hdc, oldBrush);

	// 파랑 브러쉬 삭제
	DeleteObject(blueBrush);
	DeleteObject(redPen);
	SelectObject(hdc, oldBrush);
}

void WB::GameObject::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}
