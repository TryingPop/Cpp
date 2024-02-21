#include <vector>

/*
��¥ : 2024. 2. 21
�̸� : �輺��
���� : ���ǿ� �°� ���� ��ȭ�ϱ� 2
	���� �迭 arr�� �־�����
	arr�� �� ������ ���� 50���� ũ�ų� ���� ¦����� 2�� ������,
	50���� ���� Ȧ����� 2�� ���ϰ� 1�� ���Ѵ�

	�̷��� �۾��� x�� �ݺ��� ����� �迭�� arr(x)��� ǥ������ ��,
	arr(x) = arr(x + 1)�� x�� �׻� �����Ѵ�
	(���⼭ =�� ��ǻ�Ϳ��� ���� ���Կ����ڰ��ƴ϶� ������ �ǹ��ϴ� ��ȣ�� ���!)
	�̷��� x�� ���� ���� ���� return�ϴ� solution �Լ� ����
	
*/

using namespace std;

int solution(vector<int> _arr)
{

	int answer = 0;

	vector<int> temp;
	temp.reserve(100);

	for (int i = 1; i <= 100; i++)
	{

		int repeatNum = 0;
		int calc = i;

		while (true)
		{

			if ((calc & 1) && calc < 50)
			{

				calc *= 2;
				calc++;
				repeatNum++;
			}
			else if (!(calc & 1) && calc >= 50)
			{

				calc /= 2;
				repeatNum++;
			}
			else break;
		}
		
		temp.push_back(repeatNum);
	}

	for (const int i : _arr) 
	{

		int chk = temp[i - 1];
		if (chk > answer) answer = chk;
	}

	return answer;
}