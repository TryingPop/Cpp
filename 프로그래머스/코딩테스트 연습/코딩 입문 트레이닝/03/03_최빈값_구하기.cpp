#include <vector>
#define _ 1'001

/*
날짜 : 2024. 3. 8
이름 : 배성훈
내용 : 최빈값 구하기
	정수 배열 array가 매개변수로 주어질 때,
	최빈값을 return 하도록 solution 함수를 구현

	최빈값은 주어진 값 중에서 가장 자주 나오는 값을 의미
	최빈값이 여러 개면 -1을 반환

	array원소의 범위는 0이상 1000 이하이다
*/

using namespace std;

int solution(vector<int> _array)
{

	// 1'000을 초과하는 아무 값을 넣어주면 된다
	int answer = _;
	vector<int> calc(1'001, 0);
	int max = 0;
	for (const int i : _array)
	{

		calc[i]++;
		if (max < calc[i]) max = calc[i];
	}


	for (int i = 0; i <= 1000; i++)
	{

		if (max == calc[i]) 
		{

			// 첫 발견
			if (answer == _) answer = i;
			else 
			{

				// 중복 발견
				answer = -1;
				break;
			}
		}
	}

	return answer;
}