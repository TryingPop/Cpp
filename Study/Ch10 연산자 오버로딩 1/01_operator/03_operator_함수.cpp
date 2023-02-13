/*
날짜 : 2023. 2. 13
이름 : 배성훈
내용 : operator 함수
	사용 시 주의점
		멤버 접근 연산자 .
		멤버 포인터 연산자 .*
		범위 지정 연산자 ::
		조건 연산자(3항 연산자) ?:
		바이트 단위 크기 계산 sizeof
		RTTI관련 연산자 typeid
		형변환 연산자 static_cast
		형변환 연산자 dynamic_cast
		형변환 연산자 const_cast
		형변환 연산자 reinterpret_cast

	C++ 의 문법 규칙을 보존하기 위해서 이들 연산자에 대해서 operator 함수를 이용할 수 없다
	
	멤버 함수 기반으로 가능한 연산자
		대입연산자 =
		함수 호출 연산자 ()
		배열 접근 연산자(인덱스 연산자) []
		멤버 접근을 위한 포인터 연산자 ->

	이들은 객체를 대상으로 진행해야 의미가 통하는 연산자들이기 때문에,
	멤버 함수 기반으로만 연산자의 오버로딩을 허용한다

	이외에도 주의할 점은
		연산자의 우선순위와 결합성은 바뀌지 않는다
		매개변수의 디폴트 값 설정이 불가능하다

	위에서 언급하지 않은 나머지 주의할 점들을 예제로 보자
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public :
	Point(int x = 0, int y = 0) 
		: xpos(x), ypos(y) { }

	void ShowPosition() const {

		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// 본래 자주 사용되지 않는 형태는 지양
	void operator+(const Point& ref) {

		xpos += ref.xpos;
		ypos += ref.ypos;
	}
};

/*
// 연산자의 순수 기능까지 빼앗을 수 없다
// 연산자의 기본 기능을 변경하는 형태의 연산자 오버로딩은 허용되지 않는다
int operator+(const int num1, const int num2) {

	return num1 * num2;
}
*/

int main(void)
{
	
	Point pos1(1, 2);
	Point pos2(3, 4);

	pos1 + pos2;

	pos1.ShowPosition();	// [4, 6]
	pos2.ShowPosition();	// [3, 4]
	return 0;
}