#include <vector>

/*
��¥ : 2024. 2. 11
�̸� : �輺��
���� : ���������� Ư���� �׸� ���ϱ�
	���� �� a�� ���� d, �׸��� bool �迭 included�� �־�����
	bool �迭 ���� true�� �ε����� �ش��ϴ�
	���������� ���� ��ȯ�ϴ� �Լ��� ���ϴ� ����

	���� ��Ȳ�� �´� ���� ���� �ؾ߰ڴ�.
*/

using namespace std;

int solution(int _a, int _d, vector<bool> _included)
{

	int answer = 0;
	int num = _a - _d;
	// int num = _a;		// �ʱ� �ڵ�

	// for (int i = 0; i < _included.size(); i++) 
	for (const bool flag : _included)
	{

		num += _d;
		// if (_included[i]) answer += num;
		if (flag) answer += num;
		// num += _d;		// �ʱ� �ڵ�
	}
	return answer;
}