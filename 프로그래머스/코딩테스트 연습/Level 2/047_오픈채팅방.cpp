/*
날짜 : 2024. 7. 23
이름 : 배성훈
내용 : 오픈채팅방
	오픈 채팅방 관리자 창을 만들었다
	채팅방에 누군가 들어오면 다음 메시지가 출력된다
	"[닉네임]"님이 들어왔습니다."

	채팅방에서 누군가 나가면 다음 메시지가 출력된다
	"[닉네임]님이 나갔습니다."

	채팅방에서 닉네임을 변경하는 방법은 두 가지이다
	채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다
	채팅방에서 닉네임을 변경한다

	닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 
	메시지의 닉네임도 전부 변경된다

	채팅방에 들어오고 나가거나,
	닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때,
	모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는
	메시지를 문자열 배열 형태로 return 하는 solution 함수 구현

	record는 문자열이 담긴 배열이며
	길이는 10만 이하의 자연수이다

	record는 모든 유저는 유저아이디로 구분한다
	유저 아이디 사용자가 닉네임으로 채팅방에 입장은
	"Enter [유저 아이디] [닉네임]"
	으로 입력된다

	유저 아이디 사용자가 닉네임으로 채팅방에 퇴장은
	"Leave [유저 아이디]"
	으로 입력된다

	유저 아이디 사용자가 닉네임을 닉네임1으로 변경은
	"Change [유저 아이디] [닉네임1]"
	으로 입력된다

	첫 단어는 Enter, Leave, Change 중 하나이다
	각 단어는 공백으로 구분된다

	유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다
	유저 아이디와 닉네임의 길이는 1 이상 10이하다

	채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못된 입력은 주어지지 않는다

	parameter
	{ "Enter uid1234 Muzi", 
	  "Enter uid4567 Prodo", "Leave uid1234",
	  "Enter uid1234 Prodo", "Change uid4567 Ryan" }

	
	return
	{ "Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", 
	  "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다." }


	sol
	채팅방에 "Muzi"와 "Prodo"라는 닉네임을 사용하는
	사람이 순서대로 들어오면 채팅방에는 다음과 같은 메시지가 출력된다

	"Muzi님이 들어왔습니다."
	"Prodo님이 들어왔습니다."

	채팅방에 있던 사람이 나가면 채팅방에는 다음과 같은 메시지가 남는다
	"Muzi님이 들어왔습니다."
	"Prodo님이 들어왔습니다."
	"Muzi"님이 나갔습니다."

	Muzi가 나간후 다시 들어올 때 Prodo라는 닉네임으로 들어올 경우
	기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다
	"Prodo님이 들어왔습니다."
	"Prodo님이 들어왔습니다."
	"Prodo님이 나갔습니다."
	"Prodo님이 들어왔습니다."

	채팅방은 중복 닉네임을 허용하기 때문에,
	현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다
	이제 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면
	채팅방 메시지는 다음과 같이 변경된다

	"Prodo님이 들어왔습니다."
	"Ryan님이 들어왔습니다."
	"Prodo님이 나갔습니다."
	"Prodo님이 들어왔습니다."
	가 정답이 된다
*/

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

const string E = "Enter";
const string L = "Leave";
const string C = "Change";
const string ENTER = "님이 들어왔습니다.";
const string LEAVE = "님이 나갔습니다.";

stringstream ss;
string op, id, name;

inline void SetUserInfo(const vector<string>& _record, unordered_map<string, string>& _userInfo)
{

	/*
	
	유저 정보를 담는다
	*/

	for (int i = _record.size(); i >= 0; i--)
	{

		ss.clear();
		ss.str(_record[i]);

		// 명령어, 아이디, 이름
		ss >> op >> id >> name;
		
		if (op == L || _userInfo.count(id)) continue;
		_userInfo[id] = name;
	}
}

inline void GetRet(const string& _rec, unordered_map<string, string>& _userInfo, vector<string>& _ret) 
{

	/*
	
	명령어를 읽고 정답 형식으로 출력한다
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