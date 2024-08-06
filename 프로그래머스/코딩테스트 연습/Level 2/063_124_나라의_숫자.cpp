/*
��¥ : 2024. 8. 7
�̸� : �輺��
���� : 124 ������ ����
	124 ���󿡼��� 10������ �ƴ� ������ ���� ��Ģ����
	���� ǥ���Ѵ�

	124 ���󿡴� �ڿ����� �����Ѵ�
	124 ���󿡴� ��� ���� ǥ���� �� 1, 2, 4�� ����Ѵ�

	�ڿ��� n�� �Ű������� �־��� ��, 
	n�� 124 ���󿡼� ����ϴ� ���ڷ� �ٲ� ����
	return �ϴ� solution �Լ� ����

	n�� 5õ�� ������ �ڿ���

	parameter
	10


	return
	"41"


	sol
	
	����	124���� ����
	 1			 "1"
	 2			 "2"
	 3			 "4"
	 4			"11"
	 5			"12"
	 6			"14"
	 7			"21"
	 8			"22"
	 9			"24"
	10			"41"

	�̹Ƿ� "41"�̴�
*/

#include <string>
#include <vector>

using namespace std;

string solution(int _n)
{

	/*
	
	Greedy
	*/
	string answer = "";

	vector<char> num = { '1', '2', '4' };
	vector<int> tPow;		// �ڸ��� �� ���� �� (3�� ����)
	_n--;					// �������

	int add = 3;

	while (true) 
	{

		// �ڸ��� Ȯ��
		// �ڸ� �ʰ��ϴ� ���
		// ������ �ڸ����� ��ã�´�
		// ���� ���۰� ���ÿ� 3�� ������ ã�� �� �ִ�
		if (_n - add < 0) break;
		_n -= add;
		tPow.push_back(add);
		add *= 3;
	}

	while (tPow.size())
	{

		// ���� ū ������ ã�ư���
		int div = tPow.back();
		tPow.pop_back();
		int idx = _n / div;
		_n %= div;
		answer.push_back(num[idx]);
	}

	// ������ �ڸ��� ���� ó��
	answer.push_back(num[_n]);
	return answer;
}