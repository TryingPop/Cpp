/*
날짜 : 2023. 2. 20
이름 : 배성훈
내용 : 교재 468p 문제1
	예제 StablePointPtrArray.cpp(교재 465p)의 65, 66행을 다음과 같이 구성할 수 있도록 
	Point 클래스를 대상으로 연산자 오버로딩을 진행해보자.

		for (int i = 0; i < arr.GetArrLen(); i++) {
			cout << arr[i];
		}

	물론, 실행결과에는 변함이 없도록 연산자를 오버로딩 해야한다.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y =0)
		: xpos(x), ypos(y) { }

	friend ostream& operator<<(ostream& os, const Point& pos);
	// 오버로딩
	friend ostream& operator<<(ostream& os, const Point* posPtr);
};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

ostream& operator<<(ostream& os, const Point* posPtr) {

	os << '[' << posPtr->xpos << ", " << posPtr->ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray {

private:
	POINT_PTR* arr;
	int arrlen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

public:
	BoundCheckPointPtrArray(int len)
		: arrlen(len) {

		arr = new POINT_PTR[len];
	}

	POINT_PTR& operator[](int idx) {

		if (idx < 0 || idx >= arrlen) {

			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	POINT_PTR operator[] (int idx) const {

		if (idx < 0 || idx >= arrlen) {

			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	int GetArrLen() const {

		return arrlen;
	}

	~BoundCheckPointPtrArray() {

		delete[] arr;
	}
};

int main(void)
{

	BoundCheckPointPtrArray arr(3);

	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++) {

		cout << arr[i];
	}

	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}