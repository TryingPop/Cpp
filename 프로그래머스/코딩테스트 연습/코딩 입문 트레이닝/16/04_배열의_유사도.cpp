#include <string>
#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 18
이름 : 배성훈
내용 : 배열의 유사도
	같은 원소의 개수로 두 배열이 얼마나 
	유사한지 확인하려고한다
	
	문자열 배열 s1과 s2가 주어질 때,
	같은 원소의 개수를
	return 하도록 solution 함수를 구현

	중복된 원소를 갖지 않는다
*/

using namespace std;

int solution(vector<string> _s1, vector<string> _s2)
{

	int answer = 0;

	// 스위핑 + 두 포인터 알고리즘 적용
	sort(_s1.begin(), _s1.end());
	sort(_s2.begin(), _s2.end());

	int ptr1 = 0;
	int ptr2 = 0;
	
	int max1 = _s1.size();
	int max2 = _s2.size();

	while (ptr1 < max1 && ptr2 < max2)
	{

		// 중복 비허용 시
		// 같은 원소쌍의 최대갯수를 구하는 식으로 해결했다
		if (_s1[ptr1] == _s2[ptr2]) ptr1++, ptr2++, answer++;
		else if (_s1[ptr1] < _s2[ptr2]) ptr1++;
		else ptr2++;
	}

	return answer;
}