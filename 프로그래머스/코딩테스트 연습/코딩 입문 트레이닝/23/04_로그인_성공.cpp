#include <string>
#include <vector>

/*
��¥ : 2024. 3. 26
�̸� : �輺��
���� : �α��� ����?
	���̵�� �н����尡 ��� �迭 id_pw��
	ȸ������ ������ ��� 2���� �迭 db�� �־��� ��,

	���̵�� ��й�ȣ ��� ��ġ�ϴ� ȸ�� ������ ���� ��
	login�� return

	�α����� ���� ���� �� ���̵� ��ġ�ϴ� ȸ���� ���ٸ�
	fail, ���̵�� ��ġ������ ��й�ȣ�� ��ġ�ϴ� ȸ���� ���ٸ�
	wrong pw�� return �ϴ� solution �Լ� ����

	db���� id�� �ߺ����� �ʴ´�
*/

using namespace std;

int comp(string& _str1, string& _str2)
{

	if (_str1.length() != _str2.length()) return 0;
	
	for (int i = 0; i < _str1.length(); i++)
	{

		if (_str1[i] != _str2[i]) return 0;
	}

	return 1;
}

string solution(vector<string> _id_pw, vector<vector<string>> _db)
{

	string answer;

	int id = 0;
	int pw = 0;

	for (vector<string> user : _db)
	{

		if (!comp(user[0], _id_pw[0])) continue;
		id = 1;
		if (comp(user[1], _id_pw[1])) pw = 1;
		break;
	}

	if (id & pw) answer = "login";
	else if (id) answer = "wrong pw";
	else answer = "fail";

	return answer;
}