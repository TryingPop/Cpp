/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : dynamic_cast
	Polymorphic 클래스 기반의 형 변환
		상속관계에 놓여있는 두 클래스 사이에서,
		유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환할 경우에는 
		dynamic_cast 연산자를 사용한다

		반대로 상속관계에 놓여있는 두 클래스 사이에서,
		기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형 데이터로 형 변환할 경우에는 
		static_ast 연산자를 사용한다

		만약 기초 클래스가 Polymorphic 클래스이면,
		dynamic_cast 연산자도 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형으로의
		형 변환을 허용한다

		여기서 Polymorphic 클래스란 하나 이상의 가상함수를 지니는 클래스를 뜻한다.
*/

#include<iostream>
using namespace std;

class SoSimple {	// Polymorphic 클래스
					// ShowSimpleInfo가 가상함수 이므로

public:
	virtual void ShowSimpleInfo() {	// virtual로 선언하지 않았을 때 컴파일 에러 발생

		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple {	

public:
	void SowSimpleInfo() {	// 이거 역시 가상함수

		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{

	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	return 0;
}

