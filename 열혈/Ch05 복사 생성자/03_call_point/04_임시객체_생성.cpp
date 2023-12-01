/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 임시객체
	임시객체의 생성

	클래스 외부에서 객체의 멤버함수를 호출하기 위해 필요한 것은 다음 세 가지 중 하나
		- 객체에 붙여진 이름
		- 객체의 참조 값
		- 객체의 주소 값
*/

#include <iostream>
using namespace std;

class Temporary {

private:
	int num;

public:
	Temporary(int n)
		: num(n) {

		cout << "create obj: " << num << endl;
	}

	~Temporary() {

		cout << "destroy obj: " << num << endl;
	}

	void ShowTempInfo() {

		cout << "My name is " << num << endl;
	}
};

int main(void)
{

	Temporary(100);	// 임시객체의 생성방법
	// 여기서 임시객체는 바로 해제
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();	// 임시객체가 생성된 위치에 임시객체의 참조 값이 반환된다
									// 그래서 객체의 참조값으로 메소드가 실행
	// ShowTempInfo 이후 메모리에서 해제된다
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);	// 참조 값이 반환되어 이를 참조자를 이용해 참조하는 것
	// 참조하고 있어서 Temporary(300)은 위처럼 여기서 해제되지 않는다 다만 메인함수가 끝나면 해제된다
	cout << "********** after make!" << endl << endl;
	return 0;
}