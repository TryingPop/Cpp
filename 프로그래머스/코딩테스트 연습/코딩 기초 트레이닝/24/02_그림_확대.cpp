#include <vector>
#include <string>

/*
날짜 : 2024. 3. 1
이름 : 배성훈
내용 : 그림 확대
	그림파일은 1 x 1 크기의 정사각형 크기의 
	픽셀로 이루어져 있다

	그림파일을 나타낸 문자열 배열 picture과 
	정수 k가 매개변수로 주어질 때,

	이 그림파일을 가로 세로로 k배 늘린 그림파일을
	나타내도록 문자열 배열을 
	return 하는 solution 함수를 구현
*/

using namespace std;

vector<string> solution(vector<string> _picture, int _k)
{

	vector<string> answer;
	answer.reserve(_picture.size() * _k);

	string temp;
	temp.reserve(20 * _k);

	for (const string str : _picture)
	{

		for (const char c : str)
		{

			for (int i = 0; i < _k; i++) 
			{

				temp.push_back(c);
			}
		}

		for (int i = 0; i < _k; i++)
		{

			answer.push_back(temp);
		}

		temp.clear();
	}
	return answer;
}