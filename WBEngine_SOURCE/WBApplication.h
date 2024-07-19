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
		void clearRenderTarget();
		void copyRenderTarget(HDC source,HDC dest);
	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
		// 플레이어
		GameObjectRed mRedPlayer;

		//std::vector<Scene*> mScene;
		
		//std::vector<GameObject*> mGameObjects;
	};

}

