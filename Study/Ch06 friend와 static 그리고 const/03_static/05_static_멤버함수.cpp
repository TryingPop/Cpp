/*
��¥ : 2023. 2. 3
�̸� : �輺��
���� : static ����Լ�
	����� Ŭ������ ��� ��ü�� �����Ѵ�
	public���� ����Ǹ�, Ŭ������ �̸��� �̿��ؼ� ȣ���� �����ϴ�
	��ü�� ����� �����ϴ� ���� �ƴϴ�

	static ����Լ� �������� static ��������� static ����Լ��� ȣ���� �����ϴ�

	static ��������� static ����Լ��� ��κ��� ��쿡 �־ ���������� �����Լ��� ��ü�� �� �ִ�
*/

class SoSimple {

private:
	int num1;
	static int num2;

public:
	SoSimple(int n)
		: num1(n) { }

	static void Adder(int n) {

		// num1 += n;	// num1�� static ��� ������ �ƴ϶� ����
		num2 += n;
	}
};

int SoSimple::num2 = 0;

