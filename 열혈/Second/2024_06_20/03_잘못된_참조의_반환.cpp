/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : 잘못된 참조의 반환
	교재 p87 ~ 88

	지역변수를 참조의 형태로 반환하고 있다
	아래와 같은 형태로 반환하면 num에 ref라는 또 하나의 이름이 붙게된다
	함수가 반환이되면 지역변수 num은 소멸된다
	아직 채 소멸되지 않은 쓰레기 값 형태로 남아있는데, 
	운이 좋으면 아직 살아있어 정상적인 데이터를 참조하는 경우도 있지만
	소멸되어 비 정상적인 결과를 보일 수도 있다!

	그래서 지역변수를 참조형으로 반환하는 일이 없어야 한다
	컴파일 에러가 안떠서 주의해야한다!!
*/

#include <iostream>
#define endl '\n'

using namespace std;

int& WrongFunc(int _n)
{

	int num = 20;
	num += _n;
	return num;
}

int main(void)
{

	int num1 = 10;

	int& num2 = WrongFunc(num1);

	cout << num1 << endl;		// 10
	cout << num2 << endl;		// -858993460
	return 0;
}