#include <string>
#include <vector>
#define MUL 26

/*
날짜 : 2024. 3. 26
이름 : 배성훈
내용 : 옹알이 1
	문자열 배열 babbling이 매개변수로 주어질 때,
	babbling에서 aya, ye, woo, ma 네 가지 발음을 최대
	한 번씩 사용해 조합한 단어의 개수를 return하도록
	solution 함수를 구현

	babbling의 각 문자열에서 aya, ye, woo, ma는
	각각 최대 1번씩만 등장한다

	문자열은 알파벳 소문자로만 이루어져 있다
*/

using namespace std;

int solution(vector<string> _babbling)
{

	int answer = 0;

	// 문자를 숫자로 봐서 해결
	int i1 = 'a' * MUL * MUL + 'y' * MUL + 'a';
	int i2 = 'y' * MUL + 'e';
	int i3 = 'w' * MUL * MUL + 'o' * MUL + 'o';
	int i4 = 'm' * MUL + 'a';

	for (const string str : _babbling)
	{

		int calc = 0;
		for (const char c : str)
		{

			if (20'000 < calc) break;

			calc = calc * MUL + c;

			if (calc == i1 || calc == i2 || calc == i3 || calc == i4) calc = 0;
		}

		if (!calc) answer++;
	}

	return answer;
}