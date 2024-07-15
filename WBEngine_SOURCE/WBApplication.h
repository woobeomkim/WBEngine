#pragma once
#include "CommonInclude.h"
#include "WBGameObject.h"
#include "WBGameObjectRed.h"

namespace WB
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		
		void Update();
		void LateUpdate();
		void Render();
	

	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
		// �÷��̾�
		//float mX;
		//float mY;
		GameObject mPlayer;
		GameObjectRed mRedPlayer;
	};

}

