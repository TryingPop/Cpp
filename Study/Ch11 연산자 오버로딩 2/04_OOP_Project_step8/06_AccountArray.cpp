/*
날짜 : 2023. 2. 17
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : BoundCheckAccountPtrArray 클래스 정의
*/

#include "05_AccountArray.h"
#include <cstdlib>

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len)
	: arrlen(len) {

	arr = new ACC_PTR[len];
}

ACC_PTR& BoundCheckAccountPtrArray::operator[](int idx) {

	if (idx < 0 || idx >= arrlen) {

		cout << "인덱스 범위가 일치하지 않습니다" << endl;
		exit(1);
	}
	
	return arr[idx];
}

ACC_PTR& BoundCheckAccountPtrArray::operator[](int idx) const {

	if (idx < 0 || idx >= arrlen) {

		cout << "인덱스 범위가 일치하지 않습니다" << endl;
		exit(1);
	}
	
	return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const {

	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {

	delete[] arr;
}