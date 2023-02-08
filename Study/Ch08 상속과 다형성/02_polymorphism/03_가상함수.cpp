/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 가상함수
	virtual 키워드

*/

#include<iostream>
using namespace std;

class First {

public:
	virtual void MyFunc1() {

		cout << "FirstFunc1" << endl;
	}

	virtual void MyFunc2() {

		cout << "FirstFunc2" << endl;
	}

	void MyFunc3() {

		cout << "FirstFunc3" << endl;
	}
};

class Second : public First {

public:
	virtual void MyFunc1() {

		cout << "SecondFunc1" << endl;
	}

	void MyFunc2() {

		cout << "SecondFunc2" << endl;
	}

	virtual void MyFunc3() {

		cout << "SecondFunc3" << endl;
	}
};

class Third : public Second {

public:
	virtual void MyFunc1() {

		cout << "ThirdFunc1" << endl;
	}

	void MyFunc2() {

		cout << "ThirdFunc2" << endl;
	}

	void MyFunc3() {

		cout << "ThirdFunc3" << endl;
	}
};

int main(void)
{

	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	cout << "MyFunc1 start" << endl;
	fptr->MyFunc1();	// Third
	sptr->MyFunc1();	// Third
	tptr->MyFunc1();	// Third
	cout << "MyFunc1 end" << endl << endl;

	cout << "MyFunc2 start" << endl;
	fptr->MyFunc2();	// Third
	sptr->MyFunc2();	// Third
	tptr->MyFunc2();	// Third
	cout << "MyFunc2 end" << endl << endl;

	cout << "MyFunc3 start" << endl;
	fptr->MyFunc3();	// First
	sptr->MyFunc3();	// Third
	tptr->MyFunc3();	// Third
	cout << "MyFunc3 end" << endl << endl;
	return 0;
}