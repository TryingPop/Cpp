/*
��¥ : 2023. 12. 01
�̸� : �輺��
���� : ����� ����
	���� : 39 ~ 43p
	
	�� å�� ������ C++�� ȿ�������� �����ϴ� ����� ������ �ִ� ��
	��, C++ ��� �� ����ؼ� ������ ����Ʈ��� �����ϱ� ���� ������������ �׸��̰� 
	�̽ļ�, Ȯ�强, ȿ�������� ������ �����̸� �ǵ���� �����ϰ� ���� ������ 
	���� ���� ���� �ʴ� �׷� ������� �Ǵ� ��  ������ �� ��ħ Ȥ�� ������� ��Ƶ� å
*/

#include <cstddef>									// size_t

// ���� - �ڵ忡 ���Ǵ� � ����� �̸��� Ÿ���� �����Ϸ����� �˷� �ִ� ��
extern int x;										// ��ü ����
													// ������ �⺻����(built-in) Ÿ���ε��� ��ü�� ǥ��

std::size_t numDigits(int number);					// �Լ� ����
													// size_t�� ������ �� �� �� Ÿ���� �̿�
													// ����ϰ� char* ����� ���ڿ� ũ��, STL �����̳��� ���� ���� ��
													// vector, string�� operator[] �Լ��� ���ϴ� Ÿ��
													// operator[] �Լ��� ������ ���� size_t�� �޵��� ����°� �Ծ�
													// ��� �Լ��� ���𹮿��� �ñ״�ó(signature), �Լ��� �Ű����� ����Ʈ�� ��ȯ Ÿ���� ���� �ִ�

class Widget;										// Ŭ���� ����

template<typename T>								// ���ø� ����
class GraphNode;						

// ���� - ���𿡼� ���� ��ü���� ���λ����� �����Ϸ����� ����
int x;												// ��ü ����

std::size_t numDigits(int number) {					// �Լ� ����

	std::size_t digitsSoFar = 1;					// �� �Լ��� ��ȯ ���� �Ű������� ��� �ִ� ������ ����

	while ((number /= 10) != 0) ++digitsSoFar;
	return digitsSoFar;
}

class Widget {										// Ŭ���� ����

public:

	Widget();
	~Widget();
};

template<typename T>
class GraphNode {									// ���ø� ����

public:

	GraphNode();
	~GraphNode();
};