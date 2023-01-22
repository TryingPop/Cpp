/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 60p
	교재 40p의 예제 NameSp2.cpp를 다음과 같이 총 3개의 파일로 분할해서 컴파일 해보자.
	소스파일1 main 함수를 제외한 나머지 두 함수의 정의를 삽입한다.
*/

#include <iostream>
#include "SimpleFunc.h"

void BestComImpl::SimpleFunc(void) {

	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {

	std::cout << "ProgCom이 정의한 함수" << std::endl;
}