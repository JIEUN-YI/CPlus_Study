#pragma once
#include "framework.h"

class Game
{
public:
	void Start(HINSTANCE hInstance, HWND hWnd);	// 게임 시작 처리
	void End();		// 게임 종료 처리
	void Input();	// 게임 입력
	void Update();	// 게임 동작
	void Render();	// 게임 그리기

private:
	HINSTANCE hInstance; // 프로그램 핸들
	HWND hWnd; // 윈도우 핸들

	float x = 0;
	float y = 0;
};



