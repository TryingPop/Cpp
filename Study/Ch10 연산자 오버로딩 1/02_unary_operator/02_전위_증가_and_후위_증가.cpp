/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : 전위 증가와 후위 증가의 구분
	전위 증가와 후위 증가 함수를 구분하는 방법

	인자에 int가 있는지 없는지로 구분한다
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

	// 전위 증가
	Point& operator++() {

		xpos += 1;
		ypos += 1;
		return *this;
	}

	// 후위 증가
	// const 반환에 참고!
	const Point operator++(int) {

		const Point retobj(xpos, ypos);	// const Point refobj(*this);
		xpos += 1;
		ypos += 1;
		return retobj;
	}

	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref) {

	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point& ref, int) {

	const Point retobj(ref);	// const 객체라 한다
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}

int main(void)
{

	Point pos(3, 5);
	Point cpy;

	cpy = pos--;
	cpy.ShowPosition();	// [3, 5]
	pos.ShowPosition();	// [2, 4]

	cpy = pos++;
	cpy.ShowPosition();	// [2, 4]
	pos.ShowPosition();	// [3, 5]

	// 이러한 결과를 반영한 정의이다
	int num = 0;
	++(++num);
	// (num++)++;	// 컴파일 에러
	
	return 0;
}