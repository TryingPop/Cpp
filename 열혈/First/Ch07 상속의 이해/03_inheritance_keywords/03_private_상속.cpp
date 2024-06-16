/*
날짜 : 2023. 2. 4
이름 : 배성훈
내용 : 세가지 형태의 상속
	private 상속
		private보다 접근의 범위가 넓은 멤버는 private으로 변경시켜 상속하겠다
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

class Derived : private Base { };	// empty!
									// num2, num3은 Derived 안에서 private 멤버로 변한다

class DeDerived : public Derived { };	// DeDerived에서 num2와 num3에 접근할 수 없다

int main(void)
{

	Derived drv;
	// cout << drv.num2 << endl; // 컴파일 에러
}
