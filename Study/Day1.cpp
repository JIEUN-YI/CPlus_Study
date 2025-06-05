/* Day1-example1
// <표준입출력>
// 콘솔 기능을 사용하기 위한 iostream 기능
#include <iostream> //input output 스트림

// 네임스페이스를 선언 : 이후 코드에서 네임스페이스를 사용
// std를 사용가능
// std:: 를 써도 되고 쓰지 않아도 됨
using namespace std;

// namespace의 선언
namespace AAA
{
    string name;
    void Test()
    {
        std::cout << "name : " << name << "\n";
    }
}
namespace BBB
{
    string name;
    void Test()
    {
        std::cout << "name : " << name << "\n";
    }
}
/// <summary>
///  모든 c++은 main() 함수를 포함해야함
/// </summary>
/// <returns></returns>
int main()
{
    // std => stadard namspace 안에 있는 cout/cin
    int input;
    cout << "입력하세요 : ";
    std::cin >> input;
    std::cout << "입력하신 숫자는 " << input << "입니다\n";

    cout << "====================================================\n";

    // namespace의 사용

    AAA::name = "안녕";
    BBB::name = "하세요";

    AAA::Test();
    BBB::Test();
}
*/

/*Day1-example2
#include <iostream>
using namespace std;

void main()
{
    // c++의 경우 자동형변환 가능
    // 단 명확하게 해주는 것이 좋다
    // c++에서 bool은 true/false만 하지 않음
    //      0 = false / 그외는 true로 판단
    // string은 자동 형변환 x
    // const를 사용하여 상수 선언 가능
    int value = 10;
    float f_value = 10.5;

    cout << "Value의 값은 " << value << " 입니다.\n";
    cout << "Value의 값은 " << f_value << " 입니다.\n";
}*/

/*Day1-example3
#include <iostream>
using namespace std;

// C#과 동일한 연산자, 조건문, 반복문
// 단, 문자열은 switch에 string을 사용할 수 없음
//
// 함수 사용 주의사항
// c++에서는 아래에 있는 함수는 불러오지 못함
//      c++은 무조건 위에서 아래로 방향성을 가지고 흐름
//      함수가 아래에 있으면 찾지 못함
//      해결법 : 위에 함수 선언 후 본문을 따로 작성
//               선언 후 제작 필수 => 하지 않으면 에러

// 함수 선언
void Test();


void main()
{
    Test();
}

// 함수 본문을 선언
void Test()
{
    cout <<
        "함수의 실행";
}
*/

/*Day1-example4
#include <iostream>
using namespace std;

// C++ 구조체 = 기본적으로 public 접근제한자로 인식
// C++ 클래스 = 기본적으로 private 접근제한자로 인식
struct Data
{
    // 접근제한자를 한번에 범위로 처리 가능
public:
    int score;
    float time;
private:
        string name;
        double distance;
};

// 열거형의 사용
enum Direction{ Up, Down, Left, Right };

void main()
{
    Data data;
    data.score = 10;
    data.time = 10.5f;
    cout << "Data 구조체 안에 scroe : " << data.score << "\n";
    cout << "Data 구조체 안에 time : " << data.time << "\n";

    cout << "열거형의 예시 : ";
    Direction direction = Direction::Left;
    cout << direction;
}
*/

/*Day1-example5 : C++만의 특징
#include <iostream>
using namespace std;

// C#
// 구조체(값형식) vs 클래스(참조형식)
//
// C++
// 구조체 vs 클래스?
//      => C++은 값형식과 참조형식 둘 다 사용 가능 : 사용자의 설정에 따라 사용
//      => 원하는 방향으로 사용 가능
//      => 둘의 차이 : public vs private
// 일반적으로 사용하는 경우 모두 값형식으로 인식
// 단,
// 포인터를 사용하는 경우 참조형식
//
//

void main()
{
    // 값형식의 사용 - 변함 없는 num
    int num = 10;
    int other = num;
    cout << "num : " << num << ", other : " << other << endl; //endl : 줄바꿈
    other = 20;
    cout << "num : " << num << ", other : " << other << endl;

    cout << "======================================= " << endl;

    // 참조형식의 사용 - 포인터
    // Pointer
    // 프로그램은 메모리를 사용, 메모리는 변수를 저장한 주소를 가지고 있음
    // 메모리 주소값을 통한 접근방법으로 다양한 작업 가능

    int p_num1 = 5;
    int p_num2 = 10;
    cout << "p_num1 : " << p_num1 << endl;
    cout << "p_num1 의 메모리 주소 : " << &p_num1 << endl; // 변수의 저장 위치불러오기 = &변수명
    cout << "p_num2 : " << p_num2 << endl;
    cout << "p_num2 의 메모리 주소 : " << &p_num2 << endl;

    cout << "======================================= " << endl;

    // 포인터 변수의 선언
    // 자료형 뒤 *를 사용하여 포인터 변수를 선언
    int* ptr = &p_num1; // p_num1 변수의 메모리 주소를 포인터 변수 ptr에 저장
    cout << "p_num1 의 메모리 주소(변수) : " << &p_num1 << endl;
    cout << "p_num1 의 메모리 주소(포인터) : " << ptr << endl;
    cout << "p_num1 의 값(변수) : " << p_num1 << endl;
    cout << "p_num1 의 값(포인터) : " << *ptr << endl;

}
*/

