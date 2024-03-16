#include <vector>

/*
날짜 : 2024. 3. 13
이름 : 배성훈
내용 : 합성수 찾기
	약수의 개수가 3개 이상인 수를 합성수
	자연수 n이 매개변수로 주어질 때,

	n이하의 합성수의 개수를
	return 하는 solution 함수 구현
*/

using namespace std;

int solution(int _n)
{

	int answer = 0;

	vector<bool> temp(_n + 1, false);

	for (int i = 2; i <= _n; i++)
	{

		for (int j = i * 2; j <= _n; j += i)
		{

			temp[j] = true;
		}
	}

	for (int i = 2; i <= _n; i++)
	{

		if (temp[i]) answer++;
	}

	return answer;
}