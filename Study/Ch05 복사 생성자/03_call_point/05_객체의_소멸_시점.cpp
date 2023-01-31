/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 객체의 소멸 시점
	
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num;

public:
	SoSimple(int n)
		: num(n) { 

		cout << "New Object: " << this << endl;
	}

	SoSimple(const SoSimple& copy)
		: num(copy.num) { 

		cout << "New Copy obj: " << this << endl;
	}

	~SoSimple() {

		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {

	cout << "Param ADR: " << &ob << endl;
	return ob;	// 반환 값 생성 >> 인자 소멸 순서이다
}

int main(void) 
{

	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);	// 반환 값에 tempRef라는 이름을 붙인거 뿐
											// tempRef는 새로 생성되는게 아니다
	cout << "Return Obj" << &tempRef << endl;
	return 0;
}