/*
��¥ : 2023. 1. 30
�̸� : �輺��
���� : ���� 160p ����1
	Chapter 03���� ������ ������� �ù����̼� ���� FruitSaleSim1.cpp���� 
	������ �� Ŭ������ ��������� private���� ������ �Ǿ��ִ�.
	�׷��� ���� ������ ������ �� �մ� ��ġ�� �ƹ��͵� �Ǿ����� �ʴ�.
		- ����� ���� �������� 0���� ���� ���� ������ �� ����.

	���� ��������� �׻� ������ų �� �ֵ��� ������ �����ϰ�,
	������ �������� ���� �� �ֵ��� �Ϻ� �Լ��� const�� �����غ���.
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
		myMoney = money;
	}

	int ShowSalesresult() const {

		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}

	/*
	int ShowSalesresult() {

		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
	*/
};

class FruitBuyer {

	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money) {

		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller& seller, int money) {

		// ���� ��ġ
		if (money < 0) { 

			cout << "����� ���� �������� 0���� ���� ���� ������ �� �����ϴ�." << endl;
			return; 
		}	
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult() const {

		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
	/*
	void ShowBuyResult() {

		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
	*/
};

int main(void)
{

	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesresult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}