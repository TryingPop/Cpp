/*
날짜 : 2024. 7. 8
이름 : 배성훈
내용 : 객체 포인터 배열
	교재 p194 ~ 196

	아래 예제를 보면 총 3회에 거쳐 new 연산을 했으니
	3회에 거쳐 delete 연산을 해야한다

	객체를 저장할 때에는
	객체로 하느냐, 객체의 주소 값으로 하느냐를 결정해야 한다

	그리고 객체 포인터에서 멤버(변수나 메서드)에 접근하려면 -> 연산자를 이용해
	public 멤버에 접근할 수 있다
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
		: name(NULL), age(0)
	{

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

	Person* parr[3];
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{

		cout << "이름: ";
		cin >> namestr;

		cout << "나이: ";
		cin >> age;

		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}