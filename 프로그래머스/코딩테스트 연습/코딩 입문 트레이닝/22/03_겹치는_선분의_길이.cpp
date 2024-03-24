#include <vector>

/*
날짜 : 2024. 3. 24
이름 : 배성훈
내용 : 겹치는 선분의 길이
	선분이 { start, end } 형태로 놓여 있다
	두 개 이상의 선분이 겹치는
	lines는 이러한 선분을 모아놓은 2차원 배열이고,
	lines가 매개변수로 주어질 때,
	부분의 길이를 return 하는 solution 함수 구현

	lines의 길이 범위는 -100 ~ 100이다
*/

using namespace std;

int solution(vector<vector<int>> _lines)
{

	int answer = 0;

	// 누적합
	vector<int> temp(202, 0);

	for (vector<int>& line : _lines) 
	{

		// 선분 위치 인덱스에 맞춰 조정
		int s = line[0] + 100;
		int e = line[1] + 100;

		// 선분의 시작지점과 끝지점 저장
		temp[s]++;
		temp[e]--;
	}

	int sum = 0;
	for (int i = 0; i < 202; i++)
	{

		// 2개 이상 만나는 곳에 한해 길이를 카운트
		sum += temp[i];
		if (2 <= sum) answer++;
	}

	return answer;
}