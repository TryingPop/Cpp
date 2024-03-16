#include <vector>

/*
��¥ : 2024. 3. 16
�̸� : �輺��
���� : ����� ��
	���� �迭 array�� ���� n�� �Ű������� �־��� ��,
	array�� ����ִ� ���� �� n�� ����
	����� ���� return �ϴ� solution �Լ� ����

	���� ����� ���� ���� ���� ���
	�� ���� ���� return
*/

using namespace std;

int solution(vector<int> _array, int _n)
{

	int answer;

	// _array�� ������ ä
	// _n ��ӵǼ� _n�� �Է��ϸ�
	// _array�� �����ϰ� ���� Ž������ Ǫ�°� ����
	int min = _n - _array[0];
	min = min < 0 ? -min : min;

	int minIdx = 0;

	for (int i = 1; i < _array.size(); i++)
	{

		int calc = _n - _array[i];
		calc = calc < 0 ? -calc : calc;

		if (calc < min) 
		{

			min = calc;
			minIdx = i;
		}
		else if (min == calc && _array[minIdx] > _array[i])
		{

			minIdx = i;
		}
	}

	answer = _array[minIdx];
	return answer;
}