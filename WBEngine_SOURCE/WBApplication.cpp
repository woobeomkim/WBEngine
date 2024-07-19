#include "WBApplication.h"
#include "WBInput.h"
#include "WBTime.h"
#include "WBSceneManager.h"

namespace WB
{
	Application::Application() : mHwnd(nullptr), mHdc(nullptr), mWidth(0), mHeight(0), mBackHdc(nullptr), mBackBitmap(nullptr)
    {
    }
    Application::~Application()
    {
    }
    void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);


		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);

		// ������ �ػ󵵿� �´� �����(��ȭ��)����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		SceneManager::Initialize();
		/*for (size_t i = 0; i < 100; i++)
		{
			GameObject* gameObj = new GameObject();
			gameObj->SetPosition(rand() % 1600, rand() % 900);
			mGameObjects.push_back(gameObj);
		}*/
		

		Input::Initailize();
		Time::Initailize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		
		/*for (int i = 0; i < mGameObjects.size(); i++)
			mGameObjects[i]->Update();*/
		SceneManager::Update();

		mRedPlayer.Update();
		
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{   
		clearRenderTarget();

		Time::Render(mBackHdc);
		/*for (int i = 0; i < mGameObjects.size(); i++)
			mGameObjects[i]->Render(mBackHdc);*/
		SceneManager::Render(mBackHdc);
		mRedPlayer.Render(mBackHdc);

		// BackBuffer�� �ִ°� ���� Buffer�� ����(�׷��ش�)
		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::clearRenderTarget()
	{
		//clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);

	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer�� �ִ°� ���� Buffer�� ����(�׷��ش�)
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}