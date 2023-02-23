/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ���ø�
	template <typename T> �� tempalte <> ������

	template <typename T> �� ��� T�� ���� ������ �ʿ��� ��� ���
	template <>�� ������ �ʿ���� ��� ���
*/

#include <iostream>
using namespace std;


template<typename T>
class SoSimple {

private:
	static int mem;

public:
	void SimpleFunc() {

		cout << mem << endl;
	}
};



template<>
class SoSimple<int> {

private:
	static int mem;

public:
	void SimpleFunc() {

		cout << mem << endl;
	}
};


template<typename T>
int SoSimple<T>::mem = 0;
int SoSimple<int>::mem = 1;			// �ٷ� �ؿ� �����ؾ��� ������ ������ �ȶ��

template<>
// int SoSimple<int>::mem = 1;		// ��������� Ư��Ȱ �� �� ���ٰ� ������ �������
int SoSimple<double>::mem = 2;

int main(void) {

	SoSimple<short> obj1;
	SoSimple<int> obj2;
	SoSimple<double> obj3;

	obj1.SimpleFunc();	// 0
	obj2.SimpleFunc();	// 1
	obj3.SimpleFunc();	// 2
	return 0;
}