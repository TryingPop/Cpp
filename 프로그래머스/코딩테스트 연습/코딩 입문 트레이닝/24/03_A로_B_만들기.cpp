#include <string>
#include <vector>

/*
날짜 : 2024. 3. 28
이름 : 배성훈
내용 : A로 B 만들기
	문자열 before와 after가 매개변수로 주어질 때,
	before의 순서를 바꾸어 after를 만들 수 있으면 1을,
	만들 수 없으면 0을 return 하도록 solution 함수 구현

	before와 after의 길이는 항상 같다
	before와 after는 소문자로만 이루어져 있다
*/

using namespace std;

int solution(string _before, string _after)
{

	int answer = 1;

	// 알파벳 개수
	vector<int> cnt(26, 0);

	for (int i = 0; i < _before.length(); i++) 
	{

		// before은 +, after는 - 
		// 알파벳 개수가 같다면 모두 0
		// 이 경우만 before을 바꾸어 after로 바꿀 수 있다
		cnt[_before[i] - 'a']++;
		cnt[_after[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{

		if (!cnt[i]) continue;
		answer = 0;
		break;
	}

	return answer;
}