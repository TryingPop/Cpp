/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 둘 이상의 형에 템플릿 선언
	둘 이상의 형에 템플릿을 선언해보자
*/

#include <iostream>
using namespace std;

// template <typename T1, typename T2> 로 정의해도 된다
template <class T1, class T2>
void ShowData(double num) {

	cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)
{

	ShowData<char, int>(65);			// A, 65
	ShowData<char, int>(67);			// C, 67
	ShowData<char, double>(68.9);		// D, 68.9
	ShowData<short, double>(69.2);		// 69, 69.2
	ShowData<short, double>(70.4);		// 70, 70.4
	return 0;
}