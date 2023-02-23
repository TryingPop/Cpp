/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 확장된 템플릿
	코드파일 : main 함수 정의
*/

#include<iostream>
#include "01_PointTemplate.h"
#include "02_ArrayTemplate.h"

using namespace std;

int main(void)
{

	BoundCheckArray<Point<int>> oarr1(3);
	oarr1[0] = Point<int>(3, 4);
	oarr1[1] = Point<int>(5, 6);
	oarr1[2] = Point<int>(7, 8);

	for (int i = 0; i < oarr1.GetArrLen(); i++) {

		oarr1[i].ShowPosition();
	}

	BoundCheckArray<Point<double>> oarr2(3);
	oarr2[0] = Point<double>(3.14, 4.31);
	oarr2[1] = Point<double>(5.09, 6.07);
	oarr2[2] = Point<double>(7.82, 8.54);

	for (int i = 0; i < oarr2.GetArrLen(); i++) {

		oarr2[i].ShowPosition();
	}

	typedef Point<int>* POINT_PTR;
	BoundCheckArray<POINT_PTR> oarr3(3);
	oarr3[0] = new Point<int>(11, 12);
	oarr3[1] = new Point<int>(13, 14);
	oarr3[2] = new Point<int>(15, 16);

	for (int i = 0; i < oarr3.GetArrLen(); i++) {

		oarr3[i]->ShowPosition();
	}

	delete oarr3[0];
	delete oarr3[1];
	delete oarr3[2];
	return 0;
}