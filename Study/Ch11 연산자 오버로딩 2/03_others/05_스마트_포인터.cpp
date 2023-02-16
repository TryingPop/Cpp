/*
날짜 : 2023. 2. 16
이름 : 배성훈
내용 : 스마트 포인터
	스마트 포인터는 포인터처럼 동작하는 객체이다

	스마트 포인터를 직접 구현해보자

	아래 예제에서는 delete 연산이 자동으로 이루어 진다
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { 
		
		cout << "Point 객체 생성" << endl;
	}

	~Point() {

		cout << "Point 객체 소멸" << endl;
	}

	void SetPos(int x, int y) {

		xpos = x;
		ypos = y;
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr {

private:
	Point* posptr;

public:
	SmartPtr(Point* ptr)
		: posptr(ptr) { }

	Point& operator*() const {

		return *posptr;
	}
	
	Point* operator->() const {

		return posptr;
	}
	
	~SmartPtr() {

		delete posptr;	// 동적할당 하지 않았는데도 delete 연산이 포함
						// 스마트 포인터는 new를 이용해 동적 할당된 객체의 주소 값
						// 이라는 가정이 포함되어 있다
	}
};

int main(void)
{

	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(3, 4));
	SmartPtr sptr3(new Point(4, 5));

	cout << *sptr1;	// 객체의 멤버 변수에 접근
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(40, 50);

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
}