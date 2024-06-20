/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : new & delete
	교재 p91 ~ 92

	C언어를 공부하면서 malloc과 free 함수의 필요성을 이해하는 것은 하나의 고비가 될 수 있다
	힙의 메모리 할당 및 소멸에 필요한 함수가 malloc과 free이다

	길이정보를 인자로 받아서, 해당 길이의 문자열 저장이 가능한 배열을 생성하고,
	그 배열의 주소 값을 반환하는 함수를 정의해보자

	아래는 다음 두 가지 불편사항이 따른다
		할당할 대상의 정보를 무조건 바이트 크기단위로 전달해야 한다
		반환형이 void형 포인터이기 때문에 적절한 형 변환을 거쳐야 한다

	C++에서 제공하는 키워드 new와 delete를 사용하면 이러한 불편한 점이 사라진다
	new는 malloc 함수를 대신하는 키워드이고,
	delete는 free 함수를 대신하는 키워드이다
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char* MakeStrAdr(int _len)
{

	char* str = (char*)malloc(sizeof(char) * _len);
	return str;
}

int main(void)
{

	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	free(str);
	return 0;
}