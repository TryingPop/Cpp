/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : BoundCheckAccountPtrArray 클래스의 정의
*/

#include "07_AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len)
	: arrlen(len) {

	arr = new ACC_PTR[len];
}

ACC_PTR& BoundCheckAccountPtrArray::operator[](int idx) {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

ACC_PTR BoundCheckAccountPtrArray::operator[](int idx) const {

	if (idx < 0 || idx >= arrlen) {

		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const {

	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {

	for (int idx = 0; idx < arrlen; idx++) {

		delete arr[idx];
	}
	
	delete[] arr;
}