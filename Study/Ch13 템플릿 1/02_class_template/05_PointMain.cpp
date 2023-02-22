/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 클래스 템플릿
	코드파일 : Main 함수 정의

	교재 546 ~ 547p 내용 참고
*/

#include <iostream>
#include "03_PointTemplate.h"
// 아래 구문 없으면 컴파일 에러 뜬다
// 컴파일에서 Point<int>, Point<double>, Point<char> 클래스를 생성
// 이를 위해서는 04_PointTemplate.cpp 의 정보를 참조할 수 있어야한다
// Main을 컴파일할 때 04도 컴파일 하니깐 04에 담긴 내용도 알고 있는거 아니냐는 생각을 할 수 있다.
// 동시에 컴파일 되는건 맞으나 이들은 서로 다른 소스파일에 있어서
// 컴파일 파일 원칙에 의해서 Main을 컴파일하면서 04를 참조를 하지 않고
// 또한 04를 컴파일하면서 Main을 참조하지 않는다
// 따라서 컴파일 에러가 발생한다
#include "04_PointTemplate.cpp"

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