/*Day1-example6 : 포인터의 활용
#include <iostream>
using namespace std;

/// <summary>
/// 각 변수의 주소값인 포인터 변수를 받아서 주소를 이동하여 바꾸는 함수
/// </summary>
/// <param name="left"></param>
/// <param name="right"></param>
void Swap(int* left, int* right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void main()
{
    // 값형식의 사용 - 변함 없는 num
    int num1 = 10;
    int num2 = 20;
    cout << "num1 : " << num1 << endl;
    cout << "num2 : " << num2 << endl;

    Swap(&num1, &num2);

    cout << "num1 : " << num1 << endl;
    cout << "num2 : " << num2 << endl;
}
*/

/*Day1-example7 : 메모리
#include <iostream>
using namespace std;

// C# 메모리
// 메모리 사용을 원하는 경우 할당 => 가비지 컬랙터가 관리
// C++ 메모리
// 메모리 사용을 원하는 경우 할당 => 직접 해제 : 가비지컬랙터 X
//
// 변수의 접근 법위와 생존범위 - C++
// 종류 - 메모리 영역 / 접근 범위 / 생존범위
// 전역변수 - 데이터영역 / 모든 곳 / 프로그램 시작 ~ 끝
// 정적변수 - 데이터영역 / 블록 내부 / 프로그램 시작 ~ 끝
// 지역변수 - 스택영역 / 블록내부 / 블록 시작 ~ 끝
// 매개변수 - 스택영역 / 블록내부 / 블록 시작 ~ 끝
// 사용자의 동적할당 - 힙 영역 / 포인터 변수 / 사용자의 할당 ~ 반납
//

// 블록 안에서만 사용되는 변수
void Function(int param) {
    int value = 10; // 지역변수
    param = 20; // 매개변수
}

// 프로그램 시작부터 끝까지 유지되는 변수
int global = 0; // 전역변수
class Data
{
public:
    static int value; // 정적변수
};

void main()
{
    // 사용자의 동적할당 변수
    // 힙 영역에 사용자가 동적 할당
    // 포인터 변수는 스택영역 => new를 사용하여 힙 영역으로 사용
    int* ptr = new int; // new를 사용하여 힙 영역에 영역을 설정
    int* other = ptr;
    *ptr = 10; // ptr의 주소(힙영역)에 10을 저장

    cout << ptr << "\n" << other << endl;
    cout << "===============================================" << endl;
    cout << "ptr이 가리키는 주소 : " << ptr << endl;
    cout << "other이 가리키는 주소 : " << other << endl;
    cout << "ptr이 가진 힙영역에 있는 데이터 : " << *ptr << endl;
    cout << "other이 가진 힙영역에 있는 데이터 : " << *other << endl;

    cout << "===============================================" << endl;
    *other = 20; // other의 주소에 20을 저장
    cout << "ptr이 가리키는 주소 : " << ptr << endl;
    cout << "other이 가리키는 주소 : " << other << endl;
    cout << "ptr이 가진 힙영역에 있는 데이터 : " << *ptr << endl;
    cout << "other이 가진 힙영역에 있는 데이터 : " << *other << endl;

    cout << "===============================================" << endl;
    delete ptr; // 할당한 int* ptr = new int; 를 삭제
    ptr = nullptr; // nullptr를 사용하여 힙 영역 할당을 삭제
    other = nullptr; // other를 ptr를 복사하여 사용하였으므로 같이 초기화 필요

    cout << "ptr이 가리키는 주소 : " << ptr << endl;
    cout << "other이 가리키는 주소 : " << other << endl;
}
*/

