/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : explicit Ű����
	��ȯ�� ���� �ʱ�ȭ�� ���� Ű����

	�ڵ��� ��Ȯ���� ���ϱ� ���ؼ� ���� ���Ǵ� Ű����
*/

class SoSimple {

private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2) { }

	// ���� ���� const�� copy�� ���� �� ������ ���� ���� �־���
	explicit SoSimple(const SoSimple& copy)	
		: num1(copy.num1), num2(copy.num2) { }
};

class A {

private:
	int num;

public:
	explicit A(int n) 
		: num(n) { }
};

int main(void)
{

	SoSimple sim1(2, 3);
	// SoSimple sim2 = sim1; // ����
	SoSimple sim2(sim1);

	// A obj = 3; // ��ó�� �����ϴ� ���� ���� ���ؼ��� ���
	A obj(3);
}