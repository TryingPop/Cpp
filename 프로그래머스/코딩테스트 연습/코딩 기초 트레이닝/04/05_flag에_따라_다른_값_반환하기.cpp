/*
��¥ : 2024. 2. 10
�̸� : �輺��
���� : flag�� ���� �ٸ� �� ��ȯ�ϱ�
	�� ���� a, b�� bool ���� flag�� �Ű������� �־��� ��,
	flag�� true�� a + b��, false�� a - b�� ��ȯ�ϴ� �Լ� �����
*/

int solution(int _a, int _b, bool _flag)
{

	int answer = 0;

	answer = _flag ? _a + _b : _a - _b;
	return answer;
}