#include <string>
#include <algorithm>

/*
��¥ : 2024. 2. 22
�̸� : �輺��
���� : �ҹ��ڷ� �ٲٱ�
	���ĺ����� �̷���� ���ڿ� myString
	��� ���ĺ��� �ҹ��ڷ� ��ȯ�Ͽ� return�ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _myString)
{

	string answer;

	answer = _myString;

	transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	return answer;
}