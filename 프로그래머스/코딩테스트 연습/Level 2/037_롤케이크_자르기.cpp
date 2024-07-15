/*
날짜 : 2024. 7. 15
이름 : 배성훈
내용 : 롤케이크 자르기
	롤케이크를 두 조각으로 잘라서 동생과 한 조각씩 나눠먹으려고 한다
	롤케이크에는 여러가지 토핑들이 일렬로 올려져 있습니다

	철수와 동생은 롤케이크를 공평하게 나눠먹으려 하는데,
	롤케이크의 크기보다 롤케이크 위에 올려진 토핑들의 종류에 더 관심이 많다

	잘려진 조각들의 크기와 오렬진 토핑의 개수에 상관없이
	각 조각에 동일한 가짓수의 토핑이 올라가면 공평하게 나눠진 것이라 생각한다

	롤케이크에 올려진 토핑들의 번호를 저장한 
	정수 배열 topping이 매개변수로 주어질 때,

	롤케이크를 공평하게 자르는 방법의 수를
	return 하는 solution 함수 구현

	topping의 원소는 1만 이하의 자연수

	parameter
	{ 1, 2, 1, 3, 1, 4, 1, 2 }


	return
	2


	sol
	1 2 1 3  / 1 4 1 2
	이렇게 자르면 서로 3가지 종류의 토핑으로 
	공평하게 자른다

	1 2 1 3 1 / 4 1 2
	이렇게 자르면 서로 3가지 종류의 토핑으로 
	공평하게 자른다

	총 2가지가 있다
*/

#include <vector>
#include <algorithm>

#define MAX 10'001

using namespace std;

int solution(vector<int> _topping)
{

	int answer = 0;

	vector<bool> use(MAX, false);				// 보유 중인 토핑
	vector<int> r(_topping.size() + 1, 0);		// 오른쪽 누적합 토핑

	for (int i = _topping.size() - 1; i >= 0; i--)
	{

		r[i] = use[_topping[i]] ? r[i]: r[i] + 1;
		use[_topping[i]] = true;
	}

	fill(use.begin(), use.end(), false);
	int l = 0;

	for (int i = 0; i < _topping.size(); i++)
	{

		l = use[_topping[i]] ? l : l + 1;
		use[_topping[i]] = true;

		if (l == r[i + 1]) answer++;
		else if (l < r[i + 1]) break;
	}

	return answer;
}