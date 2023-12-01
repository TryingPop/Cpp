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

#include <ctime>	// time
#include <cstdlib>	// srand, rand
#include <iostream>	// cout, endl

using namespace std;

int main(void)
{

	srand((unsigned int)time(NULL));	// ���� �ð��� �������� seed�� ����
	
	int nums[5];
	
	for (int i = 0; i < 5; i++) {
		
		bool chk = true;

		while (chk) {
			chk = false;
			int rd = rand() % 100; // 0 ~ 100 ������ �ڿ����� ���� ���� 
			nums[i] = rd;

			// �ߺ� üũ
			for (int j = 0; j < i; j++) {

				if (nums[j] == rd) {

					chk = true;
					break;
				}
			}
		}
	}

	cout << nums[0] << endl;
	cout << nums[1] << endl;
	cout << nums[2] << endl;
	cout << nums[3] << endl;
	cout << nums[4] << endl;
}