#include <string>

/*
��¥ : 2024. 2. 16
�̸� : �輺��
���� : ���λ����� Ȯ���ϱ�
	banana�� ���λ�� 
		b
		ba
		ban
		bana
		banan
		banana

	���ڿ� my_string�� is_prefix�� �־��� ��, is_prefix�� my_string�� ���λ��� 
	1�� �ƴϸ� 0�� ��ȯ�ϴ� �Լ� ����
*/

using namespace std;

int solution(string _my_string, string _is_prefix)
{

	int answer;

	if (_my_string.length() < _is_prefix.length()) answer = 0;
	else answer = _my_string.substr(0, _is_prefix.length()) == _is_prefix;

	return answer;
}