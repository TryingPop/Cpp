/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : 교재 95p 문제1
	구조체에 대한 복습을 겸할 수 있는 문제를 제시하겠다.
	2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 다음과 같이 정의하였다.
	typedef struct __Point{

		int xpos;
		int ypos;
	} Point;

	위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고(덧셈결과는 함수의 반환을 통해서 얻게한다),
		Point& PntAdder(const Point &p1, const Point &p2);

	임의의 두 점을 선언하여, 위 함수를 이용한 덧셈 연산을 진행하는 main 함수를 정의해보자.
	단, 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며,
	할당된 메모리 공간의 소멸도 철저해야 한다. 참고로 이 문제의 해결을 위해서는 다음 두 질문에 답을 할 수 있어야 한다.
		1. 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
		2. 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?
*/

#include <iostream>
using namespace std;

typedef struct __Point {

	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main(void)
{

	// 기존에 struct 선언 방법
	// Point p1 = { 1, 1 };
	// Point p2 = { 2, 2 };
	
	// new를 이용해 Point 선언 및 변수 설정
	// new의 봔환 값이 해당 형태의 ptr이므로 앞에 *를 붙여 Point를 가르키게 한다
	Point* ptrPnt1 = new Point{ -2, 0 };	// xpos = -2, ypos = 0
	Point* ptrPnt2 = new Point{ 1, 1 };		// xpos = 1, ypos = 1 
	
	Point &p3 = PntAdder(*ptrPnt1, *ptrPnt2);

	cout << "p3.xpos : " << p3.xpos << endl;
	cout << "p3.ypos : " << p3.ypos << endl;

	// 메모리 해제
	delete ptrPnt1;
	delete ptrPnt2;
	delete &p3;

	return 0;
}

Point& PntAdder(const Point& p1, const Point& p2) {

	// malloc으로 addPnt 정의
	// Point* addPnt = (Point*)malloc(sizeof(Point) * 1);

	// 문제 조건에 맞게 addPnt정의
	Point* addPnt = new Point;

	// 변수 수정하는 방법
	addPnt->xpos = p1.xpos + p2.xpos;
	addPnt->ypos = p1.ypos + p2.ypos;

	return *addPnt;
}