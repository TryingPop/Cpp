#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 8
�̸� : �輺��
���� : �߾Ӱ� ���ϱ�
	���� �迭 array�� �Ű������� �־��� ��,
	�߾Ӱ��� return �ϴ� solution �Լ� ����

	�߾Ӱ��̶� ������������ ���� ���� ��,
	���� �߾ӿ� �ִ� ���Ҹ� �ǹ�
*/

using namespace std;

int solution(vector<int> _array)
{

	int answer;
	sort(_array.begin(), _array.end());
	// �߾ӿ� �ִ� �ε����� ����Ų��
	int mid = _array.size() / 2;
	answer = _array[mid];
	return answer;
}