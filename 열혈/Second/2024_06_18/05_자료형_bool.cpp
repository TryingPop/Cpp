/*
날짜 : 2024. 6. 18
이름 : 배성훈
내용 : 자료형 bool
	교재 p66 ~ 67

	true와 false는 그 자체로 참과 거짓을 의미하는 데이터이기 때문에,
	이들 데이터의 저장을 위한 자료형이 별도로 정의되어 있는 것은 당연하다

	true와 false를 가리켜 bool 형 데이터라 한다
	bool은 int, double과 마찬가지로 기본 자료형의 하나이기에
	bool 형 변수를 선언하는 것이 가능하다
*/

#include <iostream>

using namespace std;

bool IsPositive(int _num)
{

	if (_num <= 0) return false;
	else return true;
}

int main(void)
{

	bool isPos;
	int num;

	cout << "Input number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos) cout << "Positive number" << endl;
	else cout << "Negative number" << endl;

	return 0;
}