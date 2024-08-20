/*
��¥ : 2024. 8. 20
�̸� : �輺��
���� : ���̺� �ؽ� �Լ�
	��ȣ�� �����ϴ� � �����ͺ��̽��� �� ���̺��� 
	��� ���� Ÿ���� �÷���� �̷���� �ִ�

	���̺��� 2���� ��ķ� ǥ���� �� ������
	���� �÷��� ��Ÿ���� ���� Ʃ���� ��Ÿ����

	ù ��° �÷��� �⺻Ű�μ� ��� Ʃ�ÿ� ���� 
	�� ���� �ߺ����� �ʵ��� ����ȴ�

	��ȣ�� �� ���̺� ���� �ؽ� �Լ��� ������ ���� �����ߴ�

	1. �ؽ� �Լ��� col, row_begin, row_end�� �Է����� �޴´�

	2. ���̺��� Ʃ���� col ��° �÷��� ���� 
	�������� �������� ������ �ϵ�, 
	���� �� ���� �����ϸ� �⺻Ű�� ù ��° �÷��� ���� ��������
	�������� �����Ѵ�

	3. ���ĵ� �����Ϳ��� S_i�� i��° ���� Ʃ�ÿ� ����
	�� �÷��� ���� i�� ���� ���������� ������ ����

	4. row_begin <= i <= row_end�� ��� S_i�� �����Ͽ�
	bitwise XOR�� ���� �ؽ� �����μ� ��ȯ�Ѵ�

	���̺��� ������ data�� �ؽ��Լ��� ����
	�Է� col, row_begin, row_end�� �־����� ��
	���̺��� �ؽ� ���� return �ϵ��� solution �Լ��� ����

	data�� ���̴� 2500������ �ڿ���,
	data�� ���� ���̴� 500 ������ �ڿ���

	data[i][j]�� ���� 100�� ������ �ڿ���
	data[i][j]�� i + 1 ��° Ʃ���� j + 1 ��° �÷��� ���� �ǹ��Ѵ�

	col�� data�� ������ ���� ������ �ڿ���
	1 <= row_begin <= row_end <= data�� ���̰� ����


	parameter
	{ { 2, 2, 6 }, {1, 5, 10 }, { 4, 2, 9 }, { 3, 8, 3 } }, 2, 2, 3


	return
	4


	sol
	���ǿ� ���� �����ϸ�
	{ 4, 2, 9 }, { 2, 2, 6 }, { 1, 5, 10 }, { 3, 8, 3 }
	������ ���ĵȴ�

	�׸��� Si�� 2 ~ 3�����̹Ƿ�
	S2 = (2 mod 2) + (2 mod 2) + (6 mode 2) = 0
	S3 = (1 mod 3) + (5 mod 3) + (10 mode 3) = 4

	�׸��� ������ S2 ^ S3 = 4���ȴ�
*/

#include <vector>
#include <algorithm>

using namespace std;

int comp;

bool MyComp(vector<int>& _f, vector<int>& _b)
{

	/*
	
	���� ����, col�� ���������� ��´�
	*/

	if (_f[comp] == _b[comp]) return _b[0] < _f[0];
	return _f[comp] < _b[comp];
}

int solution(vector<vector<int>> _data, int _col, int _row_begin, int _row_end)
{

	/*
	
	����, ����
	*/

	int answer = 0;
	comp = _col - 1;

	sort(_data.begin(), _data.end(), MyComp);

	vector<int> si;
	si.reserve(_row_end - _row_begin + 1);

	for (int r = _row_begin; r <= _row_end; r++)
	{

		int add = 0;
		for (int num : _data[r - 1])
		{

			// Si ���ϱ�
			add += num % r;
		}

		si.push_back(add);
	}

	// ������ xor����
	for (int num : si)
	{

		answer ^= num;
	}

	return answer;
}