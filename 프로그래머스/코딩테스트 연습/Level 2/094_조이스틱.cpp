/*
날짜 : 2024. 9. 7
이름 : 배성훈
내용 : 조이스틱
	조이스틱으로 알파벳 이름을 완성하시오
	맨 처음엔 A로만 이루어져 있다
	완성해야 하는 이름의 길이만큼 A로 채워져 있다

	조이스틱을 위로 움직이면 이전 알파벳으로
	
	조이스틱을 아래로 움직이면 다음 알파벳으로 갈 수 있다
	A는 Z로 간다

	조이스틱을 왼쪽으로 움직이면 커서가 왼쪽으로 이동한다 
	커서가 처음에 있는 경우에 쓰면 마지막으로 간다

	조이스틱을 오른쪽으로 움직이면 커서가 오른쪽으로 이동한다
	커서가 마지막 위치에 있는 경우 처음 위치로 간다

	만들고자 하는 이름 name이 매개변수로 주어질 때,
	이름에 대해 조이스틱 조작 횟수의 최솟값을 
	return 하는 solution 함수 구현

	name은 알파벳 대문자로만 이루어져 있다
	name의 길이는 1 이상 20 이하다

	parameter
	JAN

	
	return
	23


	sol
	초기에 상태는 name의 길이만큼 A가 있고 커서는 처음을 가리키고 있다
		AAA
		|

	처음 문자를 위로 9회 이동해서 J로 바꾼다 
		JAA
		|

	커서를 왼쪽으로 1회 이동한다
		JAA
		  |

	그리고 A를 N으로 바꾼다
	위로 13회 옮기던, 아래로 13회 옮겨 N으로 바꾼다
		JAN

	그러면 9 + 1 + 13 = 23으로 최소가 된다
*/

#include <string>

#define Min(X, Y)	((X < Y) ? X : Y)

using namespace std;

inline int MinMove(char _dst)
{

	/*
	
	위 아래 이동 확인
	*/
	int chk1 = _dst - 'A';
	int chk2 = 1 + 'Z' - _dst;
	return Min(chk1, chk2);
}

inline int MinDis(int _s, int _e, int _len)
{

	/*
	
	시작지점과 끝 지점 중 가까운 곳 확인
	*/
	if (_len <= _s) _s -= _len;
	if (_len <= _e) _e -= _len;

	return Min(Min(_s, _len - _s), Min(_e, _len - _e));
}

int solution(string _name)
{

	/*
	
	그리디
	문자열의 길이를 N
	시간복잡도는 O(N^2)
	*/
	int answer = 1'000'000;

	int len = _name.length();
	
	_name.reserve(len << 1);
	_name += _name;

	for (int s = 0; s < len; s++)
	{

		int move = 0;
		int cnt = 0;

		for (int i = 0; i < len; i++)
		{

			if (_name[s + i] == 'A') continue;

			move = i;
			cnt += MinMove(_name[s + i]);
		}

		cnt += move;
		cnt += MinDis(s, s + move, len);

		answer = Min(answer, cnt);
	}

	return answer;
}