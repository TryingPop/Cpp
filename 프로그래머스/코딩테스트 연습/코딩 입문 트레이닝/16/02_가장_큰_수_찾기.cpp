#include <vector>

/*
��¥ : 2024. 3. 18
�̸� : �輺��
���� : ���� ū �� ã��
	���� �迭 array�� �Ű������� �־��� ��,
	���� ū ���� �� ���� �ε����� ���� �迭��
	return �ϵ��� solution �Լ��� ����

	array�� �ߺ��� ���� ����
*/

using namespace std;

vector<int> solution(vector<int> _array)
{

	vector<int> answer(2, 0);
	answer[0] = _array[0];

	for (int i = 1; i < _array.size(); i++)
	{

		if (_array[i] <= answer[0]) continue;

		answer[0] = _array[i];
		answer[1] = i;
	}
	return answer;
}