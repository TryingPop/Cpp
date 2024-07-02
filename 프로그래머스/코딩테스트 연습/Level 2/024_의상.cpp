/*
��¥ : 2024. 7. 2
�̸� : �輺��
���� : �ǻ�
	�ǻ���� ��� 2���� �迭 clothes�� �Ű������� �־�����
	clothes�� �ǻ��� �̸�, �ǻ��� ������ �̷��� �ְ�
	�ǻ��� ������ �ִ� 1���� �ǻ� ������ �� �ִ�

	������ �ǻ��� �Ϻΰ� ��ġ���� �ٸ� �ǻ��� ��ġ�� �ʰų�,
	Ȥ�� �ǻ��� �߰��� �� ������ ��쿡�� ���� �ٸ� ������� ���� ������ ������ ����

	�׸��� �ּ� 1���� �ǻ��� �Ծ�� �Ѵ�
	���� �ٸ� ���� ������ ���� return �ϴ� solution �Լ� ����

	���� �̸��� ���� �ǻ��� �������� �ʴ´�
	��� ���ڿ��� ���ĺ� �ҹ��� �Ǵ� ��� ��(_)�θ� �̷��� �ִ�


	parameter
	{ { "yellow_hat", "headgear" }, 
	  { "blue_sunglasses", "eyewear" }, 
	  { "green_turban", "headgear" } }


	return
	5


	sol
	yellow_hat
	blue_sunglasses
	green_turban
	yellow_hat + blue_sunglasses
	green_turban + blue_sunglasses

	�� 5������ �����Ѵ�
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> _clothes)
{

	int answer = 0;

	unordered_map<string, int> cnt;
	for (vector<string>& vec : _clothes)
	{

		if (cnt.count(vec[1])) cnt[vec[1]]++;
		else cnt[vec[1]] = 2;
	}

	answer = 1;
	for (pair<string, int> element : cnt)
	{

		answer *= element.second;
	}

	answer--;

	return answer;
}