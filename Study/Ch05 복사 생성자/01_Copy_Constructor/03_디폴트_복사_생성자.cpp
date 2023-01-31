/*
날짜 : 2023. 1. 31
이름 : 배성훈
내용 : 복사생성자
	디폴트 복사 생성자
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2) { }
	
	/*
	// 이 주석의 코드가 디폴트 복사 생성자
	SoSimple(SoSimple &copy)
		: num1(copy.num1), num2(copy.num2) { }
	*/
};