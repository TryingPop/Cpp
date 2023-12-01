/*
날짜 : 2023. 2. 10
이름 : 배성훈
내용 : 가상함수의 동작원리와 가상함수 테이블
	C++이 C보다 느린 이유를 알 수 있다
	가상함수를 설명하기 위한 예제

	가상함수가 포함되면 가상함수 테이블을 참조해 호출될 함수가 결정되기 때문에
	C++이 C보다 극히 미미하게 나마 느릴 수 밖에 없다
*/

#include <iostream>
using namespace std;

class AAA {

private:
	int num1;
	
public:
	// 선언하면 가상함수를 포함하는 클래스에 대해 
	// 메소드의 이름을 키로 주소를 값으로 갖는 가상함수 테이블을 생성한다
	virtual void Func1() {

		cout << "Func1" << endl;
	}

	virtual void Func2() {

		cout << "Func2" << endl;
	}
};

class BBB : public AAA {

private:
	int num2;

public:
	// AAA와 마찬가지로 가상함수 테이블 생성
	// 그러나 AAA 클래스의 오버라이딩 된 가상함수 Func1에 대한 정보가 존재하지 않는다
	virtual void Func1() {

		cout << "BBB::Func1" << endl;
	}

	void Func3() {

		cout << "Func3" << endl;
	}
};

int main(void)
{

	AAA* aptr = new AAA();
	aptr->Func1();

	BBB* bptr = new BBB();
	bptr->Func1();
	return 0;
}