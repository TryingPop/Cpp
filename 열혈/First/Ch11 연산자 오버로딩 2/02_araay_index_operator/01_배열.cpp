/*
날짜 : 2023. 2. 15
이름 : 배성훈
내용 : 배열
	C, C++의 기본 배열의 특징
		경계 검사를 하지 않는다
*/

#include <iostream>
using namespace std;

int main(void)
{

	int arr[3] = { 1, 2, 3 };
	// 경계 검사를 하지 않아 다음과 같은 특성이 존재
	// 둘 다 쓰레기값을 호출한다
	cout << arr[-1] << endl;	// arr의 주소 sizeof(int) * -1의 위치에 접근
	cout << arr[-2] << endl;	// arr의 주소 sizeof(int) * -2의 위치에 접근
	return 0;
}