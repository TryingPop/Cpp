/*
날짜 : 2023. 1. 23
이름 : 배성훈
내용 : true and false
	참과 거짓
*/

#include <iostream>

using namespace std;

// C에서 표현 하는 방법
#define TRUE	1
#define FALSE	0

int main(void) 
{

	int num = 10;
	int i = 0;

	cout << "true : " << true << endl;		// 1로 표기
	cout << "false : " << false << endl;	// 0으로 표기

	while (true) {

		
		cout << i++ << ' ';
		// i++는 i++를 포함한 코드와 그다음 코드 사이에서 
		// i 값 증가한다고 생각하면 된다
		// 즉, 주석 자리에서 상승

		if (i > num) {

			break;
		}
	}

	cout << endl;

	// 크기(단위 : 바이트)를 확인
	cout << "sizeof 1 : " << sizeof(1) << endl;				// 4
	cout << "sizeof 0 : " << sizeof(0) << endl;				// 4
	cout << "sizeof true : " << sizeof(true) << endl;		// 1
	cout << "sizeof false : " << sizeof(false) << endl;		// 1

	return 0;
}