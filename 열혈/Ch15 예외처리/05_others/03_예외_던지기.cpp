/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : 예외 던지기
	catch 블록에 전달된 예외를 다시 던진다
	이를 이용해 둘 이상의 catch 블록에 의해서 처리되게 할 수 있다.

	예외 값을 그대로 전달한다
*/

#include<iostream>
using namespace std;

void Divide(int num1, int num2) {

	try {

		if (num2 == 0) {

			// throw 2;
			throw 0;
		}
		cout << "몫: " << num1 / num2 << endl;
		cout << "나머지: " << num1 % num2 << endl;
	}

	catch (int expn) {
		// cout << expn << endl;
		cout << "first catch" << endl;
		throw;	// 예외를 다시 던진다
	}
}

int main(void) {

	try {

		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn) {
		// cout << expn << endl;
		cout << "second catch" << endl;
	}
	return 0;
}