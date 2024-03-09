#define PRICE_1 100'000
#define PRICE_2 300'000
#define PRICE_3 500'000

#define SALE_1 95 / 100
#define SALE_2 9 / 10
#define SALE_3 4 / 5

/*
��¥ : 2024. 3. 9
�̸� : �輺��
���� : �ʰ��� ���� �ޱ�
	10���� �̻� ��� 5%,
	30���� �̻� ��� 10%,
	50���� �̻� ��� 20%�� ����

	������ ���� ���� price�� ������ �־��� ��,
	�����ؾ��� �ݾ��� return�ϴ� solution �Լ� ����
*/

int solution(int _price)
{

	int answer;

	// ���� ���� �������� Ȯ���ϰ� ���ϰ� ���� ��Ų��
	if (_price < PRICE_1) answer = _price;
	else if (_price < PRICE_2) answer = _price * SALE_1;
	else if (_price < PRICE_3) answer = _price * SALE_2;
	else answer = _price * SALE_3;

	return answer;
}