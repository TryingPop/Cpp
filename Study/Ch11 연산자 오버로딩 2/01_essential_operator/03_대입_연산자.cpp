/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 대입 연산자
	상속에서의 대입 연산자

	유도 클래스에서 대입 연산자에는 아무런 명시를 하지 않으면,
	기초 클래스의 대입 연산자가 호출되지 않는다
	그래서 기초 클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외된다
*/

#include <iostream>
using namespace std;

class First {

private:
	int num1, num2;

public:
	First(int n1 = 0, int n2 = 0)
		: num1(n1), num2(n2) { }

	void ShowData() const {

		cout << num1 << ", " << num2 << endl;
	}

	First& operator=(const First& ref) {

		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First {

private:
	int num3, num4;

public:
	Second(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
		: First(n1, n2), num3(n3), num4(n4) { }

	void ShowData() const {

		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}

	/*
	// 만약 주석을 해제하면 Second에서 =연산 시 얘가 호출된다
	// 이경우 scpy.ShowData()에서 다음과 같이 호출된다
	// Second operator=()
	// 0, 0
	// 333, 444
	Second& operator=(const Second& ref) {

		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	*/
};

int main(void)
{

	Second ssrc(111, 222, 333, 444);
	Second scpy;

	scpy = ssrc;
	scpy.ShowData();	// First& operator=()
						// 111, 222
						// 333, 444
	
	// 따로 First& operator=()나 Second operator=() 문구가 없다
	// First fcpy = ssrc;	// 111, 222
	// fcpy.ShowData();

	return 0;
}