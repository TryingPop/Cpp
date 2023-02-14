/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : 교재 409p 문제1
	연산자 오버로딩을 이해하는 가장 좋은 방법은 연산자를 직접 오버로딩 해 보는 것이다.
	연산자를 오버로딩 하는 과정에서 자신이 이해하지 못한 부분이 드러나면서,
	그 부분을 이해하게 되는 경우가 많기 때문이다.
	따라서 앞서 예제 GFuncionOverloading.cpp(교재 407p)에서 보인 Point 클래스를 대상으로
	아래의 요구대로 연산자를 오버로딩 해보자.

	Point 클래스에 대해서 다음 조건을 만족하는 형태로 - 연산자를 오버로딩해보자
		전역함수 기반으로 오버로딩
		멤버 별 - 연산의 결과를 담은 Point 객체의 반환
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

	friend Point& operator-(Point&, Point&);
};

Point& operator-(Point& pos1, Point& pos2) {

	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

int main(void) 
{

	Point pos1(1, 2);
	Point pos2(3, 5);

	Point cpy;
	cpy = pos1 - pos2;
	cpy.ShowPosition();
	return 0;
}