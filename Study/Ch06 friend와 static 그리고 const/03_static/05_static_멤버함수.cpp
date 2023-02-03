/*
날짜 : 2023. 2. 3
이름 : 배성훈
내용 : static 멤버함수
	선언된 클래스의 모든 객체가 공유한다
	public으로 선언되면, 클래스의 이름을 이용해서 호출이 가능하다
	객체의 멤버로 존재하는 것이 아니다

	static 멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다

	static 멤버변수와 static 멤버함수는 대부분의 경우에 있어서 전역변수와 전역함수를 대체할 수 있다
*/

class SoSimple {

private:
	int num1;
	static int num2;

public:
	SoSimple(int n)
		: num1(n) { }

	static void Adder(int n) {

		// num1 += n;	// num1은 static 멤버 변수가 아니라서 에러
		num2 += n;
	}
};

int SoSimple::num2 = 0;

