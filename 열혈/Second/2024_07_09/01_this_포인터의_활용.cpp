/*
��¥ : 2024. 7. 9
�̸� : �輺��
���� : this �������� Ȱ��
	���� p197 ~ 

	this �����ʹ� ���� �����ϰ� ���Ǵµ�,
	�̿� ���� ���� �ռ� ���� ���� Ŭ������ ��������

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

	�� ���� �־����� ��, ThisFunc �Լ��� �Ű����� �̸��� num�̴�
	�׷��� �� �̸��� ��������� �̸��� �����ϱ� ������
	ThisFunc �Լ� �������� num�� �Ű����� num�� �ǹ��ϰ� �ȴ�
	���� ������ �̸��� �����ϴ� ������δ� ThisFunc �Լ� ������ 
	������� num�� ������ �Ұ����ϴ�
	�׷��� this �����͸� Ȱ���ϸ� ������ �����ϴ�

	������ �̸��� ���� ���� �Ű澲�̴� ���̴�
	Ư�� ������ ������ ���ϴ� �� ������ �̸��� �����ǰ� ���� ���� ����Ѵ�
	��� ������ �Ű������� �̸��� �����ϰ� ���� this �����͸� �̿��ؼ� 
	�� ���� �����ϴ� ���� �����ϴ� ���α׷��ӵ鵵 �ִ�
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
	// �ش� ��쿡 ��ȿ
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