#include <vector>
#include <string>

/*
��¥ : 2024. 2. 25
�̸� : �輺��
���� : �� ���� ������
	������ ���ڿ��� �־��� ��,
	���� a, b, c�� �����ڷ� �����
	���ڿ��� �������� �Ѵ�

	���ڿ� myStr�� �־����� ��,
	a, b, c�� ����� ������ ���ڿ��� �������
	������ �迭�� return �ϴ� solution �Լ� ����

	��, �� ������ ���̿� �ٸ� ���ڰ� ���� ��쿡
	�ƹ��͵� �������� ������
	return �� �迭�� �� �迭�̶��
	{ EMPTY }�� return
*/

using namespace std;

vector<string> solution(string _myStr)
{

	vector<string> answer;

	string temp;
	temp.reserve(_myStr.length());

	for (const char c : _myStr)
	{

		if (c == 'a' || c == 'b' || c == 'c')
		{

			if (temp.empty()) continue;

			answer.push_back(temp);
			temp.clear();
		}
		else temp.push_back(c);
	}

	if (!temp.empty()) answer.push_back(temp);

	if (answer.empty()) answer.push_back("EMPTY");
	return answer;
}