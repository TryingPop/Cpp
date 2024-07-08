/*
��¥ : 2024. 7. 7
�̸� : �輺��
���� : ��ȭ��ȣ ���
	��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��,
	�� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ��� �Ѵ�

	��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭
	phone_book�� �Ű������� �־��� ��,

	� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������
	false�� �׷��� ������ true��
	return �ϴ� solution �Լ� ����

	phone_book�� ���̴� 1 �̻� 100�� ����,
	�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 ����

	�ߺ��Ǵ� ��ȭ��ȣ�� ����


	parameter
	{ "119", "97674223", "1195524421" }


	return
	false


	sol
	119�� 1195524421�� ���λ�� ����
	�׷��� false
*/

#if first
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool MyComp(string& _str1, string& _str2)
{

	/*

	���ڿ� ������ �迭
	*/
	int len = _str2.length() < _str1.length() ? _str2.length() : _str1.length();

	for (int i = 0; i < len; i++)
	{

		if (_str1[i] != _str2[i]) return _str1[i] < _str2[i];
	}

	return _str1.length() < _str2.length();
}

bool solution(vector<string> _phone_book)
{

	bool answer = true;

	/*

	lcp �迭 ���� �� ���� ���̵� �����Դ�
	������ ������ �յڸ� ���ϸ� �ȴ�
	O(N * M log N), N : phone_book�� ����, M : �� ��ȭ��ȣ�� ����
	*/
	sort(_phone_book.begin(), _phone_book.end(), MyComp);

	// O(N * M), N : phone_book�� ����, M : �� ��ȭ��ȣ�� ����
	for (int i = 1; i < _phone_book.size(); i++)
	{

		if (_phone_book[i].find(_phone_book[i - 1]) != 0) continue;

		answer = false;
		break;
	}

	return answer;
}
#else

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool solution(vector<string> _phone_book)
{

	unordered_set<string> chk;
	chk.reserve(_phone_book.size());
	for (const string& str: _phone_book)
	{

		chk.insert(str);
	}

	string temp;
	for (const string& str : _phone_book)
	{

		temp = str;
		temp.pop_back();
		while (temp.size())
		{

			if (chk.count(temp)) return false;
			temp.pop_back();
		}
	}

	return true;
}
#endif