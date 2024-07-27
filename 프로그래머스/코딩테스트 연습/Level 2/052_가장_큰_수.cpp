/*
��¥ : 2024. 7. 27
�̸� : �輺��
���� : ���� ū ��
	0 �Ǵ� ���� ������ �־����� ��,
	������ �̾�ٿ� ���� �� �մ� ���� ū ���� �˾Ƴ� �ּ���

	������� �־��� ������ { 6, 10, 2 }���
	{ 6102, 6210, 1062, 1026, 2610, 2106 }�� ���� �� �ְ�,
	���߿� ���� ū ���� 6210�̴�

	0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־����� ��,
	������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� 
	return �ϵ��� solution �Լ� ����

	numbers�� ���̴� 1 �̻� 10�� ����
	numbers�� ���Ҵ� 1'000 ������ ���� �ƴ� ����
	������ ���ڿ��� �ٲپ� return

	parameter
	{ 6, 10, 2 }


	return
	"6210"


	sol
	���� ���� �ִ�
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline bool MyComp(int _f, int _b)
{

	/*

	���� �� �Լ�
	f�� b�� �̾�ٿ��� �� ���ڸ� n1,
	b�� f�� �̾�ٿ��� �� ���ڸ� n2���ϸ�
	n1 > n2�̸� f�� �տ� �����Ѵ�

	string�� �� ������ ������ �����̰�,
	���̰� ���� ��� ���ڿ� ���ؼ��� ���� ũ�� ����� ������ ������ ����

	�׸��� ���� ���ڰ� ���ٸ� �� ū ���� �տ� �����Ѵ�
	*/

	string f = to_string(_f);
	string b = to_string(_b);

	string chk1 = f + b;
	string chk2 = b + f;

	if (chk1 != chk2) return chk1 > chk2;
	return _b < _f;
}

string solution(vector<int> _numbers)
{

	string answer = "";

	/*
	
	Greedy
	*/

	sort(_numbers.begin(), _numbers.end(), MyComp);

	// MyComp ���� ����� ���� �տ� �ִ� ���Ұ� ���ʿ� ���� ��� �� ū ���� �ȴ�
	// �̷��� �ִ밡 �ǰ� ����ؼ� �̾�ٿ������� ��� ��쿡�� �ִ밡 ����ȴ�
	if (_numbers[0])
	{

		for (int num : _numbers)
		{

			answer.append(to_string(num));
		}
	}
	// ���� ���� 0�̸� 00000���� �̾���̱⿡ �ݷ�ó��
	// ���̽� �߿� �ش� �κ� �����ϴ� ���� �ִ�
	else answer = "0";

	return answer;
}