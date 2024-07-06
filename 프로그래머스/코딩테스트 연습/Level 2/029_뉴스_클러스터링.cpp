/*
날짜 : 2024. 7. 6
이름 : 배성훈
내용 : 뉴스 클러스터링
	자카드 유사도는 집합 간의 유사도를 검사하는 여러 방법 중의 하나이다
	두 집합 A, B 사이의 자카드 유사도 J(A, B)는 
	두 집합의 교집합의 크기를 합집합의 크기로 나눈 값으로 정의된다

	합집합이 공집합인 경우 나눗셈이 정의되지 않으니 J(A, B) = 1로 정의한다

	자카드 유사도를 문자열 사이의 유사도를 계산하는데 이용할 수 있다
	문자열 str1, str2가 매개변수로 주어질 때,
	각 문자열을 두 글자씩 끊어서 다중 집합을 만든다
	여기서 영문자로 된 글자 쌍만 유효하고,
	기타 공백이나 숫자, 특수 문자가 들어있는 경우에는 그 글자 쌍을 버린다
	그리고 원소를 비교할 때 대문자와 소문자의 차이는 무시한다
	
	두 문자열의 자카도 유사도는 0 에서 1인데 다루기 쉽도록 65536을 곱한 뒤
	소수점 아래를 버리고 정수부분만 return하는 solution 함수 구현


	parameter
	"FRANCE", "french"


	return
	16384


	sol
	"FRANCE" 문자열의 다중집합은
	{ "FR", "RA", "AN", "NC", "CE" }

	"french" 문자열의 다중집합은
	{ "fr", "re", "en", "nc", "ch" }

	이다

	대소문자 차이를 무시한다고 했으므로
	"FR" == "fr", "NC" == "nc"이다
	교집합은 {"FR", "NC" } 2개 있다
	합집합은 8개 { "FR", "RA", "AN", "NC", "CE", "re", "en", "ch" } 있다

	자카드 유사도는 0.25가 되고
	출력 조건에 맞추면 65536 * 0.25 = 16384가 된다
*/

#include <vector>
#include <string>
#include <cmath>

#define DIV 26

using namespace std;

void ChangeString(string& _str)
{

	/*
	
	문자열 변형 함수

	소문자 -> 대문자
	특수문자, 숫자, 기호 -> 공백
	*/

	for (int i = 0; i < _str.length(); i++)
	{

		if ('A' <= _str[i] && _str[i] <= 'Z') continue;

		if ('a' <= _str[i] && _str[i] <= 'z') _str[i] = _str[i] - 'a' + 'A';
		else _str[i] = ' ';
	}
}

void SetCnt(string& _str, vector<int>& _cnt) 
{

	/*
	
	두 글자씩 끊은 문자열 다중 집합 세는 함수
	Rabin - Karp 알고리즘으로 문자열을 숫자로 변환해서 저장한다
	*/

	int len = 0;
	int idx = 0;

	for (const char c : _str)
	{

		if (c == ' ')
		{

			len = 0;
			idx = 0;
			continue;
		}

		idx %= DIV;
		idx = idx * DIV + c - 'A';

		if (len < 1) 
		{ 
			
			len++;
			continue;
		}

		_cnt[idx]++;
	}
}

int solution(string _str1, string _str2)
{

	int answer;

	ChangeString(_str1);
	ChangeString(_str2);

	int len = DIV * DIV + 1;
	vector<int> cnt1(len, 0);
	vector<int> cnt2(len, 0);

	SetCnt(_str1, cnt1);
	SetCnt(_str2, cnt2);

	int u = 0;
	int n = 0;

	for (int i = 0; i < len; i++)
	{

		u += max(cnt1[i], cnt2[i]);
		n += min(cnt1[i], cnt2[i]);
	}

	if (u) answer = (int)(65'536 * ((double)(n)) / u);
	else answer = 65'536;

	return answer;
}