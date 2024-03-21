#include <vector>

/*
날짜 : 2024. 3. 21
이름 : 배성훈
내용 : 중복된 숫자 개수
	정수가 담긴 배열 array와 정수 n이
	매개변수로 주어질 때,

	array에 n이 몇 개 있는지를
	return 하도록 solution 함수를 구현
*/

using namespace std;

int solution(vector<int> _array, int _n)
{

	int answer = 0;

	for (const int i : _array)
	{

		if (i == _n) answer++;
	}

	return answer;
}