/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : �Լ� ���ø��� Ư��ȭ
	���� �������� �Լ� ���ø��� Ư��ȭ�� �غ���
*/

#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {

	return a > b ? a : b;
}

// ���ڿ��� ���� ��
// �����Ϸ����� char* �� ���ø� �Լ��� �ʿ��� ��� 
// ������ ������ ���� �̰��� ���� �ǹ�
template <>
char* Max(char* a, char* b) {

	cout << "char* Max<char*>(char*, char*)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max(const char* a, const char* b) {

	cout << "const char* Max<const char*>(const char*, const char*)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{

	cout << Max(11, 15) << endl;			// 15
	cout << Max('T', 'Q') << endl;			// T
	cout << Max(3.5, 7.5) << endl;			// 7.5
	cout << Max("Simple", "Best") << endl;	// const char* Max...
											// Simple

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;		// char* Max...
											// Simple
	return 0;
}