#include <string>

/*
��¥ : 2024. 2. 15
�̸� : �輺��
���� : ���ڿ��� ���� n����
	���ڿ� my_string�� ���� n�� �Ű������� �־��� ��,
	my_string�� ���� n���ڷ� �̷���� ���ڿ��� return�ϴ� solution �Լ��� ����
*/

using namespace std;

string solution(string _my_string, int _n)
{

	string answer;
	int len = _my_string.length();
	// len - _n ������ ������ �ڸ� ���ڿ��� ��ȯ
	answer = _my_string.substr(len - _n);
	return answer;
}