/*
날짜 : 2024. 7. 17
이름 : 배성훈
내용 : 주식가격
	초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때,
	가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수 구현

	prices의 각 가격은 1 이상 10'000 이하인 자연수

	prices의 길이는 2 이상 100'000이하


	parameter
	{ 1, 2, 3, 2, 3 }


	return
	{ 4, 3, 1, 1, 0 }


	sol
	1초 시점의 1은 끝까지 가격이 떨어지지 않는다
	2초 시점의 가격 2도 끝까지 가격이 떨어지지 않는다
	3초 시점의 3은 1초 뒤에 가격이 떨어진다
	4초 시점의 2는 1초간 가격이 떨어지지 않는다
	5초 시점의 3은 0초간 가격이 떨어지지 않는다
*/

#include <vector>

using namespace std;


vector<int> solution(vector<int> _prices)
{

	int end = _prices.size() - 1;
	vector<int> answer(end + 1, 0);

	vector<int> stack;
#if back


	for (int i = end; i >= 0; i--)
	{

		while (stack.size() && _prices[stack.back()] >= _prices[i])
		{

			stack.pop_back();
		}

		if (stack.empty()) answer[i] = end - i;
		else answer[i] = stack.back() - i;
	}
#else

	for (int i = 0; i <= len; i++)
	{

		while (stack.size() && _prices[i] < _prices[stack.back()])
		{

			int idx = stack.back();
			stack.pop_back();

			answer[idx] = i - idx;
		}
		
		stack.push_back(i);
	}

	while (stack.size())
	{

		int idx = stack.back();
		stack.pop_back();

		answer[idx] = len - idx;
	}
#endif

	return answer;

}
