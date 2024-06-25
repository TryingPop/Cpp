/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : main 함수
	교재 p157 ~ 158

	초기화의 실패 여부에 따라서 true 또는 false를 반환하도록 정의했기 때문에,
	함수를 호출한 영역에서 성공여부를 확인하고 그에 따른 조치를 취할 수 있다

	좌표정보를 프로그램 사용자로부터 입력 받는 예제였다면, 
	정상적인 좌표의 입력을 재 요청할 수도 있다
*/

#include <iostream>
#include "02_Point.h"
#include "04_Rectangle.h"

using namespace std;

int main(void)
{

	Point pos1;

	// 벗어난 범위의 값 전달
	// 초기화 실패
	if (!pos1.InitMembers(-2, 4)) cout << "초기화 실패" << endl;

	if (!pos1.InitMembers(2, 4)) cout << "초기화 실패" << endl;

	Point pos2;
	if (!pos2.InitMembers(5, 9)) cout << "초기화 실패" << endl;

	Rectangle rec;

	// 잘못된 위치정보 전달
	// 직사각형 초기화 실패
	if (!rec.InitMembers(pos2, pos1)) cout << "직사각형 초기화 실패" << endl;

	if (!rec.InitMembers(pos1, pos2)) cout << "직사각형 초기화 실패" << endl;

	//
	// 좌 상단: [2, 4]
	// 우 하단: [5, 9]
	rec.ShowRecInfo();
	return 0;
}