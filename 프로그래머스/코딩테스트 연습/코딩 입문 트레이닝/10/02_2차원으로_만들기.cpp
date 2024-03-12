#include <vector>

/*
날짜 : 2024. 3. 12
이름 : 배성훈
내용 : 2차원으로 만들기
	정수 배열 num_list와 정수 n이 매개변수로 주어질 때,
	num_list를 2차원 배열로 바꿔 return 하는 solution 함수 구현

	num_list의 사이즈를 l이라 하면 num_list를 앞에서 부터 n개씩 묶어
	l / n * n 사이즈의 2차원 배열을 만들어야 한다

	예를들어 num_list = { 1, 2, 3, 4, 5, 6 } 이고, n = 3이면
	{ { 1, 2, 3 }, { 4, 5, 6 } }인 배열로 만든다
*/

using namespace std;

vector<vector<int>> solution(vector<int> _num_list, int _n)
{

	// 크기 설정
	vector<vector<int>> answer(_num_list.size() / _n, vector<int>(_n));

	int idx1 = 0;
	int idx2 = 0;
	for (const int i : _num_list)
	{

		answer[idx1][idx2] = i;
		idx2++;
		if (idx2 == _n)
		{

			idx1++;
			idx2 = 0;
		}
	}

	return answer;
}