#include <vector>

/*
��¥ : 2024. 2. 13
�̸� : �輺��
���� : �ݶ��� ���� �����
	��� �ڿ��� x�� ���� x�� ¦���̸� 2�� ������, x�� Ȧ���� 3 * x + 1�� �ٲ۴�
	�ش� ����� �ݺ��ϸ� 1�� �ȴٰ� �����ϴ°� �ݶ��� ����

	1000���� �۰ų� ���� ���� ���ؼ��� �����Ѵ�
	1000���� ���� �ڿ��� n�� �־��� ��, �ʱⰪ�� n�� �ݶ��� ������ ��ȯ�ϴ� �Լ������
*/

using namespace std;

vector<int> solution(int _n)
{

	vector<int> answer;

	answer.push_back(_n);
	
	while (_n != 1)
	{

		if (_n & 1) _n = _n * 3 + 1;
		else _n = _n / 2;

		answer.push_back(_n);
	}

	return answer;
}