#pragma once
#include "Singleton.h"
#include <chrono>

using namespace std;

// Time.DeltaTime과 같은 기능을 쓰기 위한 클래스 생성
class TimeManager : public Singleton<TimeManager>
{
public :
	void Start();
	void End();

	void CheckTime();

private:
	int fps;				// Frame per Seconds : 1초당 그려진 화면 수
	float deltaTime;		// 1프레임 당 소요된 시간 = 단위시간 - Unity와의 차이 : 직접 만들어서 사용하는 WINAPI

	chrono::high_resolution_clock::time_point prevTime; // 이전 시간
	chrono::high_resolution_clock::time_point curTime;	// 지금 시간

public :
	int GetFPS() { return fps; }
	float GetDT(){return deltaTime;}


};

#define TIME TimeManager::GetInstance()
#define FRAME TimeManager::GetInstance()->GetFPS()
#define DT TimeManager::GetInstance()->GetDT()

