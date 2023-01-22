/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 57p 문제2
	프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서,
	입력 받은 데이터를 그대로 출력하는 프로그램을 작성해 보자.
*/

#include <iostream>

int main(void) 
{
	
	char name[50];
	char phoneNumber[50];

	std::cout << "이름: ";
	std::cin >> name;
	std::cout << "전화번호: ";
	std::cin >> phoneNumber;

	std::cout << "당신의 이름: " << name << std::endl;
	std::cout << "당신의 전화번호: " << phoneNumber << std::endl;
	return 0;
}