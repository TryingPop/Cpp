#include <vector>

/*
��¥ : 2024. 2. 25
�̸� : �輺��
���� : �迭�� ���Ҹ�ŭ �߰��ϱ�
	�ƹ� ���ҵ� ������� ���� �� �迭 X�� �ִ�
	���� ������ �̷���� �迭 arr�� �־��� ��,
	arr�� �տ������� ���ʴ�� ���Ҹ� ���鼭
	���Ұ� a��� X�� �� �ڿ� a�� a����ŭ �߰��ϴ�
	���� �ݺ��� ���� �迭 X�� return�ϴ�
	solution �Լ��� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> answer;

	for (const int i : _arr)
	{

		for (int j = 0; j < i; j++)
		{

			answer.push_back(i);
		}
	}
	return answer;
}