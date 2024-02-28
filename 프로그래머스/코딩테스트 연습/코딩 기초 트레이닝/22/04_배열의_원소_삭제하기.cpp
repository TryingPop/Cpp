#include <vector>

/*
날짜 : 2024. 2. 28
이름 : 배성훈
내용 : 배열의 원소 삭제하기
	정수 배열 arr과 delete_list가 있다
	arr의 원소 중 delete_list의 원소를 모두 삭제하고
	남은 원소들은 기존의 arr에 있던 순서를 유지한 배열을
	return하는 solution 함수를 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr, vector<int> _delete_list)
{

	vector<int> answer;

	for (const int i : _arr)
	{

		bool chk = true;
		for (const int j : _delete_list)
		{

			if (i == j)
			{

				chk = false;
				break;
			}
		}

		if (chk) answer.emplace_back(i);
	}
	return answer;
}