#include <vector>

/*
��¥ : 2024. 2. 12
�̸� : �輺��
���� : ������ �� ����
	���� ����Ʈ num_lis�� �־��� ��, ������ ���Ұ� ���� ���Һ��� ũ��
	������ ���ҿ��� ���� ���Ҹ� �� ����
	������ ���Ұ� ���� ���Һ��� ũ�� �ʴٸ� ������ ���Ҹ� �� ���� ���� �߰��Ͽ�
	return�ϴ� �Լ� �����
*/

using namespace std;

vector<int> solution(vector<int> _num_list)
{

	vector<int> answer;
	int size = _num_list.size();
	answer.reserve(4 * (size + 1));

	for (const auto n : _num_list)
	{

		answer.push_back(n);
	}

	// ���ؼ� �������� ���� �ֱ�
	if (answer[size - 2] < answer[size - 1]) answer.push_back(answer[size - 1] - answer[size - 2]);
	else answer.push_back(answer[size - 1] * 2);
	return answer;
}