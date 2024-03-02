#include <vector>

/*
날짜 : 2024. 3. 2
이름 : 배성훈
내용 : 정사각형으로 만들기
	이차원 정수 배열 arr이 매개변수로 주어진다
	arr의 행의 개수가 더 많다면
	열의 수가 행의 수와 같아지도록
	각 행의 끝에 0을 추가하고

	열의 수가 더 많다면 행의 수가
	열의 수와 같아지도록 각 열의 끝에 0을 추가한
	이차원 배열을 return하는 solution 함수 구현
*/

using namespace std;

vector<vector<int>> solution(vector<vector<int>> _arr) 
{

	vector<vector<int>> answer = _arr;
	int r = answer.size();
	int c = answer[0].size();

	if (r < c) answer.resize(c, vector<int>(c, 0));
	else if (c < r)
	{

		for (int i = 0; i < r; i++)
		{

			answer[i].resize(r, 0);
		}
	}

	return answer;
}