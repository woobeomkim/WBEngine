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
	// 파랑 브러쉬 생성
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

	// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

	// 다시 흰색 원본브러쉬로 선택
	SelectObject(hdc, oldBrush);

	// 파랑 브러쉬 삭제
	DeleteObject(blueBrush);
	SelectObject(hdc, oldBrush);
}

void WB::GameObject::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}
