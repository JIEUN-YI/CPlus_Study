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
	int fps;				// Frame per Seconds : 1초당 그려진 화면 수
	float deltaTime;		// Delta Time : 1프레임당 소요된 시간 = 단위시간

	chrono::high_resolution_clock::time_point::prevTime;
	chrono::high_resolution_clock::time_point::curTime;
};

#define TIME TimeManager::GetInstance();
#define FRAME TimeManager::GetInstance()->GetFPS();
#define DT TimeManager::GetInstance()->GetDT();
*/