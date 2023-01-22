#include <iostream>
// 매크로 함수
#define SQUARE(x) ((x) * (x))
using namespace std;

/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 인라인 함수와 매크로 함수
	매크로 함수 : 일반 함수에 비해 속도가 빠르다 
			반면 복잡한 함수를 매크로의 형태로 정의하는데 한계가 있다
	인라인 함수 : 매크로 함수의 단점을 보완한 C++의 함수
*/

inline int Add(int num1, int num2) {

	return num1 + num2;
}

int main()
{
	cout << "매크로 함수 SQUARE(1) : " << SQUARE(1) << endl;
	cout << "인라인 함수 Add(1, 1) : " << Add(1, 1) << endl;

	return 0;
}