/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : 세가지 형태의 상속
	protected 상속
		- protected보다 접근의 범위가 넓은 멤버는 protected로 변경시켜서 상속하겠다
*/

#include <iostream>
using namespace std;

class Base {

private:
	int num1;

protected:
	int num2;


public:	
	int num3;

	Base() 
		: num1(1), num2(2), num3(3) { }
};

class Derived : protected Base { };	// empty!
									// Base의 public 파트가 protected로 변한다고 보면 된다
									// 즉 num3은 Derived 안에서 protected, Base 생성자도 Derived 안에서 protected
int main(void) 
{
	
	Derived drv;
	// cout << drv.num3 << endl; // 컴파일 에러 발생
	return 0;
}