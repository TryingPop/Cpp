#include <vector>
#include <algorithm>

/*
날짜 : 2024. 3. 17
이름 : 배성훈
내용 : 약수 구하기
	정수 n이 매개변수로 주어질 때,
	n의 약수를 오름차순으로 담은 배열을
	return 하도록 solution 함수를 구현

	n은 1만 이하의 자연수
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;
	
	// 에라토스 테네스의 체 이론을 적용할 예정
	// 커봐야 100까지만 탐색하는데 
	// 모두 쌍으로 발견되는 경우
	// 많아야 200개 크기 먼저 할당
	// 실제론 더 적다!
	answer.reserve(200);

	for (int i = 1; i <= _n; i++)
	{

		if (i * i > _n) break;
		if (_n % i) continue;

		int div1 = i;
		int div2 = _n / i;

		answer.push_back(div1);
		if (div1 != div2) answer.push_back(div2);
	}

	sort(answer.begin(), answer.end());
	return answer;
}