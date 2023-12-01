/*
��¥ : 2023. 2. 21
�̸� : �輺��
���� : ���� 469p ����2
	�̹����� ��� ��Ƽ� 2���� �迭���ٿ� ���� ������ �����ε��� �����ϰ��� �Ѵ�.
	������ �̷��Ա��� �����ڸ� ���� �����ε� �ϴ� ���� ���� ����.
	�ٸ�, ���ڴ� ȣ����� ���� �� ������Ų�ٴ� ���鿡�� �� ������ �����ϴ� ���̴�.
	�׷��� �����е� �� ������ �ܼ��� ȣ��ɰ� ��ſ��� �������� ���ڴ�.
	�׷� ������ �����ϰڴ�.
	������ �̸����� Ŭ������ ��������.

		class BoundCheck2DIntArray { ... }

	�� Ŭ������ BoundCheckIntArray Ŭ������ 2���� �迭 �����̴�.
	���� ������ ���� ��ü�� �����ϸ�,
		BoundCheck2DIntArray arr2d(3, 4);

	���ο� ���� ���̰� ���� 3�� 4��, 
	int�� 2���� �迭ó�� �����ϴ� arr2d ��ü�� �����Ǿ�,
	������ ���·� �����͸� ���� �� ������ �� �־�� �Ѵ�.

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 4; m++) {
				arr2d[n][m] = n + m;
			}
		};

		for (int n = 0; n < 3; n++) {

			for (int m = 0; m < 4; m++) {
				cout << arr2d[n][m] << ' ';
			}

			cout << endl;
		};

	����� �� ���� [] �����ڸ� ���ÿ� �����ε� �ϴ� ���� ������ �ʱ� ������,
	���� ���� ������, 
		arr2d[n][m];
	�� ���� [] ������ ȣ���� �����ϰԲ� �����ؾ� �Ѵ�.
	��, ù ��° [] ���꿡 ���ؼ� ���� ������ ������ ���� �ؼ��Ǿ�� �ϸ�,
		(arr2d.operator[](n))[m];

	�׸��� arr2d.operator[](n) ������ ��ȯ ���� �̿��ؼ� �� ��° [] ������ ������ ���� �ؼ��Ǿ�� �Ѵ�.
		((��ȯ ��).operator[])(m);

	����� �̴� ȣ��� ���� �̻��� �ǹ̸� ������ ������,
	���� ������ ���� �����̴�, Ǯ�� ���ߴٰ� �ؼ� �Ǹ��� �ʿ�� ����.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheck2DIntArray {

	int** arr;
	int arrlen[2];	// �迭�� ũ��

public:
	BoundCheck2DIntArray(int num1, int num2) {

		arrlen[0] = num1;
		arrlen[1] = num2;

		// ���� �����͸� �̿��� ������ �迭�� ǥ��
		arr = new int*[num2];
		for (int i = 0; i < num2; i++) {

			arr[i] = new int[num1];
		}
	}

	int* operator[](int idx) {
		
		return arr[idx];
	}
};

int main(void)
{

	BoundCheck2DIntArray arr2d(2, 3);

	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 4; m++) {
			arr2d[n][m] = n + m;
		}
	};

	for (int n = 0; n < 3; n++) {

		for (int m = 0; m < 4; m++) {
			cout << arr2d[n][m] << ' ';
		}

		cout << endl;
	};
}