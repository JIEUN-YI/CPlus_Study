/*
#pragma once
#include "Singleton.h"
#include <chrono>;
using namespace std;

class TimeManager:public Singleton<TimeManager>
{
public:
	void Start();
	void End();

	void CheckTime();

	int GetFPS() { return fps; }
	float GetDT() { return deltaTime; }

private:
	int fps;				// Frame per Seconds : 1�ʴ� �׷��� ȭ�� ��
	float deltaTime;		// Delta Time : 1�����Ӵ� �ҿ�� �ð� = �����ð�

	chrono::high_resolution_clock::time_point::prevTime;
	chrono::high_resolution_clock::time_point::curTime;
};

#define TIME TimeManager::GetInstance();
#define FRAME TimeManager::GetInstance()->GetFPS();
#define DT TimeManager::GetInstance()->GetDT();
*/