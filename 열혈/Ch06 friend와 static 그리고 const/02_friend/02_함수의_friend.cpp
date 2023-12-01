/*
날짜 : 2023. 2. 2
이름 : 배성훈
내용 : 함수의 friend 선언
	전역 함수를 대상으로도, 클래스의 멤버함수를 대상으로도 frined 선언 가능


*/

#include <iostream>
using namespace std;

class Point;		// Point가 클래스임을 선언

class PointOP {

private:
	int opcnt;

public:
	PointOP() 
		: opcnt(0) { }

	Point PointAdd(const Point&, const Point&);
	Point PointSub(const Point&, const Point&);

	~PointOP() {

		cout << "Operation times: " << opcnt << endl;
	}
};

class Test {

private:
	int num;
};

class Point {

private:
	int x;
	int y;

public:
	Point(const int& xpos, const int& ypos)
		: x(xpos), y(ypos) { }

	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);	// friend 선언 이외에 함수의 선언도 
	friend void Num(const Test&);			// 포함되어 있어서 별도로 함수 선언할 필요 X
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {

	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {

	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main(void) 
{

	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	return 0;
}

void ShowPointPos(const Point& pos) {

	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
}

void Num(const Test& test) {

	// test.num;	// test의 num 멤버 변수에 접근 불가능
}