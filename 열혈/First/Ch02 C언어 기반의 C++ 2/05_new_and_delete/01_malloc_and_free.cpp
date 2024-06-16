/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : malloc & free
	C에서 사용하던 동적 메모리 할당
*/
#define _CRT_SECURE_NO_WARNINGS		// strcpy 에러무시

#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

/// <summary>
/// 문자열 동적 메모리 할당
/// 1(char의 크기) * len 바이트만큼 할당한다
/// </summary>
/// <param name="len">문자열의 길이</param>
/// <returns>할당된 메모리의 주소</returns>
char* MakeStrAdr(int len) {

	char* str = (char*)malloc(sizeof(char) * len);	
	return str;
}

int main(void) {

	// str 포인터에 20 바이트 메모리 할당
	char* str = MakeStrAdr(20);

	// str에 I am so happy~ 문자열을 복사해 넣는다
	strcpy(str, "I am so happy~");
	cout << str << endl;
	// str 메모리 해제
	free(str);
	return 0;
}