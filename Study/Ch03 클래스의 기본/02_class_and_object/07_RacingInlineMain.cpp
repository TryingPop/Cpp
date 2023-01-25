/*
날짜 : 2023. 1. 25
이름 : 배성훈
내용 : Inline을 이용해 RacingCar class의 분할
	소스파일 : 메인 함수 정의
*/

#include "05_CarInline.h"

int main(void) 
{

	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}