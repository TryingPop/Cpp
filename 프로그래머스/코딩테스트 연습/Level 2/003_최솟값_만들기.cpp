/*
날짜 : 2024. 6. 10
이름 : 배성훈
내용 : 최솟값 만들기
	길이가 같은 배열 A, B 두 개가기 있다
	배열은 자연수로 이뤄져 있다

	배열 A, B에서 각각 한 개의 숫자를 뽑아
	두 수를 곱한다

	이러한 과정을 배열의 길이만큼 반복하며,
	두 수를 곱한 값 누적하여 더한다

	이때 최종적으로 누적된 값이 최소가 되도록
	만드는 것이 목표이다

	여기서 각 배열에서 k번째 숫자를 뽑았다면
	다음에 k번째 숫자는 다시 뽑을 수 없다

	A, B의 길이는 1'000이하인 자연수
	A, B의 원소의 크기는 1'000이하인 자연수

	parameter
	{ 1, 4, 2 }, { 5, 4, 4 }

	return
	29
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> _A, vector<int> _B)
{

	int answer = 0;

	sort(_A.begin(), _A.end());
	sort(_B.begin(), _B.end(), greater<int>());

	for (int i = 0; i < _A.size(); i++)
	{

		answer += _A[i] * _B[i];
	}

	return answer;
}