/*
��¥ : 2024. 2. 14
�̸� : �輺��
���� : ������ �� ����
	bool ���� x1, x2, x3, x4�� �Ű������� �־��� ��,
	(x1 or x2) and (x3 or x4)�� ����� ��ȯ�ϴ� �Լ��� ����
*/

bool solution(bool _x1, bool _x2, bool _x3, bool _x4)
{

	bool answer;
	answer = (_x1 || _x2) && (_x3 || _x4);
	return answer;
}