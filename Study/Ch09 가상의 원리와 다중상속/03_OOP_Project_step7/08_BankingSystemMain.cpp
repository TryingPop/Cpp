/*
날짜 : 2023. 2. 12
이름 : 배성훈
내용 : 은행계좌 관리 프로그램
	코드파일 : 메인함수
*/

#include "05_AccountHandler.h"


int main(void) {

	AccountHandler program;

	program.Start();

	delete &program;
}