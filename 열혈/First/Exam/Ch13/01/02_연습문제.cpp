/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ���� 536p ����2
	������ int�� �迭�� ����� ���� ��� ���ؼ� �� ����� ��ȯ�ϴ� ����� �Լ��̴�.
	int SumArray(int arr[], int len) {

		int sum = 0;
		for (int i = 0; i < len; i++) {
			
			sum += arr[i];
		}

		return sum;
	}

	�� �Լ��� ���ø����� �����Ͽ�, �پ��� �ڷ����� �迭�� ������� ���� ����ϴ� ������ �ۼ��غ���
*/

#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len) {

	T sum = 0;
	for (int i = 0; i < len; i++) {

		sum += arr[i];
	}

	return sum;
}

int main(void)
{

	
	int iarr[3];
	for (int i = 0; i < 3; i++) {

		iarr[i] = (i + 1) * 7;
	}

	cout << SumArray<int>(iarr, 3) << endl;	// 42

	double darr[3];

	for (int i = 0; i < 3; i++) {

		darr[i] = (i + 1) * 0.3;
	}

	cout << SumArray(darr, 3) << endl;	// 1.8

	return 0;
}