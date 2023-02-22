/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 클래스 템플릿의 멤버함수의 정의
	외부에서 멤버함수 정의하는 예제
*/

#include <iostream>
using namespace std;

template<typename T>
class Point {

private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

template<typename T>
Point<T>::Point(T x, T y)
	: xpos(x), ypos(y) { }

template<typename T>
void Point<T>::ShowPosition() const {

	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

int main(void)
{

	Point<int> pos1(3, 4);
	pos1.ShowPosition();			// [3, 4]

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();			// [2.4, 3.6]

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();			// [P, F]
	return 0;
}