
/*
��¥ : 2023. 1. 25
�̸� : �輺��
���� : ���� 99p ����2
	���� �� �Լ��� �̿��ؼ� 0�̻� 100�̸��� ������ �� 5�� �����ϴ� ������ �����,
	C++ �� ����� �����ؼ� �ۼ��غ���.
	����� C����� ��� time �Լ��� <time.h>�� ����Ǿ� �ְ�,
	rand �Լ��� srand �Լ��� <stdlib.h>�� ����Ǿ� �ִ�.
		rand, srand, time
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void) 
{

	srand(time(NULL));

	for (int i = 0; i < 5; i++) {

		printf("Random number #%d : %d\n", i, rand() % 100);
	}
	return 0;
}