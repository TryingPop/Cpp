/*
��¥ : 2024. 7. 6
�̸� : �輺��
���� : ��� �̴ϼȶ�����(Member Initializer)�� �̿��� ��� �ʱ�ȭ
	���� p175 ~ 176

	��ü�� �����ϴ� �������� Ŭ������ �����ڸ� �̿��� ��ü�� �ʱ�ȭ�� �� �ִ�
	�����ڴ� �ʱ�ȭ�� �������� ���ǰ� �Ǵ�,
	��ü �������������� ������ ȣ���� ��ü�� �ʱ�ȭ�� �Ѱ� �����ϰ� �Ѵ�
	�̴� �̴ϼ� ��������� ���� �̿��ϸ� �ȴ�

	�Ʒ� ������ ����
	��ü a�� ������������ _anum1, _anum2�� ���ڷ� ���޹޴� �����ڸ� ȣ���ϰ�
	��ü b�� ������������ _bnum1, _bnum2�� ���ڷ� ���޹޴� �����ڸ� ȣ���϶�� �ǹ��̴�
*/

class A
{

private:
	int num1;
	int num2;

public:
	A(const int& _num1, const int& _num2)
	{

		num1 = _num1;
		num2 = _num2;
	}
};

class AA
{

private:
	A a;
	A b;

public:
	AA(const int& _anum1, const int& _anum2, const int& _bnum1, const int& _bnum2)
		// ��� �̴ϼȶ�����
		: a(_anum1, _anum2), b(_bnum1, _bnum2)
	{ }
};