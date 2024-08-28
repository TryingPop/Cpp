/*
��¥ : 2024. 8. 28
�̸� : �輺��
���� : ���� ĳ��
	������ ��̷� ���꿡�� ������ ĳ���� �Ѵ�
	������ ���̾Ƹ�� ���, ö ���, �� ��̸�
	���� 0������ 5������ ������ ������,

	��̷� ������ Ķ ���� �Ƿε��� �Ҹ�ȴ�
	�� ��̷� ������ Ķ ���� �Ƿε��� ������ ����

		
	���	/	����		���̾Ƹ��		ö		��
		���̾Ƹ��			1				1		1
		ö					5				1		1
		��					25				5		1

	�� ��̴� ������ ������� ���� 5���� ĵ �Ŀ���
	�� �̻� ����� �� ����

	������ ������ ���� ��Ģ�� ��Ű�鼭 �ּ����� �Ƿε��� ������ ĳ���� �Ѵ�

	����� �� �ִ� ��� �� �ƹ��ų� �ϳ��� ������ ������ ĵ��
	�� �� ����ϱ� ������ ��̴� ����� �� ���� ������ ����Ѵ�
	������ �־��� ������θ� Ķ �� �ִ�
	���꿡 �ִ� ��� ������ ĳ�ų�, �� ����� ��̰� ���� ������ ������ ĵ��

	��, ��̸� �ϳ� �����ؼ� ���� 5���� �������� ĳ��,
	���� ��̸� �����ؼ� ���� 5���� �������� ĳ�� ������ �ݺ��ϸ�,
	�� ����� ��̰� ���ų� ���꿡 �ִ� ��� ������ Ķ ������ ������ �ݺ��ϸ� �ȴ�

	������ ���� �ִ� ����� ������ ��Ÿ���� picks�� 
	������ ������ ��Ÿ���� ���ڿ� �迭 minerals�� �Ű������� �־��� ��,
	������ �۾��� ��������� �ʿ��� �ּ����� �Ƿε��� 
	return �ϴ� solution �Լ� ����

	picks�� { dia, iron, stone }�� ���� ������ �̷���� �ִ�
	dia, iron, stone�� 5 ������ ���̾ƴ� ����
	dia�� ���̾Ƹ�� ����� ���� �ǹ��Ѵ�
	iron�� ö ����� ���� �ǹ��Ѵ�
	stone�� �� ����� ���� �ǹ��Ѵ�
	��̴� ġ�Ǽ� 1�� �̻� ���� �ִ�

	minerals�� ���̴� 5 �̻� 50����
	minerals�� ���� 3���� ���ڿ��� �̷���� ������ ������ �ǹ̴� ������ ����
	diamond : ���̾Ƹ��, iron : ö, stone : ��


	parameter
	{ 1, 3, 2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" }


	return
	12


	sol
	diamond ���, iron ��� ������ ��̸� ����ϸ�
	12�� �Ƿε��� ������
	�� ���Ϸ� ������ ����� ���� ����
*/	

#include <string>
#include <vector>

#define Min(X, Y)	(((X) < (Y)) ? (X) : (Y))

using namespace std;

inline int GetScore(int _type, string& _m)
{

	/*
	
	������ ��̺��� �Ƿε��� ���� ��ȯ
	type: ��� ����
	0 : ���̾Ƹ��, 1 : ö, 2 : ��
	*/
	int ret;
	if (_m[0] == 'd') ret = 25;
	else if (_m[0] == 'i') ret = 5;
	else ret = 1;

	if (_type == 0) ret = 1;
	else if (_type == 1) ret /= 5;

	if (ret == 0) ret++;
	return ret;
}

inline int GetRangeScore(int _s, int _type, vector<string>& _minerals)
{

	/*
	
	�ش� ������ ��̺� �Ƿε��� ���Ѵ�
	type : ��� ����
	0 : ���̾Ƹ��, 1 : ö, 2 : ��

	s : ���� ����
	*/

	int ret = 0;
	// 5�� ������ ������� Ȯ��
	int e = Min(_s * 5 + 5, _minerals.size());

	for (int i = _s * 5; i < e; i++)
	{

		ret += GetScore(_type, _minerals[i]);
	}

	return ret;
}

inline int DFS(int _s, vector<int>& _picks, vector<string>& _minerals)
{

	/*
	
	�������� ��̸� ����ذ��� ���Ѵ�
	3^(50 / 5) ����� ����
	*/

	// ������ �� ĵ ���
	if (_minerals.size() < _s * 5) return 0;

	// ���� �� ���� ���� ū �Ƿε�
	int ret = 10'000;

	for (int i = 0; i < 3; i++)
	{

		// ��� �ٽ���� Ȯ��
		if (_picks[i] == 0) continue;

		// ��� type i�� ���� �ּ� �Ƿε��� ���Ѵ�
		_picks[i]--;
		int chk = GetRangeScore(_s, i, _minerals);
		chk += DFS(_s + 1, _picks, _minerals);

		if (chk < ret) ret = chk;
		_picks[i]++;
	}

	if (ret == 10'000) ret = 0;
	return ret;
}

int solution(vector<int> _picks, vector<string> _minerals)
{

	/*
	
	DFS, ���Ʈ����
	*/
	int answer = DFS(0, _picks, _minerals);
	return answer;
}