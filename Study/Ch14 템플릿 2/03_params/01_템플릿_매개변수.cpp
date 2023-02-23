/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ���ø� ����
	template<typename T1, typename T2> ����
	T1, T2 �� ���ø� �Ű������� �Ѵ�.
	�׸��� �Ű������� ���޵Ǵ� �ڷ��� ������ ������ ���ø� ���ڶ� �Ѵ�

	���ø� �Ű��������� ������ ������ �� �� �ִ�
*/

#include<iostream>
using namespace std;

// �迭�� ���̸� ���ø� �Ű������� �����Ѵ�
template<typename T, int len>
class SimpleArray {

private:
	T arr[len];

public:
	T& operator[] (int idx) {

		return arr[idx];
	}

	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref) {

		for (int i = 0; i < len; i++) {
			
			arr[i] = ref.arr[i];
		}
		return *this;
	}
};

int main(void) 
{

	SimpleArray<int, 5> i5arr1;
	for (int i = 0; i < 5; i++) {

		i5arr1[i] = i * 10;
	}

	SimpleArray<int, 5> i5arr2;
	// �迭�� ���̰� ���Ƽ� ���� ���ǵ� ���Կ����� �̿� ����
	i5arr2 = i5arr1;
	for (int i = 0; i < 5; i++) {

		cout << i5arr2[i] << ", ";
	}
	cout << endl;

	SimpleArray<int, 7> i7arr1;
	for (int i = 0; i < 7; i++) {

		i7arr1[i] = i * 10;
	}

	SimpleArray<int, 7> i7arr2;
	i7arr2 = i7arr1;
	for (int i = 0; i < 7; i++) {

		cout << i7arr2[i] << ", ";
	}
	cout << endl;
	return 0;
}