#include <vector>
#include <cmath>

/*
��¥ : 2024. 2. 26
�̸� : �輺��
���� : �迭�� ���̸� 2�� �ŵ��������� �����
	���� �迭 arr�� �Ű������� �־�����
	arr�� ���̰� 2�� ���� �ŵ������� �ǵ���
	arr �ڿ� ���� 0�� �߰�
	arr�� �ּ����� ������ 0�� �߰��� �迭�� 
	return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> answer;

	int log = (int)ceil(log2(_arr.size()));
	int size = pow(2, log);

	answer.reserve(size);

	for (int i = 0; i < _arr.size(); i++)
	{

		answer.push_back(_arr[i]);
	}

	// ���� �κ� 0���� ä���
	answer.resize(size, 0);

	return answer;
}