/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 배열 클래스
	객체 저장을 위한 배열 클래스의 정의
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class BoundCheckPointArray {

private:
	Point* arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }

public:
	BoundCheckPointArray(int len)
		: arrlen(len) {

		arr = new Point[len];
	}

	Point& operator[](int idx) {

		if (idx < 0 || idx >= arrlen) {

			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	Point operator[](int idx) const {

		if (idx < 0 || idx >= arrlen) {

			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	int GetArrLen() const {

		return arrlen;
	}

	~BoundCheckPointArray() {

		delete[] arr;
	}
};

int main(void)
{
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++) {

		cout << arr[i];
	}
	return 0;
}