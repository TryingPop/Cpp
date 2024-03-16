#include <vector>

/*
날짜 : 2024. 3. 16
이름 : 배성훈
내용 : 가까운 수
	정수 배열 array와 정수 n이 매개변수로 주어질 때,
	array에 들어있는 정수 중 n과 가장
	가까운 수를 return 하는 solution 함수 구현

	가장 가까운 수가 여러 개일 경우
	더 작은 수를 return
*/

using namespace std;

int solution(vector<int> _array, int _n)
{

	int answer;

	// _array는 고정된 채
	// _n 계속되서 _n을 입력하면
	// _array를 정렬하고 이진 탐색으로 푸는게 좋다
	int min = _n - _array[0];
	min = min < 0 ? -min : min;

	int minIdx = 0;

	for (int i = 1; i < _array.size(); i++)
	{

		int calc = _n - _array[i];
		calc = calc < 0 ? -calc : calc;

		if (calc < min) 
		{

			min = calc;
			minIdx = i;
		}
		else if (min == calc && _array[minIdx] > _array[i])
		{

			minIdx = i;
		}
	}

	answer = _array[minIdx];
	return answer;
}