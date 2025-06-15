#pragma once
#include "Singleton.h"
#include "framework.h"
#include <string>;
using namespace std;
class RenderManager : public Singleton<RenderManager>// �׷��ִ� �۾��� ���� - �̱���
{
	/* 20250612 - �׷��� ���� ���۸�*/
public:
	void Start(HWND hwnd); // �׸��� ��������
	void End();
	void BeginDraw();	// �׸��� ��
	void EndDraw();		// �׸��� ��

	void Rect(float startX, float startY, float endX, float endY);	// �簢�� �׸���
	void Text(wstring str, float x, float y);						// ���� ����

private :
	
	HWND hWnd;			// ���� ������
	HDC hDC;			// ����ȭ��
	HDC hBackDC;		// ����� ȭ��
	HBITMAP hBitmap;	// ����� �̹���

	// RECT rect;		// ȭ�� ũ��
	int winSizeX;		// ȭ�� ����ũ��
	int winSizeY;		// ȭ�� ����ũ��

	/* 20250608 ������
	public:
		void Start(HWND hWnd);
		void End();

		void BeginDraw(); // ���ο� �׸��ǿ� �غ�
		void EndDraw(); // ���� ȭ������ ����

		void Rectacgle(int startX, int startY, int endX, int endY);

	private:
		HWND hWnd;
		HDC hDC;
		HDC hBackDC;
		HBITMAP hBitmap;
	*/
};

#define RENDER RenderManager :: GetInstance()
