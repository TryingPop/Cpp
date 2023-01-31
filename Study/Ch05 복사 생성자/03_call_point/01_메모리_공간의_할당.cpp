/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 메모리 공간의 할당과 초기화
	동시에 일어나는 상황
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num;
};


int SimpleFunc(int n) {

	return n++;	// 반환하는 순간 메모리 공간이 할당되면서 동시에 초기화!
}

SoSimple SimpleFuncObj(SoSimple obj) {

	return obj;	// 위와 마찬가지로 반환하는 순간 메모리 공간이 할당되고 동시에 초기화!
}

int main(void)
{

	// 할당과 동시에 초기화
	int num1 = 10;
	int num2 = num1;

	SimpleFunc(num1); // 호출되는 순간 매개변수 n이 할당과 동시에 초기화!

	// 다음 코드를 보면 반환 값이 메모리에 할당되는 것을 알 수 있다
	cout << SimpleFunc(num2) << endl;

	// 할당과 동시에 초기화
	SoSimple obj1;
	SoSimple obj2 = obj1;	// 전달되는 인자로 초기화

	SimpleFuncObj(obj1);	// 위와 동일하다
}