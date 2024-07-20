/*
��¥ : 2024. 7. 20
�̸� : �輺��
���� : ���� ��� ���
	�������� ���ǥ�� ������ ������(����),
	����(����) ��α� �־����� ��,
	�������� ���� ����� ����Ϸ��� �Ѵ�

	� ������ ������ �Ŀ� ������ ������ ���ٸ�,
	23:59�� ������ ������ �����Ѵ�

	00:00 ���� 23:59������ ������ ������ ��������
	������ ���� ���� �ð��� ����Ͽ� ����� �ϰ��� ����

	���� �����ð��� �⺻ �ð� ���϶��,
	�⺻ ����� û��

	���� �����ð��� �⺻ �ð��� �ʰ��ϸ�,
	�⺻ ��ݿ� ���ؼ�,
	�ʰ��� �ð��� ���ؼ� ���� �ð�����
	���� ����� û���Ѵ�

	�ʰ��� �ð��� ���� �ð����� ������ �������� ������ �ø� ������ �Ѵ�

	���� ����� ��Ÿ���� ���� �迭 fees,
	�ڵ����� ��/���� ������ ��Ÿ���� ���ڿ� �迭 records�� �Ű������� �־��� ��,
	���� ��ȣ�� ���� �ڵ������� û���� ���� ����� ���ʴ�� ���� �迭�� ��Ƽ�
	return �ϴ� solution �Լ� ����

	fees�� ���̴� 4�̰�
	fees�� �⺻ �ð�(��), �⺻ ���, ���� �ð�(��), ���� ������� �����Ǿ� �ִ�
	
	records�� ���̴� 1000������ �ڿ����̰�
	"�ð� ������ȣ ����" ������ ���ڿ�
	�ð�, ������ȣ, ������ �������� ���еǾ� �ִ�
	�ð��� HH:MM���� ��ϵ� ���� 5�� ���ڿ�
	29:77 ���� �߸��� �ð��� �־����� �ʴ´�
	������ȣ�� '0' ~ '9'�� ������ ���� 4�� ���ڿ�
	������ ������ IN, ������ OUT���� ǥ��ȴ�
	���� �ð��� ���� ������ȣ�� ������ 2�� �̻� ��Ÿ���� �ʰ�,
	������ �ð� 23:59�� �����Ǵ� ���� ����
	�׸��� ��������� ���� ���� ������ ������
	�̹� ������ ���� ��ȣ�� �ٽ� �����ϴ� ���� ����
	record�� ���ҵ��� �ð��� �������� �������� ���ĵǾ� �ִ�
	
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
	���� ��ȣ ���� ��� �ð��� ����
	0000�� ��� 

	05:34�п� 5961 ������ �����ǰ�
	07:59�п� 5961 ������ ���� �Ѵ�
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
	
	���� ��� ��� �Լ�
	fees : ����
	time : ��� �ð�
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
	
	���ڿ� �б�
	info�� ���� ���� ��ȯ
	0 : �ð�
	1 : ��ȣ
	2 : Ÿ�� -> 1 : IN, 0 : OUT
	*/

	_info.clear();			// ��Ȱ�� ������ �ʱ�ȭ
	
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
	
	���� ���� ������
	���� ������ ����ϰ� ��ü ���� �ð� ���
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

	// ���� ��� ���� �о� ������ ��ȭ�� �� ����� ����
	// 0 : ���� or ���� �ð�, 1 : ���� ��ȣ, 2 : ������ Ÿ��
	vector<int> info;
	info.reserve(3);

	// ���� ����
	// first.first: �����ð�
	// first.second: ���� ������ ���� ����� �ȵ��� �ǹ�
	// second.first: ���� ���� �ð�
	// second.second: ��� X
	map<int, pii> cars;

	for (string& rec : _records)
	{

		// ����� �о� info�� ����
		ReadString(rec, info);

		// ���� info�� ���� ������ ����
		ReadInfo(cars, info);
	}

	for (const auto& car : cars)
	{

		int useTime;
		
		if (car.second.first.second)	// �������� ���� �ߴ���?
			// �������� ���� X�� ���Ǵ�� �� �ð��� ���� ���� ��Ų ���� �߰�
			useTime = car.second.first.first + (END - car.second.second.first);
		else
			// �������� �����Ǿ� ��ϵ� ���� ���
			useTime = car.second.first.first;

		// map�� key�� �������� ���ĵ� ���·� �����ϴ� �ڷᱸ����
		// �״�� ������ �ȴ�
		answer.push_back(GetFee(_fees, useTime));
	}

	return answer;
}