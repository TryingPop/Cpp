/*
날짜 : 2023. 1. 28
이름 : 배성훈
내용 : 이니셜라이저
	이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성된다
	const 멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다
*/

#include <iostream>
using namespace std;

class FruitSeller {

private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numOfApples(num), myMoney(money) { }

	int SaleApples(int money) {

		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const {

		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}

	// const 비교
	void GetPrice() const {

		cout << "Price : " << APPLE_PRICE << endl;
	}
};

class FruitBuyer {

private:
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money)
		: myMoney(money), numOfApples(0) { }

	void BuyApples(FruitSeller& seller, int money) {

		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult() const {

		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void) 
{

	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();


	FruitSeller fs(1500, 10, 0);
	fs.ShowSalesResult();

	// C#과 다른 결과를 낸다
	// C#에서 상수 변수는 클래스 변수처럼 인식되어 같은 클래스면 
	// 모두가 같은 const변수를 이용한다
	seller.GetPrice();	// 1000
	fs.GetPrice();		// 1500
	return 0;
}