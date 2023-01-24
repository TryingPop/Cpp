/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : 교재 99p 문제1
	다음 표준함수를 호출하는 예제를 만들되,
	C++의 헤더를 선언해서 만들어보자.
	그리고 예제의 내용은 상관이 없지만,
	아래의 함수들을 최소 1회 이상 호출해야 한다.
	참고로 다음 함수들은 C언어의 경우 <string.h>에 선언되어 있다.
		- strlen : 문자열의 길이 계산
		- strcat : 문자열의 뒤에 덧붙이기
		- strcpy : 문자열 복사
		- strcmp : 문자열의 비교
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{

	char* str1 = "ABC 123 ";
	char* str2 = "DEF 456 ";

	char str3[50];

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;
	strcpy(str3, str1);
	strcpy(str3, str1);
	cout << str3 << endl;

	if (strcmp(str1, str2) == 0) {
		cout << "문자열이 같다." << endl;
	}
	else {

		cout << "문자열이 같지 않다." << endl;
	}
	return 0;
}