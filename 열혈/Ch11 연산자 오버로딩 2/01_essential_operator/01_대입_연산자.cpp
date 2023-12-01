/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 대입 연산자
	복사생성자
		정의하지 않으면 디폴트 복사 생성자가 삽입된다
		디폴트 복사 생성자는 멤버 대 멤버의 복사(얕은 복사)를 진행한다
		생성자 내에서 동적 할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의해야한다

	대입 연산자
		정의하지 않으면 디폴트 대입 연산자가 삽입된다
		디폴트 대입 연산자는 멤버 대 멤버의 복사(얕은 복사)를 진행한다
		연사자 내에서 동적 할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의해야 한다

	복사 생성자와 유사한 대입 연산자의 예제
*/

#include <iostream>
using namespace std;

class First {

private:
	int num1, num2;

public:
	First(int n1 = 0, int n2 = 0)
		: num1(n1), num2(n2) { }

	void ShowData() {

		cout << num1 << ", " << num2 << endl;
	}
};

class Second {

private:
	int num3, num4;

public:
	Second(int n3 = 0, int n4 = 0)
		: num3(n3), num4(n4) { }

	void ShowData() {

		cout << num3 << ", " << num4 << endl;
	} 

	Second& operator=(const Second& ref) {

		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)
{

	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;

	fcpy = fsrc;
	scpy = ssrc;

	fcpy.ShowData();	// 111, 222
	scpy.ShowData();	// 333, 444

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;	// Second& operator=()
						// Second& operator=()

	fob1.ShowData();	// 111, 222
	fob2.ShowData();	// 111, 222
	sob1.ShowData();	// 333, 444
	sob2.ShowData();	// 333, 444
	return 0;
}