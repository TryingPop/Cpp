/*
날짜 : 2023. 1. 23
이름 : 배성훈
내용 : 참조자를 반환하는 함수
	참조자를 반환하는 함수 구현
*/

#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{

	ref++;
	return ref;
}

int RefRetFuncTwo(int& ref) {

	ref++;
	return ref;
}

int main(void) 
{

	int num1 = 1;						
	int& num2 = RefRetFuncOne(num1);	 
	// 참조자가 아니라서 새 주소 할당 받고 값만 받아옴
	int num3 = RefRetFuncOne(num1);	
	int num4 = RefRetFuncTwo(num1);
	// int& num5 = RefRetFuncTwo(num1);

	// num1 = num2 = num4 = 4, num3 = 3인 상태
	num1++;
	num2++;
	// 여기까지 num3과 num4는 영향 안받으므로 num3 = 3, num4 = 4
	num3++;
	num4++;

	cout << "num1 : " << num1 << endl;	// 6
	cout << "num2 : " << num2 << endl;	// 6
	cout << "num3 : " << num3 << endl;	// 4
	cout << "num4 : " << num4 << endl;	// 5
	return 0;
}