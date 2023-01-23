/*
날짜 : 2023. 1. 23
이름 : 배성훈
내용 : 참조자 함수
	ref를 이용한 swap함수 구현

	주의할 점
		참조자 기반의 함수 구현 시 값이 변하는지 안변하는지 알 수 없다
		함수 안에서 참조자의 값이 변하지 않는 경우 참조자 앞에 const를 이용해 알릴 수 있다
		이러한 단점에 의해 C++에서 참조자 대신 포인터를 이용하는 경우가 있다
*/

#include <iostream>
using namespace std;

// &ref1, &ref2 는 함수 호출시 초기화 한다는 의미
void Swap(int& ref1, int& ref2) {

	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main(void) 
{

	int val1 = 10;
	int val2 = 20;

	Swap(val1, val2);

	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;
	return 0;
}