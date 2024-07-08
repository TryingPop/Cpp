/*
날짜 : 2024. 7. 8
이름 : 배성훈
내용 : 객체 배열
	교재 p191 ~ 194

	C언어에서 구조체 배열을 선언해본적이 있다
	마찬가지로 구조체 포인터 배열도 선언해본적 있다

	객체 배열 및 객체 포인터 배열은 이와 유사하다

	(클래스 명)*  (배열 변수 이름) = new (클래스명)[(배열의 길이)];
	형태로 선언가능하다
	
	구조체 배열의 선언과 차이가 없다
	위처럼 객체 배열을 선언하는 경우에도 생성자는 호출된다
	단, 배열의 선언과정에서는 호출할 생성자를 별도로 명시하지 못한다
	(생성자에 인자를 전달하지 못한다)

	그래서 반드시 void형 생성자가 정의되어 있어야 한다
		(클래스 명)() { ... }
	형태의 생성자가 정의되어야 한다

	원하는 값으로 초기화 한다면
	일일이 초기화의 과정을 별도로 거쳐야 한다

	아래 예제를 실행해보면
	객체 배열 생성 시 void형 생성자가 호출됨을 확인할 수 있다
	그리고 배열 소멸시에도 그 배열을 구성하는 객체의 소멸자가 호출됨을 확인할 수 있다
*/

#include <iostream>
#include <cstring>

using namespace std;

class Person
{

private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)
	{

		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}

	Person()
	{

		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage)
	{

		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{

		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}

	~Person() 
	{

		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{

	Person parr[3];
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{

		cout << "이름: ";
		cin >> namestr;

		cout << "나이: ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];

		strcpy_s(strptr, len, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();

	return 0;
}