#include <string>
/*
날짜 : 2024. 2. 27
이름 : 배성훈
내용 : 정수 부분
	실수 flo가 매개변수로 주어질 때,
	flo의 정수 부분을 return 하도록 solution 함수를 구현
*/

using namespace std;

int solution(double flo)
{

	// int answer = (int)flo;
	int answer = 0;

	string strFlo = to_string(flo);
	for (const char c : strFlo)
	{

		if (c == '.') break;
		answer = answer * 10 + c - '0';
	}

	return answer;
}