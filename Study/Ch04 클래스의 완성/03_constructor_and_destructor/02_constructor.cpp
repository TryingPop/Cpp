/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 생성자
	클래스명 변수명(); 인자로 정의는 불가능하다
	클래스명 변수명();은 반환을 클래스명으로 하고 변수명()인 함수로 오해할 수 있기 때문이다

	반면,
	클래스명* ptr = new 클래스명();은 정의 가능하다
*/

#include <iostream>
using namespace std;

class SimpleClass {

private:
	int num1;
	int num2;

public:
	SimpleClass(int n1 = 0, int n2 = 0) {

		num1 = n1;
		num2 = n2;
	}

	void ShowData() const {

		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void) 
{

	SimpleClass sc1();
	SimpleClass mysc = sc1();
	mysc.ShowData();
	return 0;
}

SimpleClass sc1() {

	SimpleClass sc(20, 30);
	return sc;
}