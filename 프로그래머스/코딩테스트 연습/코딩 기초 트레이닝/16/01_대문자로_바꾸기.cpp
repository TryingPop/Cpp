#include <string>
#include <vector>
#if !first
#include <algorithm>
#endif
/*
��¥ : 2024. 2. 22
�̸� : �輺��
���� : �빮�ڷ� �ٲٱ�
	���ĺ����� �̷���� ���ڿ� myString�� �־�����
	��� ���ĺ��� �빮�ڷ� ��ȯ�Ͽ� return�ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _myString)
{

	string answer;
#if first
	answer.reserve(_myString.size());

	int calc = 'A' - 'a';
	for (int i = 0; i < _myString.length(); i++)
	{

		if (_myString[i] > 'Z') answer.push_back(_myString[i] + calc);
		else answer.push_back(_myString[i]);
	}
#else
	answer = _myString;
	transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
	
#endif
	return answer;
}