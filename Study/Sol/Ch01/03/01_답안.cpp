/*
날짜 : 2023. 1. 22
이름 : 배성훈
내용 : 교재 59p 문제1
	예제[ DefaultValue3.cpp에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌,
	'함수의 오버로딩'의 형태로 재 구현해보자. 물론 main 함수는 변경하지 안하야 하며,
	실행결과도 동일해야 한다.
*/

#include<iostream>

int BoxVolume(int length, int width, int height) {

	return length * width * height;
}

int BoxVolume(int length, int width) {

	return length * width * 1;
}

int BoxVolume(int length) {

	return length * 1 * 1;
}

int main(void) 
{

	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	return 0;
}