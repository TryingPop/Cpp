#include <string>
#include <vector>

using namespace std;

inline vector<int> SetPattern(const string& _pattern)
{

	/*
	
	매치안될 시 되돌아갈 장소 확인하고 반환
	*/
	int backPos = 0;

	vector<int> jump(_pattern.length(), 0);

	for (int curPos = 1; curPos < _pattern.length(); curPos++)
	{

		// 되돌아갈 시점 확인
		while (backPos > 0 && _pattern[backPos] != _pattern[curPos])
		{

			backPos = jump[backPos - 1];
		}

		if (_pattern[backPos] == _pattern[curPos]) jump[curPos] = ++backPos;
	}

	return jump;
}

inline vector<int> KMP(string& _text, string& _pattern, vector<int>& _jump)
{

	/*
	
	문자열 매칭 확인
	매칭되는 시작 지점 인덱스들을 반환
	*/

	int match = 0;
	vector<int> ret;
	for (int i = 0; i < _text.length(); i++)
	{

		// 현재와 매칭 안되면 되돌아가는 시점 변경
		while (match > 0 && _text[i] != _pattern[match])
		{

			match = _jump[match - 1];
		}

		// 매칭 확인
		if (_text[i] == _pattern[match])
		{

			match++;

			if (match == _pattern.length())
			{

				ret.push_back(i - match + 1);
				// 겹치는 구간 상관없이 모두 찾으려면 이전 점프단계로 간다
				match = _jump[match - 1];
				// 일치하는 문자열들간 만약 겹치는 구간 없이 최대한 찾고싶다면
				// match = 0;
			}
		}
	}

	return ret;
}

#include <iostream>
#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
#define endl	'\n'

int main(void)
{

	// 백준 1786 찾기 문제
	string text, pattern;

	FAST_IO;

	getline(cin, text);
	getline(cin, pattern);
	vector<int> jump = SetPattern(pattern);
	vector<int> ret = KMP(text, pattern, jump);

	cout << ret.size() << endl;
	for (int num : ret)
	{

		cout << num + 1 << EMPTY;
	}

	return 0;
}