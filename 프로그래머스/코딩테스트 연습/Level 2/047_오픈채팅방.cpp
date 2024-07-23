/*
��¥ : 2024. 7. 23
�̸� : �輺��
���� : ����ä�ù�
	���� ä�ù� ������ â�� �������
	ä�ù濡 ������ ������ ���� �޽����� ��µȴ�
	"[�г���]"���� ���Խ��ϴ�."

	ä�ù濡�� ������ ������ ���� �޽����� ��µȴ�
	"[�г���]���� �������ϴ�."

	ä�ù濡�� �г����� �����ϴ� ����� �� �����̴�
	ä�ù��� ���� ��, ���ο� �г������� �ٽ� ����
	ä�ù濡�� �г����� �����Ѵ�

	�г����� ������ ���� ������ ä�ù濡 ��µǾ� �ִ� 
	�޽����� �г��ӵ� ���� ����ȴ�

	ä�ù濡 ������ �����ų�,
	�г����� ������ ����� ��� ���ڿ� �迭 record�� �Ű������� �־��� ��,
	��� ����� ó���� ��, ���������� ���� ������ ����� ���� �Ǵ�
	�޽����� ���ڿ� �迭 ���·� return �ϴ� solution �Լ� ����

	record�� ���ڿ��� ��� �迭�̸�
	���̴� 10�� ������ �ڿ����̴�

	record�� ��� ������ �������̵�� �����Ѵ�
	���� ���̵� ����ڰ� �г������� ä�ù濡 ������
	"Enter [���� ���̵�] [�г���]"
	���� �Էµȴ�

	���� ���̵� ����ڰ� �г������� ä�ù濡 ������
	"Leave [���� ���̵�]"
	���� �Էµȴ�

	���� ���̵� ����ڰ� �г����� �г���1���� ������
	"Change [���� ���̵�] [�г���1]"
	���� �Էµȴ�

	ù �ܾ�� Enter, Leave, Change �� �ϳ��̴�
	�� �ܾ�� �������� ���еȴ�

	���� ���̵�� �г����� ���ĺ� �빮��, �ҹ��ڸ� �����Ѵ�
	���� ���̵�� �г����� ���̴� 1 �̻� 10���ϴ�

	ä�ù濡�� ���� ������ �г����� �����ϴ� �� �߸��� �Է��� �־����� �ʴ´�

	parameter
	{ "Enter uid1234 Muzi", 
	  "Enter uid4567 Prodo", "Leave uid1234",
	  "Enter uid1234 Prodo", "Change uid4567 Ryan" }

	
	return
	{ "Prodo���� ���Խ��ϴ�.", "Ryan���� ���Խ��ϴ�.", 
	  "Prodo���� �������ϴ�.", "Prodo���� ���Խ��ϴ�." }


	sol
	ä�ù濡 "Muzi"�� "Prodo"��� �г����� ����ϴ�
	����� ������� ������ ä�ù濡�� ������ ���� �޽����� ��µȴ�

	"Muzi���� ���Խ��ϴ�."
	"Prodo���� ���Խ��ϴ�."

	ä�ù濡 �ִ� ����� ������ ä�ù濡�� ������ ���� �޽����� ���´�
	"Muzi���� ���Խ��ϴ�."
	"Prodo���� ���Խ��ϴ�."
	"Muzi"���� �������ϴ�."

	Muzi�� ������ �ٽ� ���� �� Prodo��� �г������� ���� ���
	������ ä�ù濡 �����ִ� Muzi�� Prodo�� ������ ���� ����ȴ�
	"Prodo���� ���Խ��ϴ�."
	"Prodo���� ���Խ��ϴ�."
	"Prodo���� �������ϴ�."
	"Prodo���� ���Խ��ϴ�."

	ä�ù��� �ߺ� �г����� ����ϱ� ������,
	���� ä�ù濡�� Prodo��� �г����� ����ϴ� ����� �� ���� �ִ�
	���� ä�ù濡 �� ��°�� ���Դ� Prodo�� Ryan���� �г����� �����ϸ�
	ä�ù� �޽����� ������ ���� ����ȴ�

	"Prodo���� ���Խ��ϴ�."
	"Ryan���� ���Խ��ϴ�."
	"Prodo���� �������ϴ�."
	"Prodo���� ���Խ��ϴ�."
	�� ������ �ȴ�
*/

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

const string E = "Enter";
const string L = "Leave";
const string C = "Change";
const string ENTER = "���� ���Խ��ϴ�.";
const string LEAVE = "���� �������ϴ�.";

stringstream ss;
string op, id, name;

inline void SetUserInfo(const vector<string>& _record, unordered_map<string, string>& _userInfo)
{

	/*
	
	���� ������ ��´�
	*/

	for (int i = _record.size(); i >= 0; i--)
	{

		ss.clear();
		ss.str(_record[i]);

		// ��ɾ�, ���̵�, �̸�
		ss >> op >> id >> name;
		
		if (op == L || _userInfo.count(id)) continue;
		_userInfo[id] = name;
	}
}

inline void GetRet(const string& _rec, unordered_map<string, string>& _userInfo, vector<string>& _ret) 
{

	/*
	
	��ɾ �а� ���� �������� ����Ѵ�
	*/
	ss.clear();
	ss.str(_rec);
	ss >> op >> id;

	name = _userInfo[id];

	if (op == C) return;
	else if (op == E) name.append(ENTER);
	else name.append(LEAVE);

	_ret.push_back(name);
}

vector<string> solution(vector<string> _record)
{

	vector<string> answer;
	answer.reserve(_record.size());

	unordered_map<string, string> userInfo;
	SetUserInfo(_record, userInfo);

	for (string& rec : _record)
	{

		GetRet(rec, userInfo, answer);
	}

	return answer;
}