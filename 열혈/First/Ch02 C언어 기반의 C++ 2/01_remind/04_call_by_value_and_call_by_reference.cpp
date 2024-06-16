/*
날짜 : 2023. 1. 23
이름 : 배성훈
내용 : call by value & call by reference
	값에 의한 호출, 참조에 의한 호출의 차이
*/

#include <iostream>
using namespace std;

// 함수 선언
void ValFunc(int num);
void RefFunc(int* num);


int main(void) 
{

	int val1 = 0, val2 = 0;
	ValFunc(val1);
	RefFunc(&val2);

	cout << "val1 : " << val1 << endl;	// 0
	cout << "val2 : " << val2 << endl;	// 1
}

// Call by Value
void ValFunc(int num) {

	// 지역 변수 num이 할당되고 매개변수의 값을 복사해 담는다
	// 복사한 값만 증가하고 매개변수 num의 값에 변화는 없다
	// 함수가 종료 되어도 매개변수 값의 변화는 없다
	num += 1;

}

// Call by Reference
void RefFunc(int* num) {

	// 주소를 가리키는 변수 num을 생성 num의 주소를 넣는다
	// *num은 주소로 찾아가 해당하는 값을 수정한다
	// 함수가 종료되면 매개변수의 값이 1 증가 한다
	*num += 1;
}