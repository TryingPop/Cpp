/*
��¥ : 2024. 3. 10
�̸� : �輺��
���� : ������
	������ 0 �ʰ� 90 �̸��� ����
	90���� ����
	90 �ʰ� 180 �̸��� �а�
	180���� ��

	�� 0 �ʰ� 180������ ���� angle�� �Ű������� �־��� ��
	���� 1, ���� 2, �а� 3, �� 4��
	return �ϴ� solution �Լ� ����
*/

int solution(int _angle)
{

	int answer;

	if (_angle < 90) answer = 1;
	else if (_angle == 90) answer = 2;
	else if (_angle < 180) answer = 3;
	else answer = 4;

	return answer;
}