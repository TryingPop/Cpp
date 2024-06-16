/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 대입 연산자
	디폴트 대입 연산자의 문제점
	
	멤버 대 멤버의 복사가 이뤄지는 것을 보면서 C언어 구조체 변수간 대입연산의 결과와 비슷하다고 생각하기 쉽다
	그러나 객체간의 대입연산은 C언어의 구조체 변수간의 대입연산과 본질적으로 다르다
	이는 단순한 대입연산이 아닌, 대입연산자를 오버로딩 한 함수의 호출이기 때문이다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {

private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage) {

		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const {

		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	/*
	// 다음과 같이 정의
	Person& operator=(Person& ref) {

		delete[] name;	// 없으면 이전 name에 접근할 수 없어 
						// 메모리 누수가 발생
		int lne = strlen(ref.name) + 1;
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
	*/

	~Person() {

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{

	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);

	man2 = man1;

	// 서로 같은 결과 반환
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}
// 다만 소멸자는 1번만 호출되고 vs에서 컴파일 에러 발생