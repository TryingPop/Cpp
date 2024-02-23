#include <string>
#include <vector>

/*
��¥ : 2024. 2. 23
�̸� : �輺��
���� : Ư�� ���ڿ��� ������ ���� �� �κ� ���ڿ� ã��
	���ڿ� myString�� pat�� �־�����
	myString�� �κ� ���ڿ� �� pat���� ������ 
	���� �� �κ� ���ڿ��� ã�Ƽ� return �ϴ� 
	solution �Լ��� ����

	pat�� �ݵ�� myString�� �κ� ���ڿ��� �־�����
	pat�� ���ĺ��� ��ҹ��ڷ� �����ؾ��Ѵ�
*/

using namespace std;

string solution(string _myString, string _pat) 
{

	string answer = "";

	int rpos = _myString.rfind(_pat);

	if (rpos != -1) 
	{

		answer.append(_myString.substr(0, rpos));
		answer.append(_pat);
	}

	return answer;
}