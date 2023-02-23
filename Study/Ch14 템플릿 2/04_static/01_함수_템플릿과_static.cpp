/*
날짜 : 2023. 2. 24
이름 : 배성훈
내용 : 함수 템플릿과 static
	함수 템플릿에서 static 지역변수는 함수별로 하나씩 존재한다
*/

#include <iostream>
using namespace std;

template <typename T>
void ShowStaticValue(void) {

	static T num = 0;
	num += 1;
	cout << num << " ";
}

int main(void) {

	ShowStaticValue<int>();		// 1
	ShowStaticValue<int>();		// 2
	ShowStaticValue<int>();		// 3
	cout << endl;

	ShowStaticValue<long>();	// 1
	ShowStaticValue<long>();	// 2
	ShowStaticValue<long>();	// 3
	cout << endl;

	ShowStaticValue<double>();	// 1
	ShowStaticValue<double>();	// 2
	ShowStaticValue<double>();	// 3
	return 0;
}