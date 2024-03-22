#include <string>
#include <sstream>

/*
날짜 : 2024. 3. 22
이름 : 배성훈
내용 : 다항식 더하기
	한 개 이상의 항의 합으로 이루어진
	식을 다항식이라 한다

	다항식을 계산할 때는 동류항끼리
	계산하여 정리한다

	덧셈으로 이루어진 다항식 polynomial이
	매개변수로 주어질 때,

	동류항끼리 더한 결괏값을 return하는
	solution 함수 구현

	같은 식이라면 가장 짧은 수식을 return 해야한다

	polynomial의 수는 0 초과 100 미만이다
	polynomial의 일차 항과 상수로만 이루어져 있다
	polynomial은 양의 정수, 공백, x, +로 이루어져 있다
	항과 연산기호 사이에는 항상 공백이 존재
	공백은 연속되지 않고 끝과 처음에 공백은 없다
	변수가 숫자 앞에 오는 경우는 없다
	잘못된 입력이 주어지는 경우는 없다
	0으로 시작되는 경우도 없다
	계수 1은 생략 가능하다
*/

using namespace std;

string solution(string _polynomial)
{

	string answer = "";

	int a = 0;
	int b = 0;

	stringstream ss(_polynomial);

	string temp;
	temp.reserve(10);

	while (ss >> temp)
	{

		if (temp == "+") continue;
		else if (temp == "x") a++;
		else if (temp.back() == 'x')
		{

			temp.pop_back();
			a += stoi(temp);
		}
		else b += stoi(temp);
	}

	answer.reserve(20);

	if (a != 0) 
	{

		if (a != 1) answer.append(to_string(a));
		
		if (b != 0) answer.append("x + ");
		else answer.push_back('x');
	}

	if (b != 0) answer.append(to_string(b));

	if (answer.empty()) answer.push_back('0');
	return answer;
}