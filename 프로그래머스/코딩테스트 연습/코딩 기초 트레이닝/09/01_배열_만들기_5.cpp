#include <string>
#include <vector>

/*
��¥ : 2024. 2. 15
�̸� : �輺��
���� : �迭 ����� 5
	���ڿ� �迭 intStrs�� ���� k, s, l�� �־�����
	intStrs�� ���Ҵ� ���ڷ� �̷�����ִ�

	�迭 intStrs�� �� ���Ҹ��� s�� �ε������� �����ϴ� ���� l ¥�� �κ� ���ڿ��� �߶� ������ ��ȯ
	�̶� ��ȯ�� �������� k���� ū ������ ���� �迭�� return �ϴ� solution �Լ� �����

	������ ����ִ� ��찡 ����;
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

		// ���� ���, �Ǿ��� -�̰�, ������ 0�� ��츸 false�̴�!
		bool plus = str[0] != '-' || _s != 0;
		// plus�� �ƴ� ��� ��ĭ �� ���� ����
		if (!plus) curLen++;

		while (curLen < _l) 
		{

			intStr = intStr * 10 + str[_s + curLen] - '0';
			curLen++;
		}

		// plus ���� ����
		intStr = plus ? intStr : -intStr;

		if (intStr > _k) answer.push_back(intStr);
	}
#endif	
	return answer;
}