#include <string>
#include <vector>

/*
��¥ : 2024. 3. 17
�̸� : �輺��
���� : �ε��� �ٲٱ�
	���ڿ� my_string�� ���� num1, num2�� �Ű������� �־��� ��,
	my_string���� �ε��� num1�� �ε��� num2�� �ش��ϴ� ���ڸ� �ٲ�
	���ڿ��� return �ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _my_string, int _num1, int _num2)
{

	string answer = _my_string;
	swap(answer[_num1], answer[_num2]);

	return answer;
}