/*
날짜 : 2024. 8. 26
이름 : 배성훈
내용 : 문자열 압축
	어피치는 대량의 데이터를 처리하기 위한 비손실 압축 방법에 대해
	공부를 하고 있다

	어피치는 문자열에서 같은 값이 연속해서 나타나는 것을 그 문자의 개수와 
	반복되는 값으로 표현하여 더 짧은 문자열로 줄여서 표현하는 알고리즘을
	공부하고 있다

	aabbacc를 2a2ba3c와 같이 압축한다
	문자가 반복되지 않아 한 번만 나타난 경우는 1을 생략한다
	이러한 방식은 반복되는 문자가 적은 경우
	압축률이 낮다는 단점이 있다

	이러한 단점을 해결하기 위해
	문자열을 1개 이상의 단위로 잘라서 압축하여 
	더 짧은 문자열로 표현할 수 있는지 방법을 찾아보려고 한다

	압축할 문자열 s가 매개변수로 주어질 때,
	위에서 설명한 방법으로 1개 이상 단위로 문자열을 잘라
	압축하여 표현한 문자열 중 가장 짧은 것의 길이를
	return 하는 solution 함수를 구현

	s는 1 이상 1000이하
	s는 알파벳 소문자로만 이뤄져 있다

	문자열은 제일 앞부터 정해진 길이만큼 잘라야 한다
*/

#include <string>
#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))

using namespace std;

inline void Find(string& _str, int _len, string& _ret)
{

	/*
	
	압축 실행
	len 은 압축할 단위
	str은 기존 문자열
	ret는 담을 결과
	*/

	_ret.clear();		// 이어붙이는 식이므로 이전 결과 초기화
	int cnt = 1;		// 자기자신을 포함해 개수를 세는 것이므로 자기자신 1 카운트
	int l = 0;			// 투 포인터알고리즘인데, 점검할 문자열
	int match = 0;		// 매칭된 개수

	for (int r = _len; r < _str.length(); r++)
	{

		// 매칭 여부 확인
		if (_str[l + match] != _str[r])
		{

			// 매칭 x이다
			// 앞번 검증 문자를 넣는다
			_ret.append(_str.substr(l, _len));

			// 개수 1은 생략 가능하므로 2개 이상에서만 넣는다
			if (cnt > 1) _ret.append(to_string(cnt));

			// 다음 문자로 간다
			l = r - match;
			r = l + _len - 1;
			cnt = 1;
			match = 0;
			continue;
		}

		// 매칭
		match++;
		if (match == _len)
		{

			// 압축된 경우
			cnt++;
			match = 0;
		}
	}

	// 남은 부분 추가
	_ret.append(_str.substr(l, _len));
}

int solution(string& _s)
{

	/*
	
	문자열, 구현
	*/
	_s.push_back(' ');				// 마지막에 무조건 매칭안되게 설정
	int answer = _s.length();

	string ret;						// 압축한 결과 담는 문자열
	ret.reserve(_s.length());

	int len = _s.length() / 2;
	for (int i = 1; i <= len; i++)
	{

		Find(_s, i, ret);
		answer = Min(answer, ret.length());
	}

	return answer - 1;
}