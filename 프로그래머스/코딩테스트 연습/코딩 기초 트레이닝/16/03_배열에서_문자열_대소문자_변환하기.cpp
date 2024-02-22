#include<string>
#include<vector>
#include<algorithm>

/*
��¥ : 2024. 2. 22
�̸� : �輺��
���� : �迭���� ���ڿ� ��ҹ��� ��ȯ�ϱ�
	���ڿ� �迭 strArr�� �־�����
	��� ���Ұ� ���ĺ����θ� �̷���� ���� ��,
	�迭���� Ȧ����° �ε����� ���ڿ��� ��� ���ڸ� �빮�ڷ�,
	¦����° �ε����� ���ڿ��� ��� ���ڸ� �ҹ��ڷ� �ٲ㼭 ��ȯ�ϴ�
	solution �Լ��� �ϼ�
*/

using namespace std;

vector<string> solution(vector<string> _strArr)
{

	vector<string> answer;

	for (int i = 0; i < _strArr.size(); i++) 
	{

		string temp = _strArr[i];

		if (i & 1) transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		else transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		answer.push_back(temp);
	}
	return answer;
}