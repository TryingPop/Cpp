#include <string>

/*
��¥ : 2024. 3. 29
�̸� : �輺��
���� : ���ڿ� �б�
	���ڿ� A�� B�� �Ű������� �־��� ��,
	A�� �о B�� �� �� �ִٸ�
	�о�� �ϴ� �ּ� Ƚ���� return�ϰ�
	�о B�� �� �� ���ٸ� -1��
	return �ϴ� solution �Լ� ����


	hello�� ��� 1ȸ �δٴ� ����
	������ ���������� 1ȸ ȸ�� ��Ű�� �Ͱ� ����
	�׷��� hello -> ohell �� �ȴ�

	���� int�� ���� �� �����ϸ�,
	�ּ� Ƚ���� ����Ѵ�

	A�� B�� ���̴� ����
*/

using namespace std;

int solution(string _A, string _B)
{

	int answer = -1;

	for (int i = 0; i < _A.size(); i++)
	{

		bool find = true;
		for (int j = 0; j < _A.size(); i++)
		{

			int idx = (i + j) % _A.size();
			if (_A[i] == _B[idx]) continue;

			find = false;
			break;
		}

		if (find)
		{

			answer = i;
			break;
		}
	}

#if other

	_B.reserve(2 * _A.size());
	_B += _B;
	answer = _B.find(_A);
#endif
	return answer;
}