/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 디폴트 생성자
	메모리 할당 이후에 생성자의 호출까지 완료되어야 객체
	즉, 객체가 되기 위해서는 반드시 하나의 생성자가 호출되어야 한다

	new 연산자로 호출하면 생성자가 호출된다
	반면 malloc으로 호출하면 생성자 호출이 안된다
*/

#include<cstdlib>
using namespace std;

class AAA {

private:
	int num;

public:
	int GetNum() { return num; }
	// AAA() { } // 디폴트 생성자가 생략
};

int main(void) 
{

	AAA* nptr = new AAA();
	AAA* mptr = (AAA*)malloc(sizeof(AAA));
}