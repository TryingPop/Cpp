#include <vector>
#include <string>

/*
날짜 : 2024. 3. 23
이름 : 배성훈
내용 : 외계어 사전
	알파벳이 담긴 배열 speel과
	외계어 사전 dic이 매개변수로 주어질 때,

	speel에 담긴 알파벳을 한번씩만 모두 사용한
	단어가 dic에 존재한다면 1,
	존재하지 않는다면 2를 return 하도록
	solution 함수 구현

	spell의 원소의 크기는 1이다
	spell의 원소를 모두 사용해
	단어를 만들어야 한다
*/

using namespace std;

int solution(vector<string> _spell, vector<string> _dic)
{

	int answer = 2;

	vector<int> cnt(26, 0);

	for (const string str : _dic)
	{

		for (const char c : str)
		{

			// 사용한 단어 기록
			int idx = c - 'a';
			cnt[idx]++;
		}

		bool exsist = true;
		for (const string c : _spell)
		{

			// 스펠의 단어를 모두 1번씩만 
			// 사용했는지 확인
			int idx = c[0] - 'a';
			if (cnt[idx] != 1) exsist = false;
			cnt[idx] = 0;
		}

		if (!exsist) continue;
		// 발견한 경우 1로하고 종료
		answer = 1;
		break;
	}

	return answer;
}