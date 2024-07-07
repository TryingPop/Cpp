/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : 멤버 이니셜라이저를 이용한 변수 및 const 상수 초기화
	교재 p180 ~ 

	멤버 이니셜라이저는 객체가 아닌 멤버의 초기화에도 사용할 수 있다
		class A
		{

		private:
			int num;

		public:
			A(const int n)
				: num(n)
			{ }
		}

	과같이 초기화할 수 있다

	즉, 프로그래머는 생성자의 몸체에서 초기화 하는 법과 이니셜라이저를 이용하는
	초기화 방법 중에서 선택이 가능하다

	일반적으로 멤버변수의 초기화에 있어서는
	이니셜라이저를 선호되는 편이다

	초기화하는 대상을 명확히 인식할 수 있고 성능에 약간의 이점이 있다
	이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성된다
	반면 생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하면,
	선언과 초기화를 각각 별도의 문장에서 진행하는 형태로 바이너리 코드가 생성된다

	const 변수 선언은 선언과 동시에 초기화해야 하기 때문에
	이니셜라이저를 이용하면 초기화가 가능하다
*/

#include <iostream>

using namespace std;

class FruitSeller 
{

private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numOfApples(num), myMoney(money)
	{ }

	int SaleApples(int money)
	{

		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const
	{

		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{

private:
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money)
		: myMoney(money), numOfApples(0)
	{ }

	void BuyApples(FruitSeller& seller, int money)
	{

		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult() const
	{

		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void)
{

	FruitSeller seller(1'000, 20, 0);
	FruitBuyer buyer(5'000);
	buyer.BuyApples(seller, 2'000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}