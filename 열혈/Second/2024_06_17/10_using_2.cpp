/*
날짜 : 2024. 6. 17
이름 : 배성훈
내용 : using을 이용한 이름공간의 명시
	교재 p46
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{

	int num = 20;

	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;

	return 0;
}