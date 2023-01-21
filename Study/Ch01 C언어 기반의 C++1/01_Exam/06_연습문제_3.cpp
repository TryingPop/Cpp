#include <iostream>		
using namespace std;

/*

날짜 : 2023. 1. 21
이름 : 배성훈
내용 : 교재 22p 문제3
	숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해 보자.
	예를들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력해야 한다.
*/

int main()
{

	// 입력 받을 문자
	int num;

	cout << "구구단 프로그램" << endl;
	cout << "-------------------------------" << endl;
	cout << "원하는 구구단을 입력하세요 : ";
	cin >> num;

	for (int i = 1; i < 10; i++) {

		cout << num << " * " << i << " = " << num * i << endl;
	}

	return 0;
}
