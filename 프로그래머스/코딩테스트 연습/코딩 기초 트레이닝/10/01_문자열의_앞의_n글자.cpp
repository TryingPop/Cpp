#include <string>

/*
��¥ : 2024. 2. 16
�̸� : �輺��
���� : ���ڿ��� ���� n����
	���ڿ� my_string�� ���� n�� �Ű������� �־��� ��,
	my_string�� ���� n���ڷ� �̷���� ���ڿ��� return�ϴ� solution �Լ��� �ۼ�
*/

using namespace std;

string solution(string _my_string, int _n) 
{

	string answer;

	answer = _my_string.substr(0, _n);
	// answer = string(_my_string.begin(), _my_string.begin() + _n);
	// answer.assign(_my_string.begin(), _my_string.begin() + _n);
	return answer;
}