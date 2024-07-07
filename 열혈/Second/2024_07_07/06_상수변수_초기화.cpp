/*
��¥ : 2024. 7. 7
�̸� : �輺��
���� : ��� �̴ϼȶ������� �̿��� ���� �� const ��� �ʱ�ȭ
	���� p180 ~ 

	��� �̴ϼȶ������� ��ü�� �ƴ� ����� �ʱ�ȭ���� ����� �� �ִ�
		class A
		{

		private:
			int num;

		public:
			A(const int n)
				: num(n)
			{ }
		}

	������ �ʱ�ȭ�� �� �ִ�

	��, ���α׷��Ӵ� �������� ��ü���� �ʱ�ȭ �ϴ� ���� �̴ϼȶ������� �̿��ϴ�
	�ʱ�ȭ ��� �߿��� ������ �����ϴ�

	�Ϲ������� ��������� �ʱ�ȭ�� �־��
	�̴ϼȶ������� ��ȣ�Ǵ� ���̴�

	�ʱ�ȭ�ϴ� ����� ��Ȯ�� �ν��� �� �ְ� ���ɿ� �ణ�� ������ �ִ�
	�̴ϼȶ������� �̿��ϸ� ����� ���ÿ� �ʱ�ȭ�� �̷����� ���·� ���̳ʸ� �ڵ尡 �����ȴ�
	�ݸ� �������� ��ü�κп��� ���Կ����� ���� �ʱ�ȭ�� �����ϸ�,
	����� �ʱ�ȭ�� ���� ������ ���忡�� �����ϴ� ���·� ���̳ʸ� �ڵ尡 �����ȴ�

	const ���� ������ ����� ���ÿ� �ʱ�ȭ�ؾ� �ϱ� ������
	�̴ϼȶ������� �̿��ϸ� �ʱ�ȭ�� �����ϴ�
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

		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
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

		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main(void)
{

	FruitSeller seller(1'000, 20, 0);
	FruitBuyer buyer(5'000);
	buyer.BuyApples(seller, 2'000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}