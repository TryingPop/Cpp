/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : 교재 418p 문제1
	예제 OneOpndOverloading.cpp(교재 414p)에서 보인 
	Point 클래스를 대상으로 아래의 요구대로 연산자를 오버로딩 해보자.

	부호 연산자로서 -는 단항 연산자이다.
	이 연산자는 피연산자의 부호를 반전시킨 결과를 반환한다.
	예를들어 다음 문장이 실행되면,
		int num2 = -num1;

	num2에는 num1과 절대값은 같지만 부호가 다른 값이 저장된다.
	물론 num1의 값에는 영향을 미치지 않는다.
	이와 유사하게 Point 클래스를 대상으로 - 연산자를 오버로딩 해보자.
	다음의 문장이 실행되면,
		Point pos2 = -pos1;

	pos2의 멤버변수는 pos1의 멤버변수 값과 다른 부호의 값으로 초기화되도록 오버로딩 해보자.
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

	friend Point& operator-(const Point&);
};

Point& operator-(const Point& ref) {

	Point pos(-ref.xpos, -ref.ypos);
	return pos;
}

int main(void)
{

	Point pos1(2, 3);
	Point pos2 = -pos1;

	pos2.ShowPosition();
	return 0;
}