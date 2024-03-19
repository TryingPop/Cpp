#include <string>

/*
날짜 : 2024. 3. 19
이름 : 배성훈
내용 : 자릿수 더하기
	정수 n이 매개변수로 주어질 때
	n의 각 자리 숫자의 합을
	return 하도록 solution 함수를 구현
*/

using namespace std;

int solution(int _n)
{

	int answer = 0;
	string numStr = to_string(_n);

	for (const char c : numStr)
	{

		answer += c - '0';
	}

	return answer;
}