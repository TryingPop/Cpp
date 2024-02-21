#include <vector>

/*
��¥ : 2024. 2. 21
�̸� : �輺��
���� : ���ǿ� �°� ���� ��ȯ�ϱ� 1
	���� �迭 arr�� �־�����
	arr�� �� ���ҿ� ���� ���� 50���� ũ�ų� ���� ¦����� 2�� ������,
	50���� ���� Ȧ����� 2�� ���Ѵ�
	�� ����� ���� �迭�� return�ϴ� solution �Լ��� ����
*/

using namespace std;

vector<int> solution(vector<int> _arr)
{

	vector<int> answer;
	answer = _arr;

	for (int i = 0; i < answer.size(); i++) 
	{

		if ((answer[i] & 1) && answer[i] < 50) answer[i] *= 2;
		else if (!(answer[i] & 1) && answer[i] >= 50) answer[i] /= 2;
	}
	return answer;
}