/*
날짜 : 2024. 6. 20
이름 : 배성훈
내용 : N개의 최소공배수
	두 수의 최소공배수(Least Common Multiple)이란
	입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미한다

	n개의 수의 최소 공배수는 n개의 수들의 배수 중 공통이 되는
	가장 작은 숫자를 의미한다

	n개의 숫자를 담은 배열 arr이 입력되었을 때
	이 수들의 최소공배수를 반환하는 함수 solution을 구현

	arr은 1 이상 15이하인 배열,
	arr의 원소는 100 이하인 자연수

	parameter
	{ 2, 6, 8, 14 }


	return
	168
*/

#include <vector>

using namespace std;

int GetGCD(int _a, int _b)
{

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int solution(vector<int> _arr)
{

	int answer = 1;

	for (int num : _arr)
	{

		int gcd = GetGCD(answer, num);
		answer *= num / gcd;
	}

	return answer;
}