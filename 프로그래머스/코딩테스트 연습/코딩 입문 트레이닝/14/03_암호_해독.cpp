#include <string>

/*
��¥ : 2024. 3. 16
�̸� : �輺��
���� : ��ȣ �ص�
	��ȣȭ�� ���ڿ� cipher,
	code�� ��� ��° ���ڸ� ��¥ ��ȣ

	���ڿ� cipher�� ���� code�� �Ű������� �־��� ��,
	�ص��� ��ȣ ���ڿ��� return �ϴ�
	solution �Լ� ����
*/

using namespace std;

string solution(string _cipher, int _code)
{

	string answer;
	answer.reserve(1 + _cipher.length() / _code);

	for (int i = _code - 1; i < _cipher.length(); i += _code)
	{

		answer.push_back(_cipher[i]);
	}

	return answer;
}