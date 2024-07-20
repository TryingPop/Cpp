/*
날짜 : 2024. 7. 20
이름 : 배성훈
내용 : 주차 요금 계산
	주차장의 요금표와 차량이 들어오고(입차),
	나간(출차) 기로깅 주어졌을 때,
	차량별로 주차 요금을 계산하려고 한다

	어떤 차량이 입차된 후에 출차된 내역이 없다면,
	23:59에 출차된 것으로 간주한다

	00:00 부터 23:59까지의 입출차 내역을 바탕으로
	차량별 누적 주차 시간을 계산하여 요금을 일괄로 정산

	누적 주차시간이 기본 시간 이하라면,
	기본 요금을 청구

	누적 주차시간이 기본 시간을 초과하면,
	기본 요금에 더해서,
	초과한 시간에 대해서 단위 시간마다
	단위 요금을 청구한다

	초과한 시간이 단위 시간으로 나누어 떨어지지 않으면 올림 연산을 한다

	주차 요금을 나타내는 정수 배열 fees,
	자동차의 입/출차 내역을 나타내는 문자열 배열 records가 매개변수로 주어질 때,
	차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수 배열에 담아서
	return 하는 solution 함수 구현

	fees의 길이는 4이고
	fees는 기본 시간(분), 기본 요금, 단위 시간(분), 단위 요금으로 구성되어 있다
	
	records의 길이는 1000이하의 자연수이고
	"시각 차량번호 내역" 형식의 문자열
	시각, 차량번호, 내역은 공백으로 구분되어 있다
	시각은 HH:MM으로 기록된 길이 5인 문자열
	29:77 같이 잘못된 시각은 주어지지 않는다
	차량번호는 '0' ~ '9'로 구성된 길이 4인 문자열
	내역의 입차는 IN, 출차는 OUT으로 표기된다
	같은 시각에 같은 차량번호의 내역이 2번 이상 나타나지 않고,
	마지막 시각 23:59에 입차되는 경우는 없다
	그리고 입차기록이 없는 차는 출차될 수없고
	이미 입차된 차량 번호가 다시 입차하는 경우는 없다
	record의 원소들은 시각을 기준으로 오름차순 정렬되어 있다
	
	parameter
	{ 180, 5000, 10, 600 }, 
	{ "05:34 5961 IN", "06:00 0000 IN", 
	  "06:34 0000 OUT", "07:59 5961 OUT", 
	  "07:59 0148 IN", "18:59 0000 IN", 
	  "19:09 0148 OUT", "22:59 5961 IN", 
	  "23:00 5961 OUT" }

	return
	{ 14600, 34400, 5000 }


	sol
	차량 번호 별로 사용 시간을 보자
	0000의 경우 

	05:34분에 5961 차량이 입차되고
	07:59분에 5961 차량이 출차 한다
*/

#include <string>
#include <vector>
#include <map>

#define mp make_pair
#define pi pair<int, int>
#define pii pair<pi, pi>

#define END 60 * 23 + 59

using namespace std;

inline int GetFee(const vector<int>& _fees, int _time)
{

	/*
	
	주차 요금 계산 함수
	fees : 조건
	time : 사용 시간
	*/

	int ret = _fees[1];
	_time -= _fees[0];

	if (_time <= 0) return ret;

	_time--;
	ret += _fees[3] * (1 + (_time / _fees[2]));

	return ret;
}

inline void ReadString(string& _str, vector<int>& _info)
{

	/*
	
	문자열 읽기
	info는 읽은 정보 반환
	0 : 시간
	1 : 번호
	2 : 타입 -> 1 : IN, 0 : OUT
	*/

	_info.clear();			// 재활용 변수라 초기화
	
	bool isTime = true;
	bool isNum = true;

	int time = 0;
	int num = 0;
	bool isNew;

	for (const char c : _str)
	{

		if (c == ' ')
		{

			if (isTime) 
			{

				time += num;
				num = 0;
				isTime = false;
			}
			else isNum = false;
			continue;
		}

		if (isTime)
		{

			if (c == ':') {

				time = num * 60;
				num = 0;
				continue;
			}

			num = num * 10 + c - '0';
		}
		else if (isNum) num = num * 10 + c - '0';
		else 
		{

			isNew = c == 'I';
			break;
		}
	}

	_info.push_back(time);
	_info.push_back(num);
	_info.push_back(isNew ? 1 : 0);
}

inline void ReadInfo(map<int, pii>& _cars, vector<int>& _info)
{

	/*
	
	읽은 주차 정보를
	차량 정보에 기록하고 전체 주차 시간 계산
	*/

	if (_info[2])
	{

		if (_cars.count(_info[1]))
		{

			_cars[_info[1]].second.first = _info[0];
			_cars[_info[1]].first.second = 1;
		}
		else _cars[_info[1]] = mp(mp(0, 1), mp(_info[0], -1));

		return;
	}

	_cars[_info[1]].first.second = 0;
	_cars[_info[1]].first.first += _info[0] - _cars[_info[1]].second.first;
}


vector<int> solution(vector<int> _fees, vector<string> _records)
{

	vector<int> answer;

	// 입차 기록 정보 읽어 정수로 변화할 때 사용할 변수
	// 0 : 시작 or 종료 시간, 1 : 차량 번호, 2 : 입출차 타입
	vector<int> info;
	info.reserve(3);

	// 차량 정보
	// first.first: 주차시간
	// first.second: 입차 했으나 출차 기록이 안됨을 의미
	// second.first: 주차 시작 시간
	// second.second: 사용 X
	map<int, pii> cars;

	for (string& rec : _records)
	{

		// 기록을 읽어 info에 저장
		ReadString(rec, info);

		// 읽은 info로 차량 정보에 저장
		ReadInfo(cars, info);
	}

	for (const auto& car : cars)
	{

		int useTime;
		
		if (car.second.first.second)	// 마지막에 출차 했는지?
			// 마지막에 출차 X라 조건대로 끝 시간에 맞춰 출차 시킨 가격 추가
			useTime = car.second.first.first + (END - car.second.second.first);
		else
			// 마지막에 출차되어 기록된 가격 출력
			useTime = car.second.first.first;

		// map은 key로 오름차순 정렬된 상태로 저장하는 자료구조라
		// 그대로 넣으면 된다
		answer.push_back(GetFee(_fees, useTime));
	}

	return answer;
}