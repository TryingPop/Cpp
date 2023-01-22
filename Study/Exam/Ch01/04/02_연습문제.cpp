/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 43p 문제1
	교재 40p의 예제 NameSp2.cpp를 다음과 같이 총 3개의 파일로 분할해서 컴파일 해보자.
	헤더파일 main 함수를 제외한 나머지 두 함수의 선언을 삽입한다.
	소스파일1 main 함수를 제외한 나머지 두 함수의 정의를 삽입한다.
	소스파일2 main 함수만 삽입한다.

	파일의 이름은 여러분이 임의로 정해도 된다.
	하지만, 각 파일에 들어갈 내용은 위의 지시대로 진행해야 한다.

*/
#include <iostream>
#include "01_연습문제.h"
using namespace std;

// 소스파일1
void BestComImpl::SimpleFunc(void) {

	cout << "BestCom이 정의한 함수" << endl;
}

void ProgComImpl::SimpleFunc(void) {

	cout << "ProgCom이 정의한 함수" << endl;
}