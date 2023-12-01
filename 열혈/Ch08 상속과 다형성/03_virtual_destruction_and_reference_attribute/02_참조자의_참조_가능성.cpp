/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 참조자의 참조 가능성
	포인터처럼 참조자도 객체를 직접, 간접 상속하는 객체를 참조할 수 있다
*/

#include <iostream>
using namespace std;

class First {

public:
	void FirstFunc() {

		cout << "FirstFunc()" << endl;
	}

	virtual void SimpleFunc() {

		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First {

public:
	void SecondFunc() {
		
		cout << "SecondFunc()" << endl;
	}

	virtual void SimpleFunc() {

		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third : public Second {

public:
	void ThirdFunc() {

		cout << "ThirdFunc()" << endl;
	}

	virtual void SimpleFunc() {

		cout << "Third's SimpleFunc()" << endl;
	}
};

// First를 직간접적으로 상속하는 클래스의 객체가 인자의 대상이되는 구나라고 생각
// 그리고 인자로 전달되는 객체의 실제 자료형에 상관없이 함수 내에서는
// First 클래스에 정의된 함수만 호출 가능
void GoodFunc(First first) { }


int main(void)
{

	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();		// Third
	
	Second& sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	// sref.ThirdFunc();
	sref.SimpleFunc();		// Third

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();		// Third
}