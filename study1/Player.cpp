// 소스 파일에서는 헤더파일에서 선언한 파일을 재정의
//		=> 소스 파일을 확인하여 클래스의 기능 작동을 확인
#include "Player.h"
#include <iostream>

using namespace std;

void Player::Jump()
{
	cout << "점프" << endl;
}

void Player::Attack()
{
	cout << "공격" << endl;
}
