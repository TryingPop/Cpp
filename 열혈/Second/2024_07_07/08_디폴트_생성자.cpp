/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : 디폴트 생성자
	교재 p184 ~ 

	메모리 공간의 할당 이후에 생성자의 호출까지 완료되어야 객체라 할 수 있다
	객체가 되기 위해서는 반드시 하나의 생성자가 호출되어야 한다

	이러한 기준에 예외를 두지 않기 위해서
	생성자를 정의하지 않는 클래스에는
	C++ 컴파일러에 의해서 디폴트 생성자가 자동으로 삽입된다

	디폴트 생성자는 인자를 받지 않으며, 내부적으로 아무런 일도 하지 않는 생성자이다
		class AAA
		{

		public:
			AAA() { }
		}
	와 같다

	이는 new 연산자를 이용한 객체의 생성에도 해당하는 이야기이다
	하지만 new 연산자가 아닌 malloc 함수를 대신 이용하면
	생성자는 호출되지 않는다

	malloc 함수호출 시, 클래스의 크기정보만 바이트 단위로 전달되기 때문에
	생성자가 호출될리 없다
	따라서 객체를 동적으로 할당하려는 경우에는 반드시 new 연산자를 이용해야 한다

	매개변수가 void 형으로 선언되는 디폴트 생성자는,
	생성자가 하나도 정의되어 있지 않을 때에만 삽입이 된다
*/

#include <iostream>

using namespace std;

class AAA
{

private:
	int num;

public:
	AAA() { }	// 디폴트 생성자와 같다
	int GetNum() { return num; }
};

class BBB
{

private:
	int num;

public:
	BBB(int n): num(n) { }
	int GetNum() { return num; }
};

int main(void)
{

	AAA a1;
	AAA* a2 = new AAA();

	// 생성자 불일치
	// BBB b1;				// 컴파일 에러
	// BBB* b2 = new BBB();	// 컴파일 에러
	BBB b3(123);

	cout << "a1: " << a1.GetNum() << endl;		// 쓰레기 값
	cout << "a2: " << (*a2).GetNum() << endl;	// 쓰레기 값
	cout << "b3: " << b3.GetNum() << endl;		// 123
	return 0;
}