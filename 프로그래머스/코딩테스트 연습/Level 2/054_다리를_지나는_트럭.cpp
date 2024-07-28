/*
��¥ : 2024. 7. 29
�̸� : �輺��
���� : �ٸ��� ������ Ʈ��
	Ʈ�� ���� �밡 ���� ���������� ������ �ٸ��� ������ ������ �ǳʷ� �Ѵ�
	��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� Ȯ���ؾ� �Ѵ�

	�ٸ����� Ʈ���� �ִ� bridge_length�� �ö� �� ������,
	�ٸ��� weigth ���ϱ����� ���Ը� �ߵ� �� �ִ�
	��, �ٸ��� ������ ������ ���� Ʈ���� ���Դ� �����Ѵ�

	�ٸ��� �ö� �� �ִ� Ʈ�� �� bridge_length,
	�ٸ��� �ߵ� �� �ִ� ���� weight,
	Ʈ���� ���� truck_weights�� �Ű������� �־��� ��,
	��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ�����
	return �ϴ� solution �Լ� ����

	weight, bridge_length�� 1�� ������ �ڿ���
	truck_weights�� ���̴� 1�� �����̰�
	��� Ʈ���� ���Դ� weight �����̴�


	parameter
	2, 10, { 7, 4, 5, 6 }


	return
	8


	sol
	
	�ð�	������ Ʈ��		�ٸ� ���� Ʈ��		������� Ʈ��
	0											7, 4, 5, 6
	1						7					4, 5, 6
	2						7					4, 5, 6
	3		7				4					5, 6
	4		7				4, 5				6
	5		7, 4			5					6
	6		7, 4, 5			6					
	7		7, 4, 5			6
	8		7, 4, 5, 6

	�̵ȴ�
*/

#include <vector>
#include <queue>
#include <cmath>

#define mp make_pair
#define pii pair<int, int>

using namespace std;

int solution(int _bridge_length, int _weight, vector<int> _truck_weights)
{

	/*
	
	ť ����
	*/
	int answer = 0;

	queue<pii> q;			// ���� ����, �ٸ� ���� �ð�
	
	int curTime = 0;
	int curWeight = 0;

	for (int truck : _truck_weights)
	{

		// �ٸ� ���� Ȯ��
		while (q.size() && _weight < curWeight + truck)
		{

			// ���� �ʰ�
			// �Ǿ��� Ʈ��
			pii f = q.front();
			q.pop();
			// �ٸ��� �ִ� ������ �ð�����
			curTime = max(curTime, f.second + _bridge_length - 1);
			curWeight -= f.first;
		}

		// �����ö󰣴�
		curTime++;
		curWeight += truck;
		q.push(mp(truck, curTime));
	}

	answer = q.back().second + _bridge_length;
	return answer;
}