/*
날짜 : 2023. 1. 26
이름 : 배성훈
내용 : 교재 135p 문제1
	계산기 기능의 Calculator 클래스를 정의해 보자.
	기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈 그리고 나눗셈이며, 
	연산을 할 때 마다 어떠한 연산을 몇 번 수행했는지 기록되어야 한다.
	아래의 main 함수와 실행의 예에 부합하는 Calculator 클래스를 정의하면 된다.
	단, 멤버변수는 private으로,
	멤버함수는 public으로 선언하자.
	이렇게 선언하는 이유에 대해서는 다음 Chapter에서 자세히 언급한다.

	int main(void)
	{

		Calculator cal;
		cal.Init();
		cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
		cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
		cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
		cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
		cal.ShowOpCount();
		return 0;
	}

	실행의 예
	3.2 + 2.4 = 5.6
	3.5 / 1.7 = 2.05882
	2.2 - 1.5 = 0.7
	4.9 / 1.2 = 4.08333
	덧셈: 1 뺄셈: 1 곱셈: 0 나눗셈: 2 
*/

#include <iostream>
using namespace std;

class Calculator {

private:
	int addCnt;
	int minCnt;
	int mulCnt;
	int divCnt;

public:
	void Init() {

		addCnt = 0;
		minCnt = 0;
		mulCnt = 0;
		divCnt = 0;
	};
	
	float Add(float num1, float num2) {

		addCnt++;
		return num1 + num2;
	};

	float Min(float num1, float num2) {

		minCnt++;
		return num1 - num2;
	}

	float Mul(float num1, float num2) {

		mulCnt++;
		return num1 * num2;
	};

	float Div(float num1, float num2) {

		divCnt++;
		return num1 / num2;
	}

	void ShowOpCount() {

		cout << "덧셈: " << addCnt << ' ' << "뺄셈: " << minCnt << ' ' << "곱셈 : " << mulCnt << ' ' << "나눗셈: " << divCnt << endl;
	}
};

int main(void) 
{

	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}

