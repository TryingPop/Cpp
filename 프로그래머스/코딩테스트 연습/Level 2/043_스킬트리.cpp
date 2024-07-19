/*
날짜 : 2024. 7. 19
이름 : 배성훈
내용 : 스킬트리
	선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻한다
	
	예를들어 선행 스킬 순서가 스파크 -> 라이트닝 볼트 -> 썬더 일 때,
	썬더를 배울러면 먼저 라이트닝 볼트를 배워야 하고,
	라이트닝 볼트를 먼저 배우려면 먼저 스파크를 배워야한다

	위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있다
	따라서 스파크 -> 힐링 -> 라이트닝 볼트 -> 썬더는 가능한 스킬트리다
	하지만 썬더 -> 스파크와 같은 스킬트리는 불가능하다

	선행 스킬 순서 skill과 유저들이 만든 스킬트리를 담은 배열
	skill_trees가 매개변수로 주어질 때,

	가능한 스킬트리 개수를 return 하는 solution 함수 구현

	스킬은 알파벳 대문자로 표기하며,
	모든 문자열은 알파벳 대문자로만 이루어져 있다

	스킬 순서와 스킬트리는 문자열로 표기한다
	스킬 트리가 C -> B -> D라면 CBD로 표현한다

	선행 스킬 순서 skill의 길이는 1 이상 26이하이며
	중복되어 주어지지 않는다

	skill_trees는 길이 1이상 20이하인 배열

	skill_trees의 원소는 스킬을 나타내는 문자열
	skill_trees는 길이 2 이상 26이하인 문자열이고
	스킬이 중복해서 주어지지 않는다


	parameter
	"CBD", { "BACDE", "CBADF", "AECB", "BDA" }


	return
	2


	sol
	BACDE는 B를 배우기 위해서는 C가 먼저 와야하는데
	C가 앞에 없어 배우지 못해 불가능한 스킬트리다

	CBADF, AECD는 유효한 스킬트리다

	BDA도 B를 배우기 위해서는 C가 먼저 와야하는데
	C가 앞에 없어 배우지 못해 불가능한 스킬트리다
*/

#include <string>
#include <vector>

using namespace std;

int solution(string _skill, vector<string> _skill_trees)
{

	/*
	
	투 포인터, 해시(?) 문제
	*/
	int answer = 0;

	// 중복이 없고, char형이라
	// vector를 썼다, 만약 복잡한 문자열이면 해시를 써야한다
	vector<int> lvl(128, 0);
	int cur = 1;
	for (const char c : _skill)
	{

		// 해당 스킬의 위상(위계) 저장
		lvl[c] = cur++;
	}

	for (string& tree : _skill_trees)
	{

		bool flag = true;

		// 투 포인터 -> 스킬트리 단계를 가리킨다
		cur = 1;

		for (const char c : tree)
		{

			if (cur < lvl[c])
			{

				// 아직 배우지 못한 스킬이 등장했다
				flag = false;
				break;
			}
			else if (cur == lvl[c]) cur++;
		}

		if (flag) answer++;
	}

	return answer;
}