/*Day1-example8 : 배열
#include <iostream>
using namespace std;

void main()
{
    // 스택에 배열을 저장 => 즉, 스택이기에 메모리 크기를 동작 도중 변경 불가능 = 고정적인 크기만 사용 가능
    int array[5]; // 포인터 사용 X = 스택에 배열을 저장
    // 스택으로 사용하기 때문에 사용이 끝나는 경우 자동으로 삭제

    // 힙에 포인터를 사용한 배열 저장 => 메모리 크기 동작 도중 변경 가능 = 유동적인 크기 사용 가능
    int* h_array = new int[5];
    delete[] h_array; // 힙에 할당한 배열의 경우 delete[]을 사용하여 배열 전체 삭제 필수
}
*/

/*Day1-example9
#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int score;
    int* scores = nullptr; // 소멸자 예시를 위한 배열
    // 생성자 사용
    Student()
    {
        name = "무명";
        score = 0;
        scores = new int[5];
    }
    Student(string name, int score) {
        this->name = name;
        this->score = score;
        scores = new int[5];
    }
    // (가상)소멸자 : C++에서는 필수로 구현
    // int와 string 같은 경우에는 소멸자를 이미 포함하고 있으므로 delete student로 소멸
    // 단 scores 배열의 경우 new를 사용하여 제작하였으므로 delete[]를 이용하여 소멸자에서 삭제 구현 필요
    virtual ~Student()
    {
        cout << "소멸자가 있으며 객체의 삭제 구현" << endl;
        delete[] scores;
        scores = nullptr; // 소멸 시 scores를 지우면서 삭제되어야 함

    }
};

void main()
{
    // 스택에서의 사용법
    Student s_student;
    s_student.name = "학생";
    s_student.score = 100;

    // 힙에서의 사용법
    Student* student = new Student(); // Student*(포인터변수)를 선언 후 힙 영역에 할당
    (*student).name = "학생"; // 포인터 변수의 naem과 score를 설정
    // or 동일한 표현) student->name = "학생"
    // (*student).score = 100;
    student->score = 100;
    cout << "Name : " << (*student).name << endl; // 값형식 .
    cout << "Score : " << student->score << endl;

    delete student;

    cout << "==========================================" << endl;

    // 생성자로 사용하여 선언
    Student* no_student = new Student();
    Student* set_student = new Student("이름", 100);
    cout << "Name : " << no_student->name << endl;
    cout << "Score : " << no_student->score << endl;
    cout << "Name : " << set_student->name << endl;
    cout << "Score : " << set_student->score << endl;
    cout << "==========================================" << endl;

    no_student->name = "변경"; // 참조형식 ->
    no_student->score = 50;
    no_student->scores[0] = no_student->score;
    set_student->scores[0] = set_student->score;
    cout << "Name : " << no_student->name << endl;
    cout << "Score : " << no_student->score << endl;

    delete no_student;
    no_student = nullptr;
    delete set_student;
    set_student = nullptr;

}*/

/*Day1-example10 : Player클래스*/
#include <iostream>
#include "Player.h" // Player.h 헤더 파일을 사용하여 Player.h에서 선언한 것을 사용 가능
using namespace std;

// C++의 class 분리 구현
// 클래스의 멤버 함수를 선언부와 구현부로 나누어 작성하는 방법
// 사용 이유
//  => 구현 이전에 기능을 사용하는 경우 컴파일러에서 내용을 찾을 수 없기 때문에 전방 선언이 필요(C++ 특징)
//  => 헤더 파일에 선언분에 해당하는 내용을 한번만 include
//  => 구현부에서 내용을 감추고, 선언부를 통해 사용방법만 제공
//  => 클래스 내부에 구현부를 포함하는 경우 코드량이 많아져 전체적인 클래스 구성을 확인하기 어려움
//     즉, 간결하게 확인하기 위해 분리하여 구현
// 
// 헤더 파일
//  => 클래스의 선언부를 포함
//  => 소스 파일에서 해당 기능을 필요로 하는 경우 #include "헤더파일명.h"로 포함
// 소스 파일
//  => 클래스의 구현부를 포함
//

void main()
{
    Player* player = new Player(); // player를 선언
    player->Jump();
    player->Attack();
}