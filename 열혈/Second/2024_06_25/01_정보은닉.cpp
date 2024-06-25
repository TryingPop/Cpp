/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : 정보은닉
	교재 p150 ~ 153

	객체의 생성을 목적으로 클래스를 디자인한다
	좋은 클래스가 되기 위한 최소한의 조건은 정보은닉과 캡슐화가 있다

	아래 예제를 보자,
	Point의 값을 0이상 100이하가 되게 잡고
	upLeft의 x값은 lowRight의 x값보다 작거나 같아야한다
	그리고 upLeft의 y값은 lowRight의 y값보다 작거나 같아야한다

	그런데 프로그래머가 실수를 했을 때,
	어떻게든 발견이 되어야하는데

	문법적으로는 문제가 없기 때문에 컴파일러는 위의 코드를 문제 삼지 않는다
	때문에 제한된 방법으로의 접근만 허용을 해서 잘못된 값이 저장되지 않도록 도와야 하고,
	또 실수를 했을 때 쉽게 발견되도록 해야한다
*/

#include <iostream>

using namespace std;

class Point
{

public:
	int x;
	int y;
};

class Rectangle
{

public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{

		cout << "좌 상단: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "우 하단: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl;
	}
};

int main(void)
{

	// public 선언을 해서 외부에서 초기화가 가능
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2, pos1 };
	rec.ShowRecInfo();
	return 0;
}