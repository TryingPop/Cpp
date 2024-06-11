/*
날짜 : 2024. 6. 12
이름 : 배성훈
내용 : 이진 변환 반복하기
	0과 1로 이루어진 어떤 문자열 x에 대한 이진변환을 다음과 같이 정의한다
	
	1. x의 모든 0을 제거한다
	2. x의 길이를 c라고 하면, c를 2진법으로 표현한 문자열로 바꾼다

	0과 1로 이루어진 문자열 s가 매개변수로 주어질 때,
	s가 "1"이 될 때까지 계속해서 s에 이진변환을 가했을 때,
	이진 변환 횟수와 변환 과정에서 제거된 모든 0의 개수를
	각각 배열에 담아 return 하는 solution 함수를 구현

	parameter
	"110010101001"
	
	return
	3, 8
*/

#include <vector>
#include <string>

using namespace std;

vector<int> solution(string _s)
{

	vector<int> answer(2, 0);

	int len = _s.length();
	while (len)
	{

		// 0 제거
		int remove = 0;
		for (int i = 0; i < len; i++)
		{

			if (_s[i] = '1') continue;
			remove++;
		}

		len -= remove;

		// 0을 제거한 문자열의 길이를 2진법 변환
		int nextLen = 0;

		// 역방향으로 저장
		while (len)
		{

			if (len & 1) _s[nextLen++] = '1';
			else _s[nextLen++] = '0';

			len >>= 1;
		}

		// 역방향을 정방향으로
		for (int i = 0; i < nextLen; i++)
		{

			int other = nextLen - 1 - i;
			if (other <= i) break;

			char temp = _s[i];
			_s[i] = _s[other];
			_s[other] = temp;
		}

		// 결과 갱신
		len = nextLen;
		answer[0]++;
		answer[1] += remove;
	}

	return answer;
}