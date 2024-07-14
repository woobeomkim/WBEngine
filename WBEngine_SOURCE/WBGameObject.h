#pragma once
#include "CommonInclude.h"

namespace WB
{
	//Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y);

		float GetPositionX()
		{
			return mX;
		}

		float GetPositionY()
		{
			return mY;
		}
	private:
		// 게임 오브젝트의 좌표
		float mX;
		float mY;
	};
}
