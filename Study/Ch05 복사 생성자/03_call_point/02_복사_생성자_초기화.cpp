/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 복사 생성자의 초기화
	Call by value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
	언제 복사 생성자가 호출되는지 확인하는 예제
*/

#include <iostream>
using namespace std;

class SoSimple {

public:
	int num;

public:
	SoSimple(int n)
		: num(n) { }

	SoSimple(const SoSimple& copy)
		: num(copy.num) {
	
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}

	void ShowData() {

		cout << "num : " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob) {

	ob.ShowData();
}

int main(void) 
{

	SoSimple obj(7);
	cout << "함수호출 전" << endl;
	SimpleFuncObj(obj);		// 인자의 ob가 새롭게 obj로 복사 생성됨을 알 수 있다
							// 즉 복사 생성자 호출 > ob.ShowData() 순서이다
	cout << "함수호출 후" << endl;
	return 0;
}