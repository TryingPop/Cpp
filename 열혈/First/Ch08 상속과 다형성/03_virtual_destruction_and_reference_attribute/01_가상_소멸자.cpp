/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 가상 소멸자
	Virtual Destructor
		소멸자 앞에 virtual를 넣으면 된다
		virtual ~클래스명() { 실행코드 }

*/

#include <iostream>
using namespace std;

class First {

private:
	char* strOne;

public:
	First(const char* str) {

		strOne = new char[strlen(str) + 1];
	}

	~First() {

		cout << "~First()" << endl;
		delete[] strOne;
	}
};

class Second : public First {

private:
	char* strTwo;

public:
	Second(const char* str1, const char* str2)
		: First(str1) {

		strTwo = new char[strlen(str2) + 1];
	}

	// 가상 소멸자 선언
	virtual ~Second() {

		cout << "~Second()" << endl;
		delete[] strTwo;
	}
};

class Third :public Second {

private:
	char* strThird;

public:
	Third(const char* str1, const char* str2, const char* str3)
		: Second(str1, str2) {

		strThird = new char[strlen(str3) + 1];
	}

	~Third() {

		cout << "~Third()" << endl;
		delete[] strThird;
	}
};

int main(void) 
{

	Second* ptr1 = new Third("1", "2", "3");
	delete ptr1;	// Third, Second, First 순으로 호출

	First* ptr2 = new Third("First", "Second", "Third");
	delete ptr2;	// First만 호출 된다 메모리 누수 발생
					// vs에서는 힙 영역에 접근할 수 없는 메모리 있다고 컴파일 에러를 불러일으킨다
	return 0;
}