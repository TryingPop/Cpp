/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : polymorphic
	dynamic_cast는 안정적인 형 변환을 보장한다
	컴파일 시간이 아닌 실행 시간에 안정성을 검사하도록 컴파일러가 바이너리 코드를 생성한다
	이로 인해 실행 속도는 느려진다

	반면 static_cast는 무조건 형 변환이 되도록 바이너리 코드를 생성하기 때문에
	이 연산자는 안전성을 보장하지 않는다
	다만 실행 속도는 빠르다

	앞의 예제에서 simPtr이 SoComplex를 가리키기 때문에 가능했지만
	이번에는 SoSimple을 가리키는 경우에 대한 예제
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

	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);

	if (comPtr == NULL) {

		cout << "형 변환 실패" << endl;		// 출력
	}
	else {

		comPtr->ShowSimpleInfo();
	}
	return 0;
}
