/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 배열 클래스
	주소 값을 저장하는 방식을 보다 많이 사용한다

	new랑 delete를 사용해 신경쓸게 많아 보이지만
	얕은 복사 깊은 복사를 신경안써도 되는 장점이 있다
*/

#include<iostream>
#include<cstdlib>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) 
		: xpos(x), ypos(y) { }

	friend ostream& operator<<(ostream& os, Point& pos);
};

ostream& operator<<(ostream& os, Point& pos) {

	cout << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
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

	POINT_PTR& operator[] (int idx) {

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

		cout << *(arr[i]);
	}

	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}