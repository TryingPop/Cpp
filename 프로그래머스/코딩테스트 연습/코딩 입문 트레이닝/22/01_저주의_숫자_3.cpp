#include <string>

/*
날짜 : 2024. 3. 24
이름 : 배성훈
내용 : 저주의 숫자 3
	3x 마을에서는 3의 배수와 숫자 3이
	들어가는 숫자를 사용하지 않는다

	정수 n이 매개변수로 주어질 때,
	n을 3x 마을에서 사용하는 숫자로 바꿔
	return 하는 soltuion 함수를 구현
*/

using namespace std;

int solution(int _n)
{

	int answer = 0;

	int idx = 0;
	for (int i = 1; i <= 1'000; i++)
	{

		// 3의 배수 제외
		if (!(i % 3)) continue;
		string iStr = to_string(i);

		bool isBreak = false;
		for (const char c : iStr)
		{

			// 3을 포함하는 수 제외
			if (c != '3') continue;
			isBreak = true;
			break;
		}

		if (isBreak) continue;
		idx++;

		if (idx != _n) continue;
		answer = i;
		break;
	}

	return answer;
}