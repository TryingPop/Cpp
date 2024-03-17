#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 17
�̸� : �輺��
���� : ��� ���ϱ�
	���� n�� �Ű������� �־��� ��,
	n�� ����� ������������ ���� �迭��
	return �ϵ��� solution �Լ��� ����

	n�� 1�� ������ �ڿ���
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;
	
	// �����佺 �׳׽��� ü �̷��� ������ ����
	// Ŀ���� 100������ Ž���ϴµ� 
	// ��� ������ �߰ߵǴ� ���
	// ���ƾ� 200�� ũ�� ���� �Ҵ�
	// ������ �� ����!
	answer.reserve(200);

	for (int i = 1; i <= _n; i++)
	{

		if (i * i > _n) break;
		if (_n % i) continue;

		int div1 = i;
		int div2 = _n / i;

		answer.push_back(div1);
		if (div1 != div2) answer.push_back(div2);
	}

	sort(answer.begin(), answer.end());
	return answer;
}