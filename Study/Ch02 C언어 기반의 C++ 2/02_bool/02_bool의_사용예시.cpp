/*
날짜 : 2023. 1. 23
이름 : 배성훈
내용 : bool 예시
	if 문에 이용하는 예시
*/

#include <iostream>
using namespace std;

bool IsPositive(int num) {

	if (num <= 0) {

		return false;
	}
	else {

		return true;
	}
}

int main(void)
{

	bool isPos;
	int num;
	cout << "Input number : ";
	cin >> num;

	isPos = IsPositive(num);

	if (isPos) {

		cout << "Positive number" << endl;
	}
	else {

		cout << "Negative number" << endl;
	}

	return 0;
}