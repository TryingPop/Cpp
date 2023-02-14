/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : 교재 436p 문제1
	예제 PointConsoleOutput.cpp(교재 435p)에서 정의한 Point 클래스를 대상으로 
	아래의 main 함수가 보이는 대로 데이터의 입력이 가능하도록,
	그리고 실행의 예에서 보이는 대로 출력이 이루어지도록 >> 연산자를 오버로딩 하자.

	[main 함수]
	int main(void)
	{
		
		Point pos1;
		cout << "x, y 좌표 순으로 입력: ";
		cin >> pos1;
		cout << pos1;

		Point pos2;
		cout << "x, y 좌표 순으로 입력: ";
		cin >> pos2;
		cout << pos2;
		return 0;
	}
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);

};

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos) {

	is >> pos.xpos >> pos.ypos;
	return is;
}

int main(void)
{

	Point pos1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos2;
	cout << pos2;
	return 0;
}