#include <vector>
#include <string>

/*
��¥ : 2024. 2. 23
�̸� : �輺��
���� : ad �����ϱ�
	���ڿ� �迭 strArr�� �־�����
	�迭 ���� ���ڿ� �� ad��� �κ� ���ڿ��� �����ϰ� �ִ�
	��� ���ڿ��� �����ϰ� ���� ���ڿ��� ������� �����Ͽ�
	�迭�� return�ϴ� solution �Լ��� ����
*/

using namespace std;

vector<string> solution(vector<string> _strArr)
{

	vector<string> answer;

	for (const string s : _strArr)
	{

		int chk = s.find("ad");
		if (chk == string::npos) answer.push_back(s);
	}

	return answer;
}