#include <vector>

/*
��¥ : 2024. 3. 14
�̸� : �輺��
���� : ���μ�����
	�ڿ��� n�� �Ű������� �־��� ��,
	n�� ���μ��� ������������ ���� �迭��
	return �ϴ� solution �Լ��� ����

	�ٸ� ���μ��� �ߺ��ؼ� ���� �ʴ´�
	12�� ��� 2 * 2 * 3������
	2, 3�� �����ϸ� �ȴ�
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;

	// �����佺 �׳׽��� ü �̷�
	for (int i = 2; i <= _n; i++) 
	{

		// ���⼭ �����佺 �׳׽��� ü�̷� �̿�
		if (i * i > _n) break;
		if (_n % i) continue;

		// ������������ ã��,
		// ���μ��� ��� �����ϱ⿡
		// ã�� ���� �Ҽ��� ����ȴ�
		answer.push_back(i);
		while (!(_n % i))
		{

			_n /= i;
		}
	}

	// 1�� �ƴ� ��� _n�� �Ҽ��� ������
	// �ش� ���� �־�����Ѵ�
	if (_n != 1) answer.push_back(_n);
	return answer;
}