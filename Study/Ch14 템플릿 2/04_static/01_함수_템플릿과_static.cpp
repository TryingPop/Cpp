/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : �Լ� ���ø��� static
	�Լ� ���ø����� static ���������� �Լ����� �ϳ��� �����Ѵ�
*/

#include <iostream>
using namespace std;

template <typename T>
void ShowStaticValue(void) {

	static T num = 0;
	num += 1;
	cout << num << " ";
}

int main(void) {

	ShowStaticValue<int>();		// 1
	ShowStaticValue<int>();		// 2
	ShowStaticValue<int>();		// 3
	cout << endl;

	ShowStaticValue<long>();	// 1
	ShowStaticValue<long>();	// 2
	ShowStaticValue<long>();	// 3
	cout << endl;

	ShowStaticValue<double>();	// 1
	ShowStaticValue<double>();	// 2
	ShowStaticValue<double>();	// 3
	return 0;
}