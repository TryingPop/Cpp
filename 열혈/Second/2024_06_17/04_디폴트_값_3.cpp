/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : �κ��� ����Ʈ �� ����
	���� p30 ~ 32

	�Ű����� ���θ� ����Ʈ ������ ������ �� ������ 
	�Ű������� �Ϻθ� ����Ʈ ���� ������ �� �ִ�

	�Ű������� �Ϻθ� ����Ʈ ������ �����ϴ� ���
	����Ʈ �� �����ϴ� �Ű��������� �����ʿ� ��ġ�ؾ��Ѵ�

	�Լ��� ���޵Ǵ� ���ڰ� ���ʿ��� ���������� ä������ ������
	���ʿ� ����Ʈ ���� �ִ� ��� �����ʿ��� �����ϴ°� �Ұ����ϴٰ� ���� �ȴ�

	���� �Ʒ� �������� �ּ�ó���� �Լ��� ���ǵȴٸ�
	�����Ϸ��� � �Լ��� �ҷ����� ���� ������ ������ �߻���Ų��
*/

#include <iostream>

int BoxVolume(int _length, int _width = 1, int _height = 1);
// int BoxVolume(int _length) { return _length; } 
int main(void)
{

	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;	// 27
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;	// 25
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;		// 7

	return 0;
}

int BoxVolume(int _length, int _width, int _height)
{

	return _length * _width * _height;
}

