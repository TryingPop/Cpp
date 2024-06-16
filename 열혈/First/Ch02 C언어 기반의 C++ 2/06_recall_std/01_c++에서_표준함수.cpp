/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : C++에서 표준함수 호출
	math.h >> cmath
	stdio.h >> cstdio
	string.h >> cstring
	과 같이 사용하기

	장점
		하위 버전의 호환성을 제공해준다

	주의점
		모든 표준함수들이 이름공간 std에 정의되어져 있다
*/

#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

int main(void) 
{

	char str1[] = "Result";
	char str2[30];

	strcpy_s(str2, str1);
	printf("%s : %f \n", str1, sin(0.14));
	printf("%s : %f \n", str2, abs(-1.25));
	return 0;
}