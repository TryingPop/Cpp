#include <string>
#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 10
�̸� : �輺��
���� : �ܰ��༺�� ����
	�༺���� ���̴� ���ĺ����� ���ϰ� �ִ�
	a = 0, b = 1, ... , j = 9
	10�������� ����ؼ� k�̻��� ���ĺ��� ���� �ʴ´�

	���� ������ ���� age�� �־��� ��,
	�༺���� ���� ���̸� return �ϴ� solution �Լ� ����
*/

using namespace std;

string solution(int _age)
{

	string answer;

	string temp = to_string(_age);
	answer.reserve(temp.length());
	
	for (char c : temp)
	{

		answer.push_back(c - '0' + 'a');
	}

	/*
	while (_age > 0)
	{

		int calc = _age % 10;
		char c = calc + 'a';
		answer.push_back(c);

		_age /= 10;
	}

	reverse(answer.begin(), answer.end());
	*/
	return answer;
}