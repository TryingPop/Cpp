#include <string>

/*
��¥ : 2024. 2. 16
�̸� : �輺��
���� : ���� �б�
	���ڿ� my_string�� �� ���� m, c�� �־�����
	my_string�� �� �ٿ� m ���ھ� ���η� ������ ��,
	���ʺ��� ���η� c��° ���� ���� ���ڵ��� ���ڿ��� return �ϴ� solution �Լ� ����
*/
using namespace std;

string solution(string _my_string, int _m, int _c)
{

	string answer;

	for (int i = _c - 1; i < _my_string.length(); i += _m) 
	{

		answer.push_back(_my_string[i]);
	}
	return answer;
}