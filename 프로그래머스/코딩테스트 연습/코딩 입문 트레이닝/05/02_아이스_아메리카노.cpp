#include <vector>
#define AMERICANO 5'500

/*
��¥ : 2024. 3. 9
�̸� : �輺��
���� : ���̽� �Ƹ޸�ī��
	���̽� �Ƹ޸�ī��� �� �ܿ� 5,500��

	�Ӿ��̰� ������ �ִ� �� money�� ������ �־��� ��,
	�Ӿ��̰� �ִ�� ���� �� �մ� �Ƹ޸�ī���� �� ����
	���� ���� ������� ���� �迭��
	return �ϴ� solution �Լ� ����
*/

using namespace std;

vector<int> solution(int _money)
{

	vector<int> answer;
	answer.reserve(2);

	// �Ƹ޸�ī�� ��, ���� ��
	answer.push_back(_money / AMERICANO);
	answer.push_back(_money % AMERICANO);

	return answer;
}