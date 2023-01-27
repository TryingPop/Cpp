/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자 예시
	Exam Ch03 01 의 01 연습문제에 적용

	소스파일 : 메인함수
*/

#include <iostream>
#include "04_Point.h"
#include "06_Rectangle.h"
using namespace std;

int main(void)
{

	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();
	return 0;
}