/*
날짜 : 2024. 8. 3
이름 : 배성훈
내용 : 연속된 부분 수열의 합
	비내림차순으로 정렬된 수열이 주어질 때, 
	다음 조건을 만족하는 부분 수열을 찾으려고 한다

	기존 수열에서 임의의 두 인덱스의 원소와 
	그 사이의 원소를 모두 포함하는 부분 수열이어야 한다

	부분 수열의 합은 k이다

	합이 k인 부분 수열이 여러 개인 경우
	길이가 가장 짧은 수열을 찾는다

	길이가 짧은 수열이 여러 개인 경우 앞쪽(시작 인덱스가 작은)에
	나오는 수열을 찾는다

	수열을 나타내는 정수배열 sequence와 
	부분 수열의 합을 나타내는 정수 k가
	매개변수로 주어질 때,

	위 조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를
	배열에 담아 return 하는 solution 함수 구현

	수열의 인덱스는 0부터 시작한다

	sequence의 길이는 100만 이하이고 5 이상인 자연수
	sequence의 원소는 1000 이하의 자연수
	sequence는 비내림차순으로 정렬되어 있다

	k는 10억 이하이고 5 이상인 자연수이고
	k는 항상 sequence의 부분 수열로 만들 수 잇는 값이다


	parameter
	{ 1, 2, 3, 4, 5 }, 7


	return
	{ 2, 3 }


	sol
	3에서 4까지 택하면 3 + 4 = 7이고
	길이가 2로 최소이다
*/

#include<vector>

using namespace std;

vector<int> solution(vector<int> _sequence, int _k)
{

	/*
	
	두 포인터
	*/

	int size = _sequence.size();	// sequence 의 크기
	vector<int> answer(2);			// 정답 l, r

	int l = 0;						// 왼쪽 포인터
	int r = 0;						// 오른쪽 포인터

	int curVal = _sequence[0];		// 현재 값
	int curLen = size + 1;			// _k일 때 최소 길이

	while (l < size && r < size)
	{

		// 값이 같으면 길이 검사 후 갱신
		// 비 내림차순이라 길이가 아닌 이전 값을 확인해 갱신해도 된다
		if (curVal == _k && r - l + 1 < curLen)
		{

			answer[0] = l;
			answer[1] = r;
			curLen = r - l + 1;
		}

		if (_k <= curVal) curVal -= _sequence[l++];
		else curVal += _sequence[++r];
	}

	return answer;
}
