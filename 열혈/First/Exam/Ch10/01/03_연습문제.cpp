/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : 교재 410p 문제3
	Point 클래스에 대해서 다음 조건을 만족하는 형태로 == 연산자와 != 연산자를 오버로딩 해보자.
		둘 다 전역함수의 형태로 오버로딩
		연산 'pos1 == pos2'의 결과로 모든 멤버의 값이 같다면 true, 그렇지 않다면 false 반환
		연산 'pos1 != pos2'의 결과로 모든 멤버의 값이 같다면 false, 그렇지 않다면 true 반환
		연산자 ==를 먼저 오버로딩 한 다음에, 이를 이용하는 형태로 != 연산자를 오버로딩

	참고로 총 3문제이지만 하나의 답안에 이 모두를 담아도 된다.
	정답지 역시 그러한 형태로 답안을 제시
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

	friend bool operator==(Point&, Point&);
	friend bool operator!=(Point&, Point&);
};

bool operator==(Point& pos1, Point& pos2) {

	if (pos1.xpos != pos2.xpos) {

		return false;
	}

	if (pos1.ypos != pos2.ypos) {

		return false;
	}

	return true;
}

bool operator!=(Point& pos1, Point& pos2) {

	return !(pos1 == pos2);
}

int main(void)
{

	Point pos1(1, 2);
	Point pos2(3, 4);
	Point pos3(1, 2);

	cout << "pos1 == pos3 : ";

	if (pos1 == pos3) {

		cout << "true" << endl;
	}
	else {

		cout << "false" << endl;
	}

	cout << "pos1 != pos2 : ";

	if (pos1 != pos2) {

		cout << "true" << endl;
	}
	else {

		cout << "false" << endl;
	}
	
	return 0;
}