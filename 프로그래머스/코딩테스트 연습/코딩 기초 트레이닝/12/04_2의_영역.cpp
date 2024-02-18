#include <vector>

/*
날짜 : 2024. 2. 18
이름 : 배성훈
내용 : 2의 영역
	정수 배열 arr이 주어진다
	배열 안의 2가 모두 포함된 가장 작은 연속된 부분 배열을
	return 하는 solution 함수를 완성
	단, arr에 2가 없는 경우 { -1 }을 return
*/
using namespace std;

vector<int> solution(vector<int> _arr) 
{

	vector<int> answer;

	int s = -1;
	int e = -1;

	for (int i = 0; i < _arr.size(); i++) 
	{

		if (_arr[i] == 2) 
		{

			if (s == -1) s = i;
			else e = i;
		}
	}

	if (s != -1)
	{

		if (e == -1) answer.push_back(2);

		else
		{

			for (int i = s; i <= e; i++) 
			{

				answer.push_back(_arr[i]);
			}
		}
	}
	else answer.push_back(-1);

	return answer;
}