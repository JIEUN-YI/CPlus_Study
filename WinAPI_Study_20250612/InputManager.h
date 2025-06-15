#pragma once
#include "Singleton.h"
class InputManager : public Singleton<InputManager>
{
public :
	void Start();
	void End();

	void CheckInput();	// 키 입력 확인
	bool GetKey(int key); // 키 종류 int값으로 받아, 키를 누르고 있는 중 여부 확인
	bool GetKeyDown(int key); // 키 종류 int값으로 받아, 키를 누른 순간의 여부 확인
	bool GetKeyUp(int key); // 키 종류 int값으로 받아, 키를 땐 순간 여부 확인

private :
	bool prevKeys[255];	// 이전 키 입력 상태
	bool curKeys[255];	// 현재 키 입력 상태
};

#define GMAE_INPUT InputManager::GetInstance()

