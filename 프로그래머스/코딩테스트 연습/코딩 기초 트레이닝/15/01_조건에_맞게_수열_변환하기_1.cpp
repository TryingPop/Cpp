#include <vector>

/*
날짜 : 2024. 2. 21
이름 : 배성훈
내용 : 조건에 맞게 수열 변환하기 1
	정수 배열 arr가 주어진다
	arr의 각 원소에 대해 값이 50보다 크거나 같은 짝수라면 2로 나누고,
	50보다 작은 홀수라면 2를 곱한다
	그 결과인 정수 배열을 return하는 solution 함수를 구현
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> answer;
	answer = _arr;

	for (int i = 0; i < answer.size(); i++) 
	{

		if ((answer[i] & 1) && answer[i] < 50) answer[i] *= 2;
		else if (!(answer[i] & 1) && answer[i] >= 50) answer[i] /= 2;
	}
	return answer;
}