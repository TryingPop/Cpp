#include <vector>
#include <string>

/*
날짜 : 2024. 2. 20
이름 : 배성훈
내용 : 할 일 목록
	오늘 해야 할 일이 담긴 문자열 배열 todo_list와
	각각의 일을 지금 마쳤는지를 나타내는 bool 배열 finished가 매개변수로 주어질 때,
	todo_list에서 아직 마치지 못한 일들을 순서대로 담은 문자열 배열을
	return 하는 solution 함수 구현
*/
using namespace std;

vector<string> solution(vector<string> _todo_list, vector<bool> _finished) 
{

	vector<string> answer;

	for (int i = 0; i < _todo_list.size(); i++)
	{

		if (!_finished[i]) answer.push_back(_todo_list[i]);
	}
	return answer;
}