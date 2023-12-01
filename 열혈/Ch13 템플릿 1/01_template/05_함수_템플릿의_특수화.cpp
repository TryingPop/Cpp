/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 함수 템플릿의 특수화
	특수화가 필요한 예제
*/

#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {

	return a > b ? a : b;
}

int main(void)
{

	cout << Max(11, 15) << endl;			// 15
	cout << Max('T', 'Q') << endl;			// T
	cout << Max(3.5, 7.5) << endl;			// 7.5
	// 아래는 주소값을 반환하므로 의미없는 비교
	cout << Max("Simple", "Best") << endl;	// Best
	return 0;
}