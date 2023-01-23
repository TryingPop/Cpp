#include <iostream>
using namespace std;

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 매개변수의 디폴트 값
	디폴트 값은 오른쪽부터 배치해야한다
*/

// 함수의 선언
int BoxVolume(int length, int width = 1, int height = 1);

int main()
{

	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
//	cout << "[D, D, D] : " << BoxVolume() << endl; // 에러 뜬다

	return 0;
}

// 함수의 정의
int BoxVolume(int length, int width, int height) {

	return length * width * height;
}
