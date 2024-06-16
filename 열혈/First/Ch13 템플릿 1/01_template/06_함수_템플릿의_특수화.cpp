/*
날짜 : 2023. 2. 22
이름 : 배성훈
내용 : 함수 템플릿의 특수화
	앞의 예제에서 함수 템플릿의 특수화를 해보자
*/

#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {

	return a > b ? a : b;
}

// 문자열은 길이 비교
// 컴파일러에게 char* 형 템플릿 함수가 필요한 경우 
// 별도로 만들지 말고 이것을 써라는 의미
template <>
char* Max(char* a, char* b) {

	cout << "char* Max<char*>(char*, char*)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max(const char* a, const char* b) {

	cout << "const char* Max<const char*>(const char*, const char*)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{

	cout << Max(11, 15) << endl;			// 15
	cout << Max('T', 'Q') << endl;			// T
	cout << Max(3.5, 7.5) << endl;			// 7.5
	cout << Max("Simple", "Best") << endl;	// const char* Max...
											// Simple

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;		// char* Max...
											// Simple
	return 0;
}