/*
날짜 : 2024. 6. 24
이름 : 배성훈
내용 : main
	교재 p134

	컴파일러는 파일 단위로 컴파일 한다!
	A.cpp와 B.cpp를 동시에 컴파일해서 하나의 실행파일을 만든다 해도,
	A.cpp의 컴파일 과정에서 B.cpp를 참조하지 않으며
	B.cpp의 컴파일 과정에서 A.cpp를 참조하지 않는다
*/

#include "07_CarInline.h"

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