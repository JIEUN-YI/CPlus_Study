#pragma once
#include "Singleton.h"
#include "framework.h"
#include <string>;
using namespace std;
class RenderManager : public Singleton<RenderManager>// 그려주는 작업을 진행 - 싱글톤
{
	/* 20250612 - 그래픽 더블 버퍼링*/
public:
	void Start(HWND hwnd); // 그림판 가져오기
	void End();
	void BeginDraw();	// 그리기 전
	void EndDraw();		// 그리기 후

	void Rect(float startX, float startY, float endX, float endY);	// 사각형 그리기
	void Text(wstring str, float x, float y);						// 글자 쓰기

private :
	
	HWND hWnd;			// 게임 윈도우
	HDC hDC;			// 게임화면
	HDC hBackDC;		// 백버퍼 화면
	HBITMAP hBitmap;	// 백버퍼 이미지

	// RECT rect;		// 화면 크기
	int winSizeX;		// 화면 가로크기
	int winSizeY;		// 화면 세로크기

	/* 20250608 수업분
	public:
		void Start(HWND hWnd);
		void End();

		void BeginDraw(); // 새로운 그림판에 준비
		void EndDraw(); // 게임 화면으로 복사

		void Rectacgle(int startX, int startY, int endX, int endY);

	private:
		HWND hWnd;
		HDC hDC;
		HDC hBackDC;
		HBITMAP hBitmap;
	*/
};

#define RENDER RenderManager :: GetInstance()
