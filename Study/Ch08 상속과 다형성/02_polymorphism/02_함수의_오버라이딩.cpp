/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 함수의 오버라이딩과 포인터형
	컴파일러는 포인터의 오버라이딩한 함수를 별도의 키워드 없이 호출한다고 가정하자
	이 경우, 포인터가 가리키는 클래스에 맞는 함수를 호출한다
*/

#include<iostream>
using namespace std;

class First {

public:
	void MyFunc() {

		cout << "FirstFunc" << endl;
	}
};

class Second : public First {

public:
	void MyFunc() {
		
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second {

public:
	void MyFunc() {

		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();	// First
	sptr->MyFunc();	// Second
	tptr->MyFunc();	// Third
	return 0;
}