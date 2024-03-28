#include <string>

/*
날짜 : 2024. 3. 28
이름 : 배성훈
내용 : 이진수 더하기
	이진수를 의미하는 두 개의 문자열 
	bin1과 bin2가 매개변수로 주어질 때,
	두 이진수의 합 문자열을 return 하도록 solution 함수 구현

	bin1과 bin2의 길이는 10이하이다
	0을 제외하고는 0으로 시작하지 않는다
*/

using namespace std;

int sToi(string& _str) 
{

	int ret = 0;
	for (int i = _str.length() - 1; i >= 0; i--)
	{

		if (_str[i] == '1') ret |= 1 << i;
	}

	return ret;
}

string solution(string _bin1, string _bin2)
{

	string answer;
	// 이진수 덧셈에서 10자리 + 10자리 <= 11자리
	answer.reserve(11);

	int b1 = sToi(_bin1);
	int b2 = sToi(_bin2);

	int add = b1 + b2;
	bool start = false;
	for (int i = 10; i >= 0; i--)
	{

		if (!start)
		{

			if ((1 << i) & add) 
			{ 
				
				answer.push_back('1'); 
				start = true;
			}

			continue;
		}

		if ((1 << i) & add) answer.push_back('1');
		else answer.push_back('0');
	}

	if (answer.empty()) answer.push_back('0');
	return answer;
}