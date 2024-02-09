#include <string>
#include <vector>

/*
날짜 : 2024. 2. 9
이름 : 배성훈
내용 : 문자열 섞기
	길이가 같은 두 개의 문자열을 하나씩 출력하는 메서드 만들어야한다
	
	aaaaa bbbbb
	ababababab


	벡터에는 프로퍼티로 ptr, size, capacity등이 존재
	push_back은 O(1) << 뒤에 넣기만 해서
	push_front는 O(n) << 앞에 넣고 1칸씩 이동하는 연산

	먼저 사이즈를 할당하고 뒤에 연산한다

	https://bconfiden2.tistory.com/4

	string 클래스에는 null 문자가 없다
	자체적으로 length를 갖고 있기 때문이다
*/
using namespace std;

string solution(string str1, string str2)
{

	string answer = "";
	// 사이즈 확인
	// answer.capacity();
	// 미리 크기 할당
	// 그런데 reserve안에 * 2를 하면 8바이트 캐스팅한다고 vs에서 알린다;
	answer.reserve(str1.size() + str2.size());

	// str1.length(); 로해도 된다
	for (int i = 0; i < str1.size(); i++) 
	{


		// answer += str1[i];
		answer.push_back(str1[i]);
		// answer += str2[i];
		answer.push_back(str2[i]);
	}
	return answer;
}