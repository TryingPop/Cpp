#include <vector>

/*
��¥ : 2024. 2. 17
�̸� : �輺��
���� : �迭 ����� 1
	���� n�� k�� �־����� ��, 1 �̻� n������ ���� �߿��� k�� �����
	������������ ������ �迭�� return�ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(int _n, int _k)
{

	vector<int> answer;
	
	for (int i = _k; i <= _n; i += _k)
	{

		answer.push_back(i);
	}
	
	return answer;
}