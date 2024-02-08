// #pragma warnings(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

/*
날짜 : 2024. 2. 8
이름 : 배성훈
내용 : 덧셈식 출력하기
	printf를 이용해서 출력
*/

using namespace std;

int main1(void)
{

	int a, b;

	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("%d + %d = %d", a, b, a + b);
	return 0;
}