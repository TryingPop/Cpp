#include <string>
#include <algorithm>

/*
��¥ : 2024. 3. 9
�̸� : �輺��
���� : ���ڿ� ������
	���ڿ� my_string�� �Ű������� �־��� ��,
	my_string�� �Ųٷ� ������ ���ڿ���
	return �ϴ� solution �Լ��� ����
*/

using namespace std;

string solution(string _my_string)
{

	string answer = _my_string;
	
	reverse(_my_string.begin(), _my_string.end());
	return answer;
}