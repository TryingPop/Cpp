/*
날짜 : 2023. 2. 25
이름 : 배성훈
내용 : C언어의 형 변환
	C언어의 형 변환 연산자의 말도 안되는 예제

	static_cast 연산자는 아래의 형 변환을 하지 못한다
*/

#include <iostream>
using namespace std;

int main(void)
{

	const int num = 20;
	
	int* ptr = (int*)& num;		// const 상수의 포인터 (const 포인터)이므로 형 변환을 했다
	// const int* ptr = &num;	
	*ptr = 30;					// int* 로 형 변환을 해서 값 변형이 가능 
								// const int* ptr로 하면 컴파일 에러가 뜬다

	cout << *ptr << endl;		// 30
	// cout << num << endl;		// 20

	float* adr = (float*)ptr;	
	cout << *adr << endl;		// 저장된 데이터를 float형으로 해석해서 출력한다
	return 0;
}