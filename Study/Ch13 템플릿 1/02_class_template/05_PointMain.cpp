/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : Ŭ���� ���ø�
	�ڵ����� : Main �Լ� ����
*/

#include <iostream>
#include "03_PointTemplate.h"
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