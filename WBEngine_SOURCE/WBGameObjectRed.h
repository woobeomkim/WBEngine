#pragma once
#include "CommonInclude.h"

namespace WB
{
	class GameObjectRed
	{
	public:
		GameObjectRed();
		~GameObjectRed();

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
		// ���� ������Ʈ�� ��ǥ
		float mX;
		float mY;
	};
}

