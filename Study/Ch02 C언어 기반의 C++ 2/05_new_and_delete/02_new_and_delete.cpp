/*
날짜 : 2023. 1. 24
이름 : 배성훈
내용 : new & delete
	malloc에 비해 간단하게 생성되는 new
*/
#define _CRT_SECURE_NO_WARNINGS		// strcpy 에러무시

#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

char* MakeStrAdr(int len) {

	char* str = new char[len];
	return str;
}

int main(void) 
{

	char* str = MakeStrAdr(20);

	strcpy(str, "I am so happy~");
	cout << str << endl;

	// 배열을 해제하는 경우 delete뒤에 []를 추가해줘야한다
	delete[] str;
	return 0;
}