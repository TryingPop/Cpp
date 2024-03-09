#include <vector>

/*
��¥ : 2024. 3. 9
�̸� : �輺��
���� : ¦�� Ȧ�� ����
	������ ��� ����Ʈ num_list�� �־��� ��,
	num_list�� ���� �� ¦���� Ȧ���� ������ ���� �迭��
	return�ϴ� solution �Լ� ����

	���⼭ num_list�� ���Ҵ� ���̾ƴ� ����
*/

using namespace std;

vector<int> solution(vector<int> _num_list)
{

	// ũ�� 2, 0���� �ʱⰪ �Ҵ�
	vector<int> answer(2, 0);

	for (const int n : _num_list)
	{

		if (n & 1) answer[1]++;
		else answer[0]++;
	}

	return answer;
}