/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 클래스 템플릿
	코드파일 : Main 함수 정의
*/

#include <iostream>
#include "03_PointTemplate.h"
using namespace std;

int main(void) 
{

	Point<int> pos1(3, 4);
	pos1.ShowPosition();		// [3, 4]

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();		// [2.4, 3.6]

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();		// [P, F]

	return 0;
}