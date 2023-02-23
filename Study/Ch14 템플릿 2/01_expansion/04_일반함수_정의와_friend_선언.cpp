/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 확장된 템플릿
	특정 템플릿 클래스의 객체를 인자로 받는 일반함수의 정의와 friend 선언
*/

#include <iostream>
using namespace std;

template<typename T>
class Point {

private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0)
		: xpos(x), ypos(y) { }

	void ShowPOsition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

// 연산자 +를 오버로딩 하는 일반함수
Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2) {

	return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

// 연산자 <<를 오버로딩 하는 인반함수
ostream& operator<<(ostream& os, const Point<int>& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{

	Point<int> pos1(2, 4);
	Point<int> pos2(4, 8);
	Point<int> pos3 = pos1 + pos2;
	cout << pos1 << pos2 << pos3;
	return 0;
}