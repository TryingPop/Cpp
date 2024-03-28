#include <string>

/*
날짜 : 2024. 3. 28
이름 : 배성훈
내용 : k의 개수
	1부터 13까지의 수에서 1은 1, 10, 11, 12, 13
	이렇게 총 6번 등장

	정수 i, j , k가 매개변수로 주어질 때,
	i부터 j까지 k가 몇 번 등장하는지
	return 하는 solution 함수 구현

	i, j는 10만 이하인 자연수이고, i < j
	k는 9 이하의 음이아닌 정수
*/

using namespace std;

int solution(int _i, int _j, int _k)
{

	int answer = 0;
	string numStr;
	numStr.reserve(6);
	for (int i = _i; i <= _j; i++)
	{

		numStr = to_string(i);
		for (const char c : numStr)
		{

			if (c - '0' == _k) answer++;
		}
	}

	return answer;
}