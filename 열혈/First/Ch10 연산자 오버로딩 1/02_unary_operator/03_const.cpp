/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : 후위 증가에서의 const
	후위 증가에서의 const
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

	// 반환하는 객체를 const 객체로 하겠다는 의미
	// 즉 const 함수의 호출만 허용
	const Point operator++(int) {

		const Point retobj(*this);	// 이 함수 내에서 retobj 의 값변환을 허용 X
									
		xpos++;
		ypos++;
		return retobj;	// 객체가 새로 생성되기에 const Point reobj의 const 선언은 반환형에 아무런 영향 X
	}
};

int main(void)
{

	Point pos1(1, 2);
	Point cpy;
	
	cpy = pos1++;
	cpy.ShowPosition();	// [1, 2]

	cpy++;
	cpy.ShowPosition();	// [2, 3]


	const Point pos2(3, 4);
	// Point& ref1 = pos2;	// 컴파일 에러

	const Point& ref2 = pos2;
	// pos2++; // 컴파일 에러
	// (pos1++)++;	// 같은 이유로 컴파일 에러
	return 0;
}