/*
날짜 : 2023. 2. 16
이름 : 배성훈
내용 : () 연산자
	함수의 호출에 사용되는, 인자의 전달에 사용되는 ()도 연산자이다
	이 연산자를 오버로딩 하면 객체를 함수처럼 이용할 수 있다

	객체를 함수처럼 사용하는 예제를 알아보자
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	Point operator+(const Point& pos) const {

		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

/// <summary>
/// 이와 같은 클래스를 가리켜 
/// 펑터(Functor) 혹은 함수 오브젝트(Function Object)라고 불린다
/// </summary>
class Adder {

public:
	int operator()(const int& n1, const int& n2) {

		return n1 + n2;
	}

	double operator()(const double& e1, const double& e2) {

		return e1 + e2;
	}

	Point operator()(const Point& pos1, const Point& pos2) {

		return pos1 + pos2;
	}
};

int main(void) 
{

	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9));
	return 0;
}