/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : ������� ���� ���α׷�
	������� : BoundCheckArray Ŭ������ ����� ����
*/

#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class BoundCheckArray {

private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& ref) { }
	BoundCheckArray& operator=(const BoundCheckArray& ref) { }

public:
	BoundCheckArray(int len = 100);
	
	T& operator[](int idx);
	T operator[](int idx) const;

	int GetArrLen() const;

	~BoundCheckArray();
};

template<class T>
BoundCheckArray<T>::BoundCheckArray(int len) 
	: arrlen(len) {

	arr = new T[len];
}

template<class T>
T& BoundCheckArray<T>::operator[](int idx) {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

template<class T>
T BoundCheckArray<T>::operator[](int idx) const {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

template<class T>
int BoundCheckArray<T>::GetArrLen() const {

	return arrlen;
}

template<class T>
BoundCheckArray<T>::~BoundCheckArray() {

	delete[] arr;
}
#endif