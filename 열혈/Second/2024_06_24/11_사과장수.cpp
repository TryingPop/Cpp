/*
날짜 : 2024. 6. 24
이름 : 배성훈
내용 : 사과장수
	교재 p142 ~ 145

	객체의 선언 방식은 두 가지가 있다
	하나는 
	클래스명 변수명						// 일반적인 변수의 선언방식
	클래스명* 변수명 = new 클래스명		// 동적 할당 방식

	하나의 객체가 다른 하나의 객체에게 메시지를 전달하는 방법은 함수호출을 기반으로 한다
	그래서 객체지향에서는 이러한 형태의 함수호출을 가리켜
	메시지 전달(Message Passing)이라 한다

	하나의 독립된 클래스를 정의하는 것은 쉽다
	그러나 둘 이상의 클래스를 정의하되,
	관계를 형성해서 정의하는 것은 쉽지 않다
	하지만 이는 매우 중요하다
*/

#include <iostream>

using namespace std;

class FruitSeller
{

private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{

		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{

		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() 
	{

		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{

	int myMoney;			// private
	int numOfApples;		// private

public:
	void InitMembers(int money)
	{

		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller& seller, int money)
	{

		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult()
	{

		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void)
{


	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);		// 과일의 구매

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}