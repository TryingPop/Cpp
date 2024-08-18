/*
��¥ : 2024. 8. 18
�̸� : �輺��
���� : SoSimple sim2(sim1)
	���� p 216 ~ 218

	���뿡 ���� SoSimple sim2(sim1)�� ��������
	�׸��� �������� ȣ��������� �̸� ��м��c����

	SoSimple sim2(sim1);
	�� ������ ����ִ� ������ �����ϸ� ������ ����

	SoSimple�� ��ü�� �����ض�
	��ü�� �̸��� sim2�� ���Ѵ�
	sim1�� ���ڷ� ���� �� �ִ� �������� ȣ���� ���ؼ� ��ü������ �Ϸ��Ѵ�

	���� ����� �����ؼ��� �߰����� ������ �ʿ� ���� ���̴�
	�� ���� ��ü���������� ȣ���ϰ��� �ϴ� �����ڴ� 
	������ ���� SoSimple ��ü�� ���ڷ� ���� �� �ִ� �������̴�

	SoSimple(SoSimple& _copy)
	{

		...
	}

	�׸�������� ���嵵,
	SoSimple sim2 =sim1;

	���� ������ ���·� ������ ��ȯ�� �Ǿ(�ڵ������� ��ȯ�� �Ǿ) ��ü�� �����Ǵ� ���̴�

	SoSimple sim2(sim1);

	�׷��� �ռ� ������ SoSimple Ŭ�������� �̷��� ������ �����ڰ� ���ǵǾ� ���� �ʾҴ�
	�̴� ����Ʈ ���� �����ڿ� ���� ���ظ� ���ؼ� ���� ���� �� �ִ�
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

	// ���� ������(copy constructor)
	// ��� �� ����� ���翡 ���Ǵ� ������ �����Ű�� ����
	// ������ ������ ���ʶ߸��� ������ �Ǵ�
	// Ű���� const�� �����ؼ� �̷��� �Ǽ��� ���°� ����
	// SoSimple(const SoSimple& _copy)
	SoSimple(SoSimple& _copy)
		: num1(_copy.num1), num2(_copy.num2) 
	{ 
	
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}

	void ShoSimpleData()
	{

		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{

	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1;		// SoSimple sim2(sim1);���� ��ȯ
								// Called SoSimple(SoSimple &copy) �� ��µȴ�
	cout << "���� �� �ʱ�ȭ ����" << endl;

	sim2.ShoSimpleData();

	return 0;
}