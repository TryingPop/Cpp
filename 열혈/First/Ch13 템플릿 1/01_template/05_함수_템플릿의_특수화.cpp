/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : �Լ� ���ø��� Ư��ȭ
	Ư��ȭ�� �ʿ��� ����
*/

#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {

	return a > b ? a : b;
}

int main(void)
{

	cout << Max(11, 15) << endl;			// 15
	cout << Max('T', 'Q') << endl;			// T
	cout << Max(3.5, 7.5) << endl;			// 7.5
	// �Ʒ��� �ּҰ��� ��ȯ�ϹǷ� �ǹ̾��� ��
	cout << Max("Simple", "Best") << endl;	// Best
	return 0;
}