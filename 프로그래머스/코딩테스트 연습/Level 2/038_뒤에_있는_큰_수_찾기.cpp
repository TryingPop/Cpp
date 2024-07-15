/*
날짜 : 2024. 7. 15
이름 : 배성훈
내용 : 뒤에 있는 큰 수 찾기
	정수로 이루어진 배열 numbers가 있다
	배열의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서
	자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 한다

	정수 배열 numbers가 매개변수로 주어질 때,
	모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을
	return하는 solution 함수 구현
	단 뒷 큰수가 존재하지 않는 원소는 -1을 담는다

	parameter
	{ 2, 3, 3, 5 }


	return
	{ 3, 5, 5, -1 }



	sol
	3번 인덱스의 5는 마지막에 있다
	해당 수보다 뒤에 있는 원소는 없으므로 -1을 담는다

	2번 인덱스의 3의 경우 뒤에 자기보다 큰 가장 가까운 큰 수는 5가 있다
	그래서 5가 담긴다

	1번 인덱스의 3의 경우 뒤에 자기보다 큰 가장 가까운 큰 수는 5가 있다
	그래서 5가 담긴다

	0번 인덱스의 2의 경우 뒤에 자기보다 큰 가장 가까운 큰 수는 3이 있다
	그래서 3이 담긴다
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> _numbers)
{

	vector<int> answer(_numbers.size(), -1);
	vector<int> stack(_numbers.size(), 0);

	int len = 0;
	for (int i = _numbers.size() - 1; i >= 0; i--) 
	{

		while (len && _numbers[i] >= stack[len - 1])
		{

			len--;
		}

		if (len) answer[i] = stack[len - 1];

		stack[len++] = _numbers[i];
	}

	return answer;
}