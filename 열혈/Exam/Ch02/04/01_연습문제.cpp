/*
날짜 : 2023. 1. 24
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
	
	char str1[15];
	char str2[25];

	char name[100];

	cout << "이름을 입력하세요 : ";
	cin >> name;

	if (strlen(name) <= 4) {

		strcpy(str1, name);
		strcat(str1, "님");
		cout << "이름이 짧은 "  << str1 << " 안녕하세용" << endl;
	}
	else if (strlen(name) < 9) {

		strcpy(str2, name);
		strcat(str2, "님");
		cout << "이름이 긴 " << str2 << " 안녕하세용" << endl;
	}
	else {
		cout << "이름이 너무 길어요." << endl;
	}

	return 0;
}