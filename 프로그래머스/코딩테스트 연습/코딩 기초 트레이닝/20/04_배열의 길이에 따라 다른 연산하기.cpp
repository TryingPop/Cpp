#include <vector>

/*
날짜 : 2024. 2. 26
이름 : 배성훈
내용 : 배열의 길이에 따른 다른 연산하기
	정수 배열 arr과 정수 n이 매개변수로 주어진다
	arr의 길이가 홀수라면
	arr의 모든 짝수 위치에 n을 더한 배열을,

	arr의 길이가 짝수라면
	arr의 모든 홀수 위치에 n을 더한 배열을

	return하는 solution 함수를 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr, int _n)
{

	vector<int> answer;

	answer = _arr;
	int s = (_arr.size() + 1) & 1;

	for (int i = s; i < answer.size(); i += 2)
	{

		answer[i] += _n;
	}

	return answer;
}