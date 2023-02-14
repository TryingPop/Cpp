/*
날짜 : 2023. 2. 14
이름 : 배성훈
내용 : 교재 409p 문제1, 2, 3
	연산자 오버로딩을 이해하는 가장 좋은 방법은 연산자를 직접 오버로딩 해 보는 것이다.
	연산자를 오버로딩 하는 과정에서 자신이 이해하지 못한 부분이 드러나면서,
	그 부분을 이해하게 되는 경우가 많기 때문이다.
	따라서 앞서 예제 GFuncionOverloading.cpp(교재 407p)에서 보인 Point 클래스를 대상으로
	아래의 요구대로 연산자를 오버로딩 해보자.
	Point 클래스에 대해서 다음 조건을 만족하는 형태로 - 연산자를 오버로딩해보자
		전역함수 기반으로 오버로딩
		멤버 별 - 연산의 결과를 담은 Point 객체의 반환

		Point 클래스에 대해서 다음 조건을 만족하는 형태로 += 연산자와 -= 연산자를 오버로딩 해보자
		멤버함수 기반으로 오버로딩
		연산 'pos1 += pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 증가
		연산 'pos1 -= pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 감소
		연산의 결과로 값이 증가 및 감소한 pos1의 객체를 반환하도록(이왕이면 참조형으로 반환하도록) 연산자 오버로딩

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

	Point& operator+=(const Point& ref) {

		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}

	Point& operator-=(const Point& ref) {

		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	friend Point operator-(const Point&, const Point&);
	friend bool operator==(const Point&, const Point&);
	friend bool operator!=(const Point&, const Point&);
};

Point operator-(const Point& pos1, const Point& pos2) {

	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2) {

	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) {

		return true;
	}

	return false;
}

bool operator!=(const Point& pos1, const Point& pos2) {

	return !(pos1 == pos2);		// 오버로딩 된 == 연산자를 호출하고 있다.
}

int main(void)
{

	Point pos1(20, 30);
	Point pos2(5, 7);
	Point pos3(5, 7);

	(pos1 - pos2).ShowPosition();	// 객체를 반환하므로 함수호출 가능
	(pos1 += pos3).ShowPosition();	// 반환형이 참조형이므로 함수호출 가능

	if (pos2 == pos3) {

		cout << "equal" << endl;
	}
	else {

		cout << "not equal" << endl;
	}

	(pos2 -= pos3).ShowPosition();	// 반환형이 참조형이므로 함수호출 가능

	if (pos2 != pos3) {

		cout << "not equal" << endl;
	}
	else {

		cout << "equal" << endl;
	}

	return 0;
}