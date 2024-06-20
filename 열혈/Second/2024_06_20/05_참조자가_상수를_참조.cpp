/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : 참조자가 상수를 참조
	교재 p89 ~ 90

		int num = 20 + 30;
	과 같은 코드가 있을 때,

	프로그램 상에서 20, 30과 같이 표현되는 숫자를 가리켜
	리터럴(literal constant) 상수 혹은 리터럴(literal)이라 했다

	이들은 임시적으로 존재하는 값이고,
	다음행으로 넘어가면 존재하지 않는 상수이다

	덧셈연산을 위해 20, 30은 메모리에 저장되지만
	저장되었다고 해서 참조가 가능한 것은 아니다
	즉, 다음행으로 넘어가면 소멸되는 상수다

		const int& ref = 30;
	이러한 상수를 참조하는 것은 이치에 맞지 않다
	30이 메모리 공간에 계속 남아ㅣㅆ을 때에나 성립이 가능한 문장이다

	C++은 위 문장이 성립할 수 있도록, const 참조자를 이용해서
	상수를 참조할 때 임시변수라는 것을 만든다
	그리고 이 장소에 상수 30을 저장하고선 참조자가 이를 참조하게끔 한다
	이렇듯 임시로 생성한 변수를 상수화하여 참조자가 참조하게끔 하는 구조이니,
	결과적으로는 상수화된 변수를 참조하는 형태가 된다

	임시변수의 생성을 통해서 const 참조자의 상수참조를 허용함으로써,

	int Adder(const int& _num1, const int& _num2)
	{

		return _num1 + _num2;
	}

	cout << Adder(3, 4) << endl;
	처럼 간단히 호출할 수 있게되었다
*/

#include <iostream>
#define endl '\n'

using namespace std;

int Adder(const int& _num1, const int& _num2)
{

	return _num1 + _num2;
}

int main(void)
{

	// 해당 코드 사용가능
	const int& ref = 30;
	cout << ref << endl;

	cout << Adder(3, 4) << endl;
	return 0;
}