#include <vector>
#include <string>
#define GROUP 5

/*
��¥ : 2024. 2. 20
�̸� : �輺��
���� : 5��
	�ִ� 5�� ž�� ������ ���̱ⱸ�� Ÿ�� ���� ���� ���ִ� 
	������� �̸��� ��� ���ڿ� ����Ʈ names�� �־��� ��,
	�տ������� 5�� ���� �׷��� ���� �տ� ���ִ� ������� �̸��� ���� ����Ʈ��
	return �ϴ� solution �Լ� ����
	������ �׷��� 5���� ���� �ʴ��� ���� �տ� �ִ� ����� �̸��� ����
*/
using namespace std;

vector<string> solution(vector<string> _names)
{

	vector<string> answer;

	for (int i = 0; i < _names.size(); i += GROUP)
	{

		answer.push_back(_names[i]);
	}
	return answer;
}