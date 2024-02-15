#include <string>
#include <vector>

/*
날짜 : 2024. 2. 15
이름 : 배성훈
내용 : 배열 만들기 5
	문자열 배열 intStrs와 정수 k, s, l이 주어진다
	intStrs의 원소는 숫자로 이루어져있다

	배열 intStrs의 각 원소마다 s번 인덱스에서 시작하는 길이 l 짜리 부분 문자열을 잘라내 정수로 변환
	이때 변환한 정수값이 k보다 큰 값들을 담은 배열을 return 하는 solution 함수 만들기

	음수가 들어있는 경우가 없다;
*/

using namespace std;

vector<int> solution(vector<string> _intStrs, int _k, int _s, int _l)
{

	vector<int> answer;

#if substr
	for (string str : _intStrs) 
	{

		string subStr = str.substr(_s, _l);
		int subInt = stoi(subStr);

		if (subInt > _k) answer.push_back(subInt);
	}

#else
	for (const string str : _intStrs) 
	{

		int intStr = 0;
		int curLen = 0;

		// 음수 고려, 맨앞이 -이고, 시작이 0인 경우만 false이다!
		bool plus = str[0] != '-' || _s != 0;
		// plus가 아닌 경우 한칸 띄어서 연산 시작
		if (!plus) curLen++;

		while (curLen < _l) 
		{

			intStr = intStr * 10 + str[_s + curLen] - '0';
			curLen++;
		}

		// plus 여부 적용
		intStr = plus ? intStr : -intStr;

		if (intStr > _k) answer.push_back(intStr);
	}
#endif	
	return answer;
}