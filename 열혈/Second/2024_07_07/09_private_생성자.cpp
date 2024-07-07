/*
��¥ : 2024. 7. 7
�̸� : �輺��
���� : private ������
	���� p186 ~ 187

	�ռ� ���� �����ڵ��� ��� public���� ����Ǿ���

	��ü�� ������ Ŭ������ �ܺο��� ����Ǹ�
	�����ڴ� public���� ����Ǿ�� �Ѵ�

	Ŭ���� ���ο��� ��ü�� �����Ѵٸ�,
	�����ڰ� private�� ����Ǿ�� �Ѵ�

	�Ʒ� ������ ����,
	�� ������ ������ ��ü�� ������ ���·� ��ȯ�ϰ� �ִ�
	�̴� ���� ����� �޸� ������ ������ �����Ͽ� �����ڸ� ���� ������ �����ϴ�
	��� ����� �ٽ� �ѹ� Ȯ�ν��� �ش�

	private�� ����� �����ڸ� ���ؼ��� ��ü�� ������ �������� �� �� �ִ�
	������ private �����ڵ� ���δ� �����ϰ� ����� �ȴ�
	��ü�� ��������� �����ϰ��� �ϴ� ��쿡�� �ſ� �����ϰ� ����� �ȴ�
*/

#include <iostream>

using namespace std;

class AAA
{

private:
	int num;

public:
	AAA() : num(0) { }
	AAA& CreateInitObj(int n) const
	{

		AAA* ptr = new AAA(n);
		return *ptr;
	}

	void ShowNum() const { cout << num << endl; }

private:
	AAA(int n) : num(n) { }
};

int main(void)
{

	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;

	return 0;
}