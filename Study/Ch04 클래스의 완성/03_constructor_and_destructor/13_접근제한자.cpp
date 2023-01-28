/*
날짜 : 2023. 1. 28
이름 : 배성훈
날짜 : 접근제한자
	클래스 내부에서만 객체의 생성을 허용하려는 목적으로 생성자를 private 선언하기도 한다

	아래는 private 선언과 public 선언의 차이를 보여주는 예제
*/

#include <iostream>
using namespace std;

class AAA {

private:
	int num;

public:
	AAA() : num(0){ }
	AAA& CreateInitObj(int n) const {

		AAA* ptr = new AAA(n);
	}

	void ShowNum() const { cout << num << endl; }

private:
	AAA(int n) : num(n) { }
};

int main(void)
{

	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;
	return 0;
}