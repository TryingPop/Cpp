#include <iostream>
#include <string>
#include <vector>

/*
��¥ : 2024. 2. 9
�̸� : �輺��
���� : ���� ����Ʈ�� ���ڿ��� ��ȯ�ϱ�
	arr�� ���Ҵ� ���ĺ� �ҹ��ڷ��� �̷���� ���̰� 1�� ���ڿ��̴�
	arr�� ���ҵ��� ������� �̾� ���� ���ڿ��� return�ϴ� solution �Լ������ϱ�

	input
	arr = { "a", "b", "c" };
	
	answer
	abc

	string�� push_back�� �� �� �ִ� �Ű������� char���̰�,
	string�� �������� append�� ����Ѵ�
*/

using namespace std;

string solution(vector<string> _arr)
{

	string answer = "";
	answer.reserve(_arr.size());

	for (string c : _arr) 
	{

		// answer.push_back(c[0]);
		answer.append(c);
	}

	return answer;
}