/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : new & delete
	교재 p92 ~ 93

	C++에서는 new & delete 키워드를 지원한다
	new를 이용하면 할당할 대상의 정보를 바이트 크기단위로 전달할 필요가 없고 형변환도 필요없다
	그리고 제거할 때는 delete를 이용해 제거하면 된다
	delete의 경우 배열의 형태면 변수 앞에 []를 붙여 추가로 명시해주기만 하면 된다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* MakeStrAdr(int _len)
{

	// char* str = (char*)malloc(sizeof(char) * _len);
 	char* str = new char[_len];
	return str;
}

int main(void)
{

	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	// free(str);
	delete[] str;
	return 0;
}