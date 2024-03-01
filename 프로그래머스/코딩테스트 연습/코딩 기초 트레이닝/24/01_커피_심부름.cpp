#include <string>
#include <vector>

/*
��¥ : 2024. 3. 1
�̸� : �輺��
���� : Ŀ�� �ɺθ�
	ī�信�� Ŀ�Ǹ� �߰ſ�� ������� �������
	�󶼸� 5000��, �ܴ̿� ��� �ϰ������� 4500���� �Ǵ�

	�ֹ��ϴ� �޴��� string ����Ʈ�� order�� �־����� ��,
	�����ϰ� �� �ݾ��� ���
*/

using namespace std;

int solution(vector<string> _order) 
{

	int answer = 0;

	for (const string str : _order)
	{

		if (str.find("caffelatte") != string::npos) answer += 5000;
		else answer += 4500;
	}

	return answer;
}