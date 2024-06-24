/*
��¥ : 2024. 6. 24
�̸� : �輺��
���� : ������
	���� p142 ~ 145

	��ü�� ���� ����� �� ������ �ִ�
	�ϳ��� 
	Ŭ������ ������						// �Ϲ����� ������ ������
	Ŭ������* ������ = new Ŭ������		// ���� �Ҵ� ���

	�ϳ��� ��ü�� �ٸ� �ϳ��� ��ü���� �޽����� �����ϴ� ����� �Լ�ȣ���� ������� �Ѵ�
	�׷��� ��ü���⿡���� �̷��� ������ �Լ�ȣ���� ������
	�޽��� ����(Message Passing)�̶� �Ѵ�

	�ϳ��� ������ Ŭ������ �����ϴ� ���� ����
	�׷��� �� �̻��� Ŭ������ �����ϵ�,
	���踦 �����ؼ� �����ϴ� ���� ���� �ʴ�
	������ �̴� �ſ� �߿��ϴ�
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

		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
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

		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main(void)
{


	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);		// ������ ����

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}