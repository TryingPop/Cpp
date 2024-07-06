/*
��¥ : 2024. 7. 6
�̸� : �輺��
���� : ���� Ŭ�����͸�
	��ī�� ���絵�� ���� ���� ���絵�� �˻��ϴ� ���� ��� ���� �ϳ��̴�
	�� ���� A, B ������ ��ī�� ���絵 J(A, B)�� 
	�� ������ �������� ũ�⸦ �������� ũ��� ���� ������ ���ǵȴ�

	�������� �������� ��� �������� ���ǵ��� ������ J(A, B) = 1�� �����Ѵ�

	��ī�� ���絵�� ���ڿ� ������ ���絵�� ����ϴµ� �̿��� �� �ִ�
	���ڿ� str1, str2�� �Ű������� �־��� ��,
	�� ���ڿ��� �� ���ھ� ��� ���� ������ �����
	���⼭ �����ڷ� �� ���� �ָ� ��ȿ�ϰ�,
	��Ÿ �����̳� ����, Ư�� ���ڰ� ����ִ� ��쿡�� �� ���� ���� ������
	�׸��� ���Ҹ� ���� �� �빮�ڿ� �ҹ����� ���̴� �����Ѵ�
	
	�� ���ڿ��� ��ī�� ���絵�� 0 ���� 1�ε� �ٷ�� ������ 65536�� ���� ��
	�Ҽ��� �Ʒ��� ������ �����κи� return�ϴ� solution �Լ� ����


	parameter
	"FRANCE", "french"


	return
	16384


	sol
	"FRANCE" ���ڿ��� ����������
	{ "FR", "RA", "AN", "NC", "CE" }

	"french" ���ڿ��� ����������
	{ "fr", "re", "en", "nc", "ch" }

	�̴�

	��ҹ��� ���̸� �����Ѵٰ� �����Ƿ�
	"FR" == "fr", "NC" == "nc"�̴�
	�������� {"FR", "NC" } 2�� �ִ�
	�������� 8�� { "FR", "RA", "AN", "NC", "CE", "re", "en", "ch" } �ִ�

	��ī�� ���絵�� 0.25�� �ǰ�
	��� ���ǿ� ���߸� 65536 * 0.25 = 16384�� �ȴ�
*/

#include <vector>
#include <string>
#include <cmath>

#define DIV 26

using namespace std;

void ChangeString(string& _str)
{

	/*
	
	���ڿ� ���� �Լ�

	�ҹ��� -> �빮��
	Ư������, ����, ��ȣ -> ����
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
	
	�� ���ھ� ���� ���ڿ� ���� ���� ���� �Լ�
	Rabin - Karp �˰������� ���ڿ��� ���ڷ� ��ȯ�ؼ� �����Ѵ�
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