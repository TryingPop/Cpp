/*
날짜 : 2024. 8. 18
이름 : 배성훈
내용 : C++ 스타일의 초기화
	교재 p214 ~ 216

	앞에서는
		int num = 20;
		int& ref = num;

	다음과 같이 초기화 했었다

	C++에서는 다음과 같이 초기화가 가능하다
		int num(20);
		int& ref(num);

	위의 두 가지 초기와 방식은 동일하다

	C++에서는 위의 두 가지 초기화 방식을 동시에 지원하고 있다
	객체의 생성으로 옮겨보자
*/

#include <iostream>

using namespace std;

class SoSimple 
{

private:
	int num1;
	int num2;

public:
	SoSimple(int _n1, int _n2)
		: num1(_n1), num2(_n2) { }

	void ShowSimpleData()
	{

		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{

	SoSimple sim1(15, 20);

	// sim1과 sim2간 멤버 대 멤버 복사가 일어난다
	SoSimple sim2 = sim1;
	// Sosimple sim2(sim1); // 과 동일한 의미로 해석된다
	sim2.ShowSimpleData();		// 15 20

	return 0;
}