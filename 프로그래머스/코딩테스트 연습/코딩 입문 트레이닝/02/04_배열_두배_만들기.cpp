#include <vector>

/*
��¥ : 2024. 3. 7
�̸� : �輺��
���� : �迭 �ι� �����
	���� �迭 numbers�� �Ű������� �־��� ��,
	numbers�� �� ���ҿ� �ι��� ���Ҹ� ���� �迭��
	return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(vector<int> _numbers) 
{

	vector<int> answer;
	answer.reserve(_numbers.size());

	for (int i : _numbers)
	{

		answer.push_back(i * 2);
	}

	return answer;
}