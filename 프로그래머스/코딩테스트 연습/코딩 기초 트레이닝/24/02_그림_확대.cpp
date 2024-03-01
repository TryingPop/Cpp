#include <vector>
#include <string>

/*
��¥ : 2024. 3. 1
�̸� : �輺��
���� : �׸� Ȯ��
	�׸������� 1 x 1 ũ���� ���簢�� ũ���� 
	�ȼ��� �̷���� �ִ�

	�׸������� ��Ÿ�� ���ڿ� �迭 picture�� 
	���� k�� �Ű������� �־��� ��,

	�� �׸������� ���� ���η� k�� �ø� �׸�������
	��Ÿ������ ���ڿ� �迭�� 
	return �ϴ� solution �Լ��� ����
*/

using namespace std;

vector<string> solution(vector<string> _picture, int _k)
{

	vector<string> answer;
	answer.reserve(_picture.size() * _k);

	string temp;
	temp.reserve(20 * _k);

	for (const string str : _picture)
	{

		for (const char c : str)
		{

			for (int i = 0; i < _k; i++) 
			{

				temp.push_back(c);
			}
		}

		for (int i = 0; i < _k; i++)
		{

			answer.push_back(temp);
		}

		temp.clear();
	}
	return answer;
}