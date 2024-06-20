/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : C++에서 C언어의 표준함수 호출하기
	교재 p96 ~ 98

	C언어 라이브러리에는 매우 다양한 유형의 함수들이 정의되어 있다
	이러한 함수들은 C++ 표준 라이브러리에도 포함되어 있다

	일부 헤더파일만 보면,
		stdlib.h	->		cstdlib
		stdio.h		->		cstdio
		math.h		->		cmath
		string.h	->		cstring

	헤더파일의 확장자인 .h를 생략하고 앞에 c를 붙이면
	C언어에 대응하는 C++의 헤더파일 이름이 된다

	C++ 관점에서 stdio.h의 형태로 함수호출을 허용하는 이유는 
	하위 버전과의 호환성(backwards compatibility)을 제공하기 위함이다

	그리고 C++표준 라이브러리가 제공하는 함수들과 
	C표준 라이브러리가 제공하는 함수들이 완전히 일치하는 것도 아니다

	abs함수를 보면
	C에서는 
		int abs(int num);
	인 반면
	
	C++에서는 오버로딩되어
		long abs(long num);
		float abs(float num);
		double abs(double num);
		long double abs(long double num);

	C++에서는 함수 오버로딩이 가능하기 때문에 자료형에 따라서 함수의 이름을 달리해서 정의하지 않고,
	보다 사용하기 편하도록 함수를 오버로딩 해 놓은 것이다
	C++ 문법을 기반으로 개선된 형태로 라이브러리가 구성되어 있으므로,
	가급적 C++의 표준헤더를 이용해서 함수를 호출하는 것이 좋다
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cmath>
#include <cstdio>
#include <cstring>

// 모든 표준함수들이 이름곤간 std 내에 선언되어있기 때문에
// C++ 컴파일러가 위의 선언을 생략해도
// 기본함수의 호출은 허용한다
// 하지만 허용하는 함수의 종류와 범위도 컴파일러마다 다르기 때문에
// 이름공간에 대한 선언을 생략한 상태에서 표준함수를 호출하는 것은 바람직하지 않다
using namespace std;

int main(void)
{

	char str1[] = "Result";
	char str2[30];

	strcpy(str2, str1);

	printf("%s: %f \n", str1, sin(0.14));	// 0.139543
	printf("%s: %f \n", str2, abs(-1.25));	// 1.250000

	return 0;
}