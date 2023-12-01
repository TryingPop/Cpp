/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : 객체지향 프로그래밍의 이해
	사과 판매자와 사과 구매자를 객체로 표현해보자
*/

#include <iostream>
using namespace std;

class FruitSeller {

private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) {

		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money) {

		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() {

		cout << "남은 사과 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMoney << endl << endl;
	}
};

class FruitBuyer {

	int myMoney;		// private
	int numOfApples;	// private

public:
	void InitMembers(int money) {

		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller& seller, int money) {

		numOfApples += seller.SaleApples(money);	// 객체지향에서 이러한 형태의 함수호출을 메시지 전달이라 한다 
		myMoney -= money;
	}

	void ShowByResult() {

		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numOfApples << endl << endl;
	}
};

int main(void) 
{

	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowByResult();
	return 0;
}