#include <vector>

/*
날짜 : 2024. 3. 2
이름 : 배성훈
내용 : 특별한 이차원 배열 2
	n * n 크기의 이차원 배열 arr이 매개변수로 주어진다
	arr이 다음을 만족하면 1, 아니라면 0을
	return하는 solution 함수 구현
	
	0 <= i, j < n인 정수 i,j에 대해
		arr[i][j] = arr[j][i]
*/

using namespace std;

int solution(vector<vector<int>> _arr)
{

	int answer = 1;

	// arr의 크기를 가져온다
	// arr 안에 있는 vector<int>의 개수
	int n = _arr.size();

	for (int i = 0; i < n; i++)
	{

		// n * n 벡터다
		for (int j = i + 1; j < n; j++)
		{

			if (_arr[i][j] == _arr[j][i]) continue;

			answer = 0;
			break;
		}
	}

	return answer;
}