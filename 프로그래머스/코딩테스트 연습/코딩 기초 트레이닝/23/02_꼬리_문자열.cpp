#include <string>
#include <vector>

/*
��¥ : 2024. 2. 29
�̸� : �輺��
���� : ���� ���ڿ�
	���ڿ� ����Ʈ str_list�� 
	�����Ϸ��� ���ڿ� ex�� �־�����
	
	str_list���� ex�� ������ ���ڿ��� �����ϰ� 
	���� ���� ���ڿ��� return�ϴ� solution �Լ��� ����

	���⼭ ���ϴ� list�� ���� ���ڿ���
	list�� ���Ҹ� �̾� ���� ���ڿ��� �ǹ��Ѵ�
	list = { str1, str2 }���,
	�������ڿ��� str1.append(str2) �� ���̴�
*/

using namespace std;

string solution(vector<string> _str_list, string _ex)
{

	string answer = "";

	for (const string str : _str_list)
	{

		// ex�� �����ϸ� �̾������ �ʴ´�
		if (str.find(_ex) != string::npos) continue;

		answer.append(str);
	}

	return answer;
}