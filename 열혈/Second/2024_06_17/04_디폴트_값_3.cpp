/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : 부분적 디폴트 값 설정
	교재 p30 ~ 32

	매개변수 전부를 디폴트 값으로 지정할 수 있지만 
	매개변수의 일부만 디폴트 값을 지정할 수 있다

	매개변수의 일부만 디폴트 값으로 선언하는 경우
	디폴트 값 선언하는 매개변수들은 오른쪽에 위치해야한다

	함수에 전달되는 인자가 왼쪽에서 오른쪽으로 채워지기 때문에
	왼쪽에 디폴트 값을 주는 경우 오른쪽에만 전달하는게 불가능하다고 보면 된다

	만약 아래 예제에서 주석처리한 함수가 정의된다면
	컴파일러는 어떤 함수를 불러올지 몰라 컴파일 에러를 발생시킨다
*/

#include <iostream>

int BoxVolume(int _length, int _width = 1, int _height = 1);
// int BoxVolume(int _length) { return _length; } 
int main(void)
{

	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;	// 27
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;	// 25
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;		// 7

	return 0;
}

int BoxVolume(int _length, int _width, int _height)
{

	return _length * _width * _height;
}

