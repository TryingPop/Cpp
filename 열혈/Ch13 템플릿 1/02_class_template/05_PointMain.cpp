/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : Ŭ���� ���ø�
	�ڵ����� : Main �Լ� ����

	���� 546 ~ 547p ���� ����
*/

#include <iostream>
#include "03_PointTemplate.h"
// �Ʒ� ���� ������ ������ ���� ���
// �����Ͽ��� Point<int>, Point<double>, Point<char> Ŭ������ ����
// �̸� ���ؼ��� 04_PointTemplate.cpp �� ������ ������ �� �־���Ѵ�
// Main�� �������� �� 04�� ������ �ϴϱ� 04�� ��� ���뵵 �˰� �ִ°� �ƴϳĴ� ������ �� �� �ִ�.
// ���ÿ� ������ �Ǵ°� ������ �̵��� ���� �ٸ� �ҽ����Ͽ� �־
// ������ ���� ��Ģ�� ���ؼ� Main�� �������ϸ鼭 04�� ������ ���� �ʰ�
// ���� 04�� �������ϸ鼭 Main�� �������� �ʴ´�
// ���� ������ ������ �߻��Ѵ�
#include "04_PointTemplate.cpp"

using namespace std;

int main(void) 
{
	
	Point<int> pos1(3, 4);
	pos1.ShowPosition();		// [3, 4]

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();		// [2.4, 3.6]

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();		// [P, F]

	return 0;
}