/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 다형성
	Polymorphism
		가상함수의 호출 관계에서 보인 특성을 다형성 즉 동질이상
		모습은 같은데 결과는 다르다
		객체지향을 설명하는데 있어서 매우 중요한 요소
*/

#include <iostream>
using namespace std;

class First {

public:
	virtual void SimpleFunc() {

		cout << "First" << endl;
	}
};

class Second : public First {

public:
	virtual void SimpleFunc() {

		cout << "Second" << endl;
	}
};

int main(void) 
{

	First* ptr = new First();
	ptr->SimpleFunc();	// First
	delete ptr;	

	ptr = new Second();
	// 위와 동일하나 다른 결과를 낸다
	ptr->SimpleFunc();	// Second
	delete ptr;	
	return 0;
}