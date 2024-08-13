#include <string>
#include <vector>

using namespace std;

inline vector<int> SetPattern(const string& _pattern)
{

	/*
	
	��ġ�ȵ� �� �ǵ��ư� ��� Ȯ���ϰ� ��ȯ
	*/
	int backPos = 0;

	vector<int> jump(_pattern.length(), 0);

	for (int curPos = 1; curPos < _pattern.length(); curPos++)
	{

		// �ǵ��ư� ���� Ȯ��
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
	
	���ڿ� ��Ī Ȯ��
	��Ī�Ǵ� ���� ���� �ε������� ��ȯ
	*/

	int match = 0;
	vector<int> ret;
	for (int i = 0; i < _text.length(); i++)
	{

		// ����� ��Ī �ȵǸ� �ǵ��ư��� ���� ����
		while (match > 0 && _text[i] != _pattern[match])
		{

			match = _jump[match - 1];
		}

		// ��Ī Ȯ��
		if (_text[i] == _pattern[match])
		{

			match++;

			if (match == _pattern.length())
			{

				ret.push_back(i - match + 1);
				// ��ġ�� ���� ������� ��� ã������ ���� �����ܰ�� ����
				match = _jump[match - 1];
				// ��ġ�ϴ� ���ڿ��鰣 ���� ��ġ�� ���� ���� �ִ��� ã��ʹٸ�
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

	// ���� 1786 ã�� ����
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