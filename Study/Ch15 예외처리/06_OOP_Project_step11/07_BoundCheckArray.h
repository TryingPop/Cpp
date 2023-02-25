/*
날짜 : 2023. 2. 26
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	교재 625p

	헤더파일 : AccountHandler 클래스의 선언과 정의
*/

#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include "10_BankingCommonDecl.h"

template<typename T>
class BoundCheckArray {

private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }

public:
	BoundCheckArray(int len = 100);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;

	~BoundCheckArray();
};


template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len)
	: arrlen(len) {

	arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx) {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {

	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {

	delete[] arr;
}

#endif