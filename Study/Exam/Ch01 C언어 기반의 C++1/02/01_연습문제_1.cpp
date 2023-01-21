#include <iostream>
using namespace std;

/*

��¥ : 2023. 1. 22
�̸� : �輺��
���� : ���� 26p ����1
	���� main �Լ����� �ʿ�� �ϴ� swap �Լ��� �����ε� �ؼ� �����غ���.

	int main(void)
	{
		int num1 = 20, num2 = 30;
		swap(&num1, &num2);
		std::cout<<num1<<' '<<num2<<std::endl;

		char ch1='A', ch2='Z';
		swap(&ch1, &ch2);
		std::cout<<ch1<<' '<<ch2<<std::endl;

		double dbl1=1.111, dbl2=5.555;
		swap(&dbl1, &dbl2);
		std::cout<<dbl1<<' '<<dbl2<<std::endl;
		return 0;
	}
*/

// swap �����ε� �Լ��� ����
// ���� ���� * : �ּҸ� �޾ƿ´ٴ� ǥ��
// �ּ��� swap�� �ƴ� ���� swap�̴�
void swap(int *num1, int *num2) {

	int temp;		// temp ����
	temp = *num1;	// temp�� �ּ� *num1�� ����Ű�� ���� �����Ѵ�
	*num1 = *num2;	// �ּ� num1�� �ּ� num2�� ����Ű�� ���� �����Ѵ�
	*num2 = temp;	// �ּ� num2�� temp ���� �����Ѵ�

	return;
}

void swap(char *ch1, char *ch2) {
	char temp;
	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;

	return;
}

void swap(double *dbl1, double *dbl2) {
	double temp;
	temp = *dbl1;
	*dbl1 = *dbl2;
	*dbl2 = temp;

	return;
}

int main(void)
{

	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout << dbl1 << ' ' << dbl2 << endl;
	return 0;
}