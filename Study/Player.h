#pragma once
// 헤더 파일에서는 클래스의 메서드와 데이터를 선언만 작성
//		=> 헤더 파일의 목록만 확인하여 클래스의 기능을 확인 가능
class Player
{
	// 함수를 헤더파일에서 우선 선언 후
	// 우클릭->빠른 작업 및 리펙터링 or ctrl+.
	// Player.cpp에서 함수 작성
public:
	void Jump();
	void Attack();

private:
	int jumpSpeed;
};

