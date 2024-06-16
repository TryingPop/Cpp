/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : 교환법칙
	교환법칙의 적용

	교환법칙이 적용되기 하려면 
	전역함수로 정의하는 방법 밖에 없다
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

	friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref) {
	
	return ref * times;
	// 다음과 같이 정의해도 된다
	// Point pos(ref.xpos * times, ref.ypos * times);
	// return pos;
}

int main(void)
{

	Point pos(1, 2);
	Point cpy;

	cpy = 3 * pos;
	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();
	return 0;
}