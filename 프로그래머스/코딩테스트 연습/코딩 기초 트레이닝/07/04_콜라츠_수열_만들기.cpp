#include <vector>

/*
날짜 : 2024. 2. 13
이름 : 배성훈
내용 : 콜라츠 수열 만들기
	모든 자연수 x에 대해 x가 짝수이면 2로 나누고, x가 홀수면 3 * x + 1로 바꾼다
	해당 계산을 반복하면 1이 된다고 추측하는게 콜라츠 문제

	1000보다 작거나 같은 수에 대해서는 성립한다
	1000보다 작은 자연수 n이 주어질 때, 초기값이 n인 콜라츠 수열을 반환하는 함수만들기
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;

	answer.push_back(_n);
	
	while (_n != 1)
	{

		if (_n & 1) _n = _n * 3 + 1;
		else _n = _n / 2;

		answer.push_back(_n);
	}

	return answer;
}