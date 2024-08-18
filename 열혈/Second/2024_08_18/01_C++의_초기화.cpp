/*
��¥ : 2024. 8. 18
�̸� : �輺��
���� : C++ ��Ÿ���� �ʱ�ȭ
	���� p214 ~ 216

	�տ�����
		int num = 20;
		int& ref = num;

	������ ���� �ʱ�ȭ �߾���

	C++������ ������ ���� �ʱ�ȭ�� �����ϴ�
		int num(20);
		int& ref(num);

	���� �� ���� �ʱ�� ����� �����ϴ�

	C++������ ���� �� ���� �ʱ�ȭ ����� ���ÿ� �����ϰ� �ִ�
	��ü�� �������� �Űܺ���
*/

#include <iostream>

using namespace std;

class SoSimple 
{

private:
	int num1;
	int num2;

public:
	SoSimple(int _n1, int _n2)
		: num1(_n1), num2(_n2) { }

	void ShowSimpleData()
	{

		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{

	SoSimple sim1(15, 20);

	// sim1�� sim2�� ��� �� ��� ���簡 �Ͼ��
	SoSimple sim2 = sim1;
	// Sosimple sim2(sim1); // �� ������ �ǹ̷� �ؼ��ȴ�
	sim2.ShowSimpleData();		// 15 20

	return 0;
}