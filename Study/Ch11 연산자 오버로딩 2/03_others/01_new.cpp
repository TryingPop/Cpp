/*
��¥ : 2023. 2. 16
�̸� : �輺��
���� : new ������
	new �����ڰ� �ϴ� ��
		1. �޸� ������ �Ҵ�
		2. �������� ȣ��
		3. �Ҵ��ϰ��� �ϴ� �ڷ����� �°� ��ȯ�� �ּ� ���� �� ��ȯ

	�� �� ��ü�� ���������� �ټ� ������ ������ ��ġ�Ƿ�
	�������� ȣ��� ��ȯ�� �ּ� ���� �� ��ȯ�� �����Ϸ��� å������
	�׷��� ���������� new �����ڸ� �����ε� �� ������ �޸� ������ �Ҵ縸 �����ε� ����
	
	new �����ڸ� �����ε��Ϸ��� ������ ���� ���·� �ؾ��Ѵ�
		void* operator new(size_t size) { ... }

	size_t�� �Ϲ������� ������ ���� ���ǵǾ��ִ�
	typedef unsigned int size_t;�� ���ǵǾ��� �ִ�
*/

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		: xpos(0), ypos(0) { }

	// ũ���� ������ ����Ʈ ����
	void* operator new(size_t size) {

		cout << "operator new : " << size << endl;
		void* adr = new char[size];	// char�� ũ�Ⱑ 1�̶� char ������ �޸� ������ �Ҵ��� ��ȯ
		// void* adr = malloc(size);
		return adr;
	}
};

int main(void)
{

	Point* pt = new Point(4, 5);
	return 0;
}