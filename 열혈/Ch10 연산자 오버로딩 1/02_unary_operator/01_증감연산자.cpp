/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : 증감 연산자
	++, -- 연산자
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

	Point& operator++() {

		xpos += 1;
		ypos += 1;
		return *this;	// this 는 객체자신의 포인터 값이라 *this
	}

	friend Point& operator--(Point& ref);
};

Point& operator--(Point& ref) {

	ref.xpos -= 1;
	ref.ypos -= 1;
	
	return ref;
}

int main(void) 
{
	
	Point pos(1, 2);
	++pos;	
	pos.ShowPosition();	// 2, 3
	--pos;
	pos.ShowPosition();	// 1, 2

	// pos++;	// 정의 안되었다고 컴파일 에러 뜬다
	++(++pos);	// ++(pos.operator++()) 와 같다
	pos.ShowPosition();	// 3, 4
	--(--pos);	// --(operator--(pos)) 와 같다
	pos.ShowPosition();	// 1, 2
	
	int num = 0;
	cout << num++ << endl;	// 0
	cout << ++num << endl;	// 2
	return 0;
}