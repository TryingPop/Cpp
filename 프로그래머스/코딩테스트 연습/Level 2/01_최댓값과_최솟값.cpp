/*
��¥ : 2024. 6. 8
�̸� : �輺��
���� : �ִ񰪰� �ּڰ�
	���ڿ� s���� �������� ���е� ���ڵ��� ����Ǿ� �ִ�
	str�� ��Ÿ���� ���� �� �ּڰ��� �ִ��� ã��
	�̸� "(�ּڰ�) (�ִ�)" ������ ���ڿ��� ��ȯ�ϴ� �Լ�,
	solution �Լ��� ����

	������� s�� "1 2 3 4"��� "1 4"�� �����ϰ�,
	"-1 -2 -3 -4"��� "-4 -1"�� return�ϸ� �ȴ�

	s���� �� �̻��� ������ �������� ���еǾ� �ִ�
*/

#include <string>		// ���ڿ� �Է�
#include <sstream>		// split

using namespace std;

string solution(string _s)
{

	string answer;

	stringstream ss(_s);
	int n;

	int ret1 = 1e9;			// min
	int ret2 = -1e9;		// max

	// ������ �� �д´�
	while (ss >> n)
	{

		// �ִ� �ּڰ� ã��
		ret1 = n < ret1 ? n : ret1;
		ret2 = ret2 < n ? n : ret2;
	}

	// ��� ���¿� ���� ���
	answer = to_string(ret1) + " " + to_string(ret2);
	return answer;
}