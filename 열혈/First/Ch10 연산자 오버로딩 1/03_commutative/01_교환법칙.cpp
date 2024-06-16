/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : 교환법칙
	연산자 오버로딩을 통해 서로 다른 자료형의 두 데이터간 연산을 가능하게 하고 있다
	기본적으로 연산에 사용되는 두 피연산자의 자료형은 일치해야 한다
	일치하지 않으면 형 변환의 규칙에 따라서 변환이 진행된 다음에 연산이 이루어져야한다

	문제 확인 예제
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

	Point operator*(int times) {

		Point pos(xpos * times, ypos * times);
		return pos;
	}
};

int main(void)
{

	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = pos * 3 * 2;
	cpy.ShowPosition();

	// cpy = 3 * pos;	// 컴파일 에러
	return 0;
}