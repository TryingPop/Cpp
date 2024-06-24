/*
날짜 : 2024. 6. 24
이름 : 배성훈
내용 : main
	교재 p130 ~ 131

	파일을 분할하면 클래스를 구성하는 멤버의 파악도 한결 수월해졌다
	그리고 뭔가 정리된 느낌도 든다

	파일의 분할은 계속하다보면 기준을 자연스럽게 알게 된다
*/

#include "04_Car.h"

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