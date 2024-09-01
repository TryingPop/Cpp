/*
날짜 : 2024. 9. 1
이름 : 배성훈
내용 : 이모티콘 할인행사
	카카오톡에서는 이모티콘을 무제한으로 사용할 수 있는
	이모티콘 플러스 서비스 가입자 수를 늘릴려고 한다

	이모티콘 할인행사를 하는데,
	목표는 다음과 같다

	1. 이모티콘 플러스 서비스 가입자를 최대한 늘리는 것
	2. 이모티콘 판매액을 최대한 늘리는거

	1번 목표가 우선이며, 2번 목표는 그 다음이다

	이모티콘 할인 행사는 다음과 같은 방식으로 진행된다
	n명의 카카오톡 사용자들이 이모티콘 m개를 할인하여 판매한다

	이모티콘마다 할인율은 다를 수 있으며,
	할인율은 10%, 20%, 30%, 40% 중 하나로 설정된다

	카카오톡 사용자들은 다음과 같은 기준을 따라 이모티콘을 사거나
	이모티콘 플러스 서비스에 가입한다

	각 사용자들은 자신의 기준에 따라 일정 비율 이상 할인하는
	이모티콘을 모두 구매한다

	각 사용자들은 자신의 기준에 따라 
	이모티콘 구매 비용의 합이 일정 가격 이상이 된다면,
	이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입한다

	카카오톡 사용자 n명의 구매 기준을 담은 2차원 정수 배열 users,
	이모티콘 m개의 정가를 담은 1차원 정수 배열 emoticons가 주어질 때,
	행사 목적을 최대한으로 달성했을 때의 이모티콘 플러스 서비스 가입 수와
	이모티콘 매출액을 1차원 정수 배열에 담아 return 하는 solution 함수 구현

	users의 길이는 100 이하인 자연수이고,
	users의 원소는 { 비율, 가격 } 형태인 정수이다
	users[i]는 i + 1 의 구매 기준이다

	비율 %이상의 할인이 있는 이모티콘을 모두 구매한다는 의미이다
	비율은 40이하의 자연수

	가격 이상의 돈을 이모티콘 구매에 사용한다면,
	이모티콘 구매를 모두 취소하고 플러스에 가입한다는 의미이다
	가격은 100만 이하의 자연수이며 100 으로 나눠 떨어진다

	emoticons의 길이는 7 이하이다
	emoticons[i]는 i + 1 번 이모티콘의 정가를 의미한다

	emoticons의 원소는 100만 이하의 자연수이고 100으로 나눠 떨어진다


	parameter
	{ { 40, 10000 }, { 25, 10000 } }, { 7000, 9000 }


	return
	{ 1, 5400 }


	sol
	1번, 2번을 40%로 할인해도 최대 서비스 가입자 수는 1명이다
	이 때 이익을 최대한 챙기는 경우는 1번을 30% 할인하고, 2번을 40% 할인한 경우
	가입자 수는 1명이며, 최대 이익을 챙기는 경우이다
*/

#include <vector>

using namespace std;

inline int ChkPrice(int _p, int _s)
{

	/*
	
	가격 계산
	*/
	return (_p * (100 - _s)) / 100;
}

int join;
int total;

vector<int> sale = { 40, 30, 20, 10 };
vector<int> select;

inline void ChkBuy(vector<vector<int>>& _users, vector<int>& _emoticons)
{

	/*
	
	가입자 수, 이익 계산
	*/

	int ret1 = 0;
	int ret2 = 0;

	for (vector<int>& user : _users)
	{

		// 구매 계산
		int p = 0;
		for (int i = 0; i < select.size(); i++)
		{

			if (sale[select[i]] < user[0]) continue;
			p += ChkPrice(_emoticons[i], sale[select[i]]);
		}

		if (user[1] <= p) ret1++;
		else ret2 += p;
	}

	if (join < ret1)
	{

		join = ret1;
		total = ret2;
	}
	else if (join == ret1 && total < ret2) total = ret2;
}

inline void DFS(vector<vector<int>>& _users, vector<int>& _emoticons, int _depth = 0)
{

	if (_depth == _emoticons.size())
	{

		ChkBuy(_users, _emoticons);
		return;
	}

	for (int i = 0; i < 4; i++)
	{

		select[_depth] = i;
		DFS(_users, _emoticons, _depth + 1);
	}
}

vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons)
{

	/*
	
	브루트포스
	4^7 * 100 <= 200만
	*/
	vector<int> answer;
	select.resize(_emoticons.size());

	DFS(_users, _emoticons);

	answer.push_back(join);
	answer.push_back(total);

	return answer;
}