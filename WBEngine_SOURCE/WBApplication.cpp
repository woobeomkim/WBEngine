#include "WBApplication.h"
#include "WBInput.h"

namespace WB
{
    Application::Application() : mHwnd(nullptr), mHdc(nullptr)
    {
    }
    Application::~Application()
    {
    }
    void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);
		mRedPlayer.SetPosition(0, 0);
	
		Input::Initailize();
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
		mPlayer.Update();
		mRedPlayer.Update();
		
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{   
		mPlayer.Render(mHdc);
		mRedPlayer.Render(mHdc);
	}
}