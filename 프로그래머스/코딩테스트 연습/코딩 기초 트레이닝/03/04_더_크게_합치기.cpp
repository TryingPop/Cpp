#include <string>
#include <vector>

/*
��¥ : 2024. 2. 9
�̸� : �輺��
���� : �� ũ�� ��ġ��
	���ο� ���� +�� ����

	12 + 3 = 123
	3 + 12 = 312

	a, b�� �־��� ��,
	a + b�� b + a �� ū ���� ����ϰ� �ϴ� solution �Լ� �����
	a, b�� 1�� ������ �ڿ���

	input
	3 12

	answer
	312

	�׳� +����� max �Լ��� �̿��ϴ°� ���ƺ��δ�
*/

using namespace std;

int solution(int _a, int _b)
{

	int answer = 0;

	string strA = to_string(_a);
	string strB = to_string(_b);

	
	string calc = "";
	calc.reserve(strA.size() + strB.size());

	calc.append(strA).append(strB);
	int front = stoi(calc);
	calc.clear();
	calc.append(strB).append(strA);
	int back = stoi(calc);

	answer = ((front < back) ? back : front);
	return answer;
}