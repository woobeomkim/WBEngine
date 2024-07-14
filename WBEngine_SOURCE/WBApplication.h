#pragma once
#include "CommonInclude.h"
#include "WBGameObject.h"

namespace WB
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		
		void Update();
		void LateUpdate();
		void Render();
	

	private:
		HWND mHwnd;
		HDC mHdc;

		// 플레이어
		//float mX;
		//float mY;
		GameObject mPlayer;
	};

}

