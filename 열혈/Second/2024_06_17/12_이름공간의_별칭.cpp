/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 이름공간의 별칭 지정
	교재 p47 ~ 49

	아래 예제를 보면 복잡한 AAA::BBB::CCC에 새로운 별칭 ABC를 부여해서
	쉽게 불러옴을 알 수 있다
*/

#include <iostream>

using namespace std;

namespace AAA
{

	namespace BBB
	{

		namespace CCC
		{

			int num1;
			int num2;
		}
	}
}

int main(void)
{

	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;
	cout << ABC::num1 << endl;			// 20
	cout << ABC::num2 << endl;			// 30

	return 0;
}