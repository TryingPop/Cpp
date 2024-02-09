// #include <iostream>
#include <string>
#include <vector>

/*
날짜 : 2024. 2. 9
이름 : 배성훈
내용 : 두 수의 연산값 비교하기
	새로운 + 연산 정의
	12 + 3 = 123
	3 + 12 = 312

	a, b는 1만 이하의 자연수
	a, b가 주어졌을 때, a + b와 2 * a * b중 큰 값을 return하는 solution 함수 완성하기


*/

using namespace std;

int solution(int _a, int _b)
{

	int answer = 0;

	string A = to_string(_a);
	string B = to_string(_b);

	string calc;
	calc.reserve(A.size() + B.size());
	calc.append(A).append(B);

	answer = max(stoi(calc), 2 * _a * _b);

	// 해제 해줘야하지 않을까 의문을 갖는다
	// 그런데 쓰면 프로그래머스에서도 틀리고, 여기서도 에러 뜬다
	// https://stackoverflow.com/questions/3130490/deleting-string-object-in-c
	// 
	// 스택 오버플로우에서 답변을 보니
	// 문자열은 벗어나면 해당 소멸자가 자동으로 호출되고 메모리가 해제된다고 한다
	// 함수에서 반환할 때, string 클래스의 소멸자가 작동하는거 같다
	// delete &A, &B, &calc;
	return answer;
}


/*
int main(void)
{

	int a, b;
	int result;

	cin >> a >> b;
	result = solution(a, b);
	cout << result;
}
*/