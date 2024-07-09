/*
날짜 : 2024. 7. 9
이름 : 배성훈
내용 : this 포인터의 활용
	교재 p197 ~ 

	this 포인터는 제법 유용하게 사용되는데,
	이에 대한 설명에 앞서 먼저 다음 클래스를 관찰하자

		class AAA
		{

		private:
			int num;

		public:
			void ThisFunc(int num)
			{

				this -> num = 222;
				num = 105;
			}
		}

	와 같이 주어졌을 때, ThisFunc 함수의 매개변수 이름은 num이다
	그런데 이 이름은 멤버변수의 이름과 동일하기 때문에
	ThisFunc 함수 내에서의 num은 매개변수 num을 의미하게 된다
	따라서 변수의 이름만 참조하는 방법으로는 ThisFunc 함수 내에서 
	멤버변수 num에 접근이 불가능하다
	그러나 this 포인터를 활용하면 접근이 가능하다

	변수의 이름을 짓는 것은 신경쓰이는 일이다
	특히 유사한 성격을 지니는 두 변수의 이름을 구별되게 짓는 것은 고민한다
	멤버 변수와 매개변수의 이름을 동일하게 짓고 this 포인터를 이용해서 
	이 둘을 구분하는 것을 좋아하는 프로그래머들도 있다
*/

#include <iostream>

using namespace std;

class TwoNumber
{

private:
	int num1;
	int num2;

public:
	/*
	// 해당 경우에 유효
	TwoNumber(int num1, int num2)
	{

		this->num1 = num1;
		this->num2 = num2;
	}
	*/

	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)
	{

		// empty
	}

	void ShowTwoNumber()
	{

		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void)
{

	TwoNumber two(2, 4);
	two.ShowTwoNumber();

	return 0;
}