#include "Game.h"
#include "RenderManager.h"
#include "TimeManager.h"
#include "InputManager.h"

using namespace std;

float startX;
float startY;

Game::Game()
{

}

Game::~Game()
{

}

void Game::Start(HINSTANCE hInstance, HWND hWnd)
{
	// hDC = GetDC(hWnd); // 창에 그릴 그림판
	RENDER->Start(hWnd);
	TIME->Start();
}

void Game::End()
{
	// ReleaseDC(hWnd, hDC); // 그림판 종료
	RENDER->End();
	TIME->End();
}

void Game::Input()
{
	GMAE_INPUT->CheckInput();
}

bool isLeft = false;
void Game::Update()
{
	TIME->CheckTime(); // 시간 측정
	// 자연스러운 이동
	if (GMAE_INPUT->GetKey(VK_UP)) // vritual key
	{
		y -= 100 * DT;
	}
	if (GMAE_INPUT->GetKey(VK_DOWN))
	{
		y += 100 * DT;
	}	
	if (GMAE_INPUT->GetKey(VK_LEFT))
	{
		x -= 100 * DT;
	}	
	if (GMAE_INPUT->GetKey(VK_RIGHT))
	{
		x += 100 * DT;
	}

	/* 키 입력에 따라 한칸씩 이동
	if (GMAE_INPUT->GetKeyUp(VK_UP)) // vritual key
	{
		y -= 100;
	}
	if (GMAE_INPUT->GetKeyUp(VK_DOWN))
	{
		y += 100;
	}	
	if (GMAE_INPUT->GetKeyUp(VK_LEFT))
	{
		x -= 100;
	}	
	if (GMAE_INPUT->GetKeyUp(VK_RIGHT))
	{
		x += 100;
	}
	*/
	/* DeltaTime으로 이동
	if (isLeft) {
		x -= 100 * DT;
		if (x < 0) {
			isLeft = false;
		}
	}
	else
	{
		x += 100 * DT;
		if (x > 500) {
			isLeft = true;
		}
	}
	*/

	/* 시간으로 곱하는 단점 : 컴퓨터의 성능에 따라 움직임이 달라짐
	 *  Time.DeltaTime의 활용이 필요
	if (isLeft) {
		x -= 0.1f;
		if (x < 0) {
			isLeft = false;
		}
	}
	else
	{
		x += 0.1f;
		if (x > 500) {
			isLeft = true;
		}
	}
	
	*/
	/*
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		x -= 0.1f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		x += 0.1f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		y -= 0.1f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		y += 0.1f;
	}
	*/
	
}
        
void Game::Render()
{
	/*
	RENDER->BeginDraw();
	RENDER->Rect(x + 000, y + 000, x + 100, y + 100); // 사각형 그리기
	wstring fpsText = L"FPS : " + to_wstring(FRAME);
	RENDER->Text(fpsText, 1000, 0); // 글자 쓰기
	wstring dtText = L"DT : " + to_wstring(DT);
	RENDER->Text(dtText, 1000, 0); // 글자 쓰기

	RENDER->EndDraw();
	*/
	/*
	// 잔상을 없애기 위해 지우고 그려야 하지만, 그대로 진행하면 지워지는 것도 눈에 보이게 됨
	// => 깜빡거림 현상 = 블링킹
	// 해결 법 : 더블 버퍼링
	// 두 개의 화면을 사용하여 다른 화면에 그린 후
	// 결과를 복사하여 붙여넣기
	// RenderManager::GetInstance()->Rectacgle(x, y, x + 100, y + 100);
	// RENDER->Rectacgle(x, y, x + 100, y + 100);*/
	/*
	RENDER->BeginDraw();

	RENDER->Rectacgle(x, y, x + 100, y + 100);
	RENDER->Rectacgle(x + 100, y + 100, x + 200, y + 200);
	RENDER->Rectacgle(x + 200, y + 200, x + 300, y + 300);

	RENDER->EndDraw();
	*/
	// Rectangle(hDC, 100, 100, 200, 200); // 계속 사각형을 그리는 것
	// 단, 지우지 않는 경우 잔상이 남음
	// Rectangle(hDC, x, y, x + 100, y + 100); // 계속 사각형의 위치를 변동하여 그림 => 게임은 실시간으로 그려져야 함. 
	// 더블 버퍼링 : 잔상이 남지 않도록 하는 기법
	// RanderManager::GetInstance()->Text(); 
	// // 싱글톤으로 사용 가능
	// = RENDER->Text();

	RENDER->BeginDraw(); // 그리기 전 작업

	// 백윈도우에 원하는 그림 그리기
	RENDER->Rect(x + 000, y + 000, x + 100, y + 100);
	wstring fpsText = L"FPS : " + to_wstring(FRAME);
	RENDER->Text(fpsText,1000,0);
	wstring dtText = L"FPS : " + to_wstring(DT);
	RENDER->Text(dtText, 1100, 0);

	RENDER->EndDraw(); // 그리기 후 작업 - 윈도우에 출력하기

}