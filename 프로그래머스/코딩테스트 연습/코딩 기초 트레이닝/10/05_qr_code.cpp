#include <string>

/*
��¥ : 2024. 2. 16
�̸� : �輺��
���� : qr code
	�� ���� q, r�� ���ڿ� code�� �־��� ��,
	code�� �� �ε����� q�� �������� �� �������� r��
	��ġ�� ���ڸ� �տ������� ������� �̾� ���� ���ڿ��� return�ϴ� solution �Լ� ����
*/
using namespace std;

string solution(int _q, int _r, string _code) 
{

	string answer;

	for (int i = _r; i < _code.length(); i += _q)
	{

		answer.push_back(_code[i]);
	}
	return answer;
}