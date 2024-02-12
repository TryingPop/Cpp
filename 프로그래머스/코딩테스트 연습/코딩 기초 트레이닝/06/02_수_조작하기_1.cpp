#include <string>

/*
��¥ : 2024. 2. 12
�̸� : �輺��
���� : �� �����ϱ� 1
	���� n�� ���ڿ� control�� �־�����
	control�� "w", "s", "a", "d"�� �̷���� ���ڿ��̴�
	control�� �տ������� ������� n�� �ٲ۴�
		w : n�� 1�� Ŀ����
		s : n�� 1�� �۾�����
		d : n�� 10�� Ŀ����
		a : n�� 10�� �۾�����
	�� ��Ģ�� ���� n�� �ٲ��� ��, ���� �������� ������ n�� ���� return�ϴ�
	solution �Լ��� �ϼ��ϱ�

	n�� -10�� ~ 10�������� ����
	control�� ���̴� 1���� 10�� ����

	�ּ�ģ �ڵ尡 �ش��ڵ庸�� ������
*/

using namespace std;

int solution(int _n, string _control) 
{

	int answer;

	answer = _n;

	int calc[128];
	// ���α׷��ӽ����� ��� �ȵȴ�;
	// memset(calc, 0, sizeof(calc));
	calc['w'] = 1;
	calc['s'] = -1;
	calc['a'] = 10;
	calc['d'] = -10;

	// calc['w'] = 0;
	// calc['s'] = 0;
	// calc['a'] = 0;
	// calc['d'] = 0;

	for (const char c : _control) 
	{

		// calc[c]++;
		answer += calc[c];
	}

	// answer += calc['w'];
	// answer -= calc['s'];
	// answer += 10 * calc['d'];
	// answer -= 10 * calc['a'];

	return answer;
}