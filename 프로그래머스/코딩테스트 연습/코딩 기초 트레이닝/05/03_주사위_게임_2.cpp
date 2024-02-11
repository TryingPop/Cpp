#include <set>

/*
��¥ : 2024. 2. 11
�̸� : �輺��
���� : �ֻ��� ���� 2
	���� 1 ~ 6 ���� ����ü �ֻ��� a, b, c 3���� ������
		a, b, c�� �� ���ڰ� ��� �ٸ� ��� a + b + c�� ��ȯ
		�� �� ��� �� ���ڴ� ���� ������ �ϳ��� �ٸ� ��� ( a + b + c ) * ( a^2 + b^2 + c^2 )
		a, b, c ��� ���� ��� (a + b + c) * (a ^2 + b^2 + c^2) * ( a^3 + b^3 + c^3 )

	�� ���� ��ȯ�ϴ� �Լ� ����

	set �Ἥ ������ ����� �ִ�
	�ڷᱸ�� �����Ұ� set���� �غ���
*/

using namespace std;

int solution(int _a, int _b, int _c)
{

	int answer;

	answer = _a + _b + _c;
	set<int> s = { _a, _b, _c };

	// if (_a == _b || _a == _c || _b == _a) answer *= (_a * _a + _b * _b + _c * _c);
	if (s.size() >= 2) answer *= (_a * _a + _b * _b + _c * _c);

	// if (_a == _b && _a == _c) answer *= (_a * _a * _a + _b * _b * _b + _c * _c * _c);
	if (s.size() == 3) answer *= answer *= (_a * _a * _a + _b * _b * _b + _c * _c * _c);
	return answer;
}