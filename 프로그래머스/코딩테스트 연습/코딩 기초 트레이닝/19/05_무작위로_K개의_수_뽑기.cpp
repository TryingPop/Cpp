#include <vector>
#include <map>

/*
날짜 : 2024. 2. 25
이름 : 배성훈
내용 : 무작위로 k개의 수 뽑기
	정수 배열 arr, 정수 k가 주어진다
	앞에서부터 하나씩 탐색할 때,
	arr의 서로 다른 k개의 원소를 순서대로 이어 붙인
	배열을 반환하는 solution 함수를 구현
	만약 k개가 안될 시 -1로 채운다
*/

using namespace std;

vector<int> solution(vector<int> _arr, int _k)
{

	vector<int> answer;

	map<int, int> m;

	for (int i = 0; i < _arr.size(); i++)
	{

		if (m.count(_arr[i])) continue;

		// 중복 방지용 기록
		m.insert({ _arr[i], 0 });
		answer.push_back(_arr[i]);

		// _k 채우면 탈출
		if (answer.size() == _k) break;
	}

	// 부족한 부분 -1로 채우기
	for (int i = answer.size(); i < _k; i++)
	{

		answer.push_back(-1);
	}

	return answer;
}