/*
날짜 : 2023. 2. 8
이름 : 배성훈
내용 : 객체 포인터의 참조관계
	C++에서 자식 클래스의 포인터 변수는 자기 자신 객체와 부모 클래스의 모든 객체를 가리킬 수 있다.
		(객체의 주소 값을 저장할 수 있다.)
*/

#include <iostream>
using namespace std;

class Person {

public:
	void Sleep() {

		cout << "Sleep" << endl;
	}
};

class Student : public Person {

public:
	void Study() {

		cout << "Study" << endl;
	}
};

class PartTimeStudent : public Student {

public:
	void Work() {

		cout << "Work" << endl;
	}
};

int main(void) 
{

	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}