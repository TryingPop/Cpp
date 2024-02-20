#include <vector>

/*
날짜 : 2024. 2. 20
이름 : 배성훈
내용 ; n보다 커질 때까지 더하기
	정수 배열 numbers와 정수 n이 매개변수로 주어진다
	numbers의 원소를 앞에서부터 하나씩 더하다가
	그 합이 n보다 커지는 순간 이때까지 더했던 원소들의 합을
	return 하는 solution 함수를 구현
*/

using namespace std;

int solution(vector<int> _numbers, int _n)
{

	int answer = 0;

	for (const int add : _numbers) 
	{

		answer += add;
		if (answer > _n) break;
	}

	return answer;
}