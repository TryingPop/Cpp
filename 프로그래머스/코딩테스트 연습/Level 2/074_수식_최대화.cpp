/*
��¥ : 2024. 8. 18
�̸� : �輺��
���� : ���� �ִ�ȭ
	���ڵ�� 3 ������ ���깮�� +, -, * �� �־�����
	�������� �켱������ �����Ӱ� �������Ͽ� ���� ū ���ڸ� ã�ƾ��Ѵ�

	�� �������� �켱������ ���� ������ ��,
	���� �켱������ �����ڴ� ����� �Ѵ�

	+ > - > * �Ǵ� - > * > + ��� ���� �������� �켱������ ������ �� ������
	+,* > - �Ǵ� * > +-�� ���� 2�� �̻��� �����ڰ� ������ ������ ��������
	�������� �켱������ ������ �� ����

	���� ���� ����� ������� �ش� ������ �������� ��ȯ�Ͽ� �����ϸ�
	������ ���ڰ� ���� ū �����ڸ� ����ڷ� �����ϸ�,
	����ڰ� ������ ���ڸ� ��»������ �����Ѵ�

	�����ڿ��� �־��� ���� ������ ��� ���ڿ� expression��
	�Ű������� �־��� ��,

	��� �� ���� �� �ִ� ���� ū ��� �ݾ��� 
	return �ϴ� solution �Լ� ����

	expression�� 3�̻� 100������ ����
	
	expression�� ���鹮��, ��ȣ���� ���� ������ ���ڿ� 
	3���� ������(+, -, *)�θ� �̷���� �ùٸ� ���� ǥ������� ǥ���� �����

	expression�� �ǿ����ڴ� 0�̻� 999 ������ ����

	expression�� ��� 1�� �̻��� �����ڸ� ����

	������ �켱������ ��� �����ϴ���,
	expression�� �߰� ��갪�� ���� �ᱣ���� ������
	2^63 - 1���ϰ� �ǵ��� �Է��� �־�����

	���� �����ڳ����� �տ� �ִ� ���� �켱������ �� ����


	parameter
	"100-200*300-500+20"


	return
	60420


	sol
	* > + > -�� �켱������ �ϴ� ���
	100 - 200 * 300 - 500 + 20
	= 100 - 60000 - 500 + 20
	= 100 - 60000 - 520
	= -60420
	�̰� 60420�̴�

	+ > - > *�� �켱������ �ϴ� ���
	100 - 200 * 300 - 500 + 20
	= 100 - 200 * 300 - 520
	= -100 * -220
	= 22000
	�̰� 22000�̴�

	�̷��� �ٸ� ��쵵 ã�ƺ��� 60420�� �ִ밪���� �� �� �ִ�
*/

#include <string>
#include <vector>

#define ll long long
#define Abs(X)	(((X) < 0) ? -(X) : (X))

using namespace std;

inline void ReadString(string& _expression, vector<ll>& _nums, vector<ll>& _ops)
{

	/*
	
	���ڿ� �����ڸ� ����
	*/

	int num = 0;
	for (const char c : _expression)
	{

		if (c == '*' || c == '+' || c == '-')
		{

			_nums.push_back(num);
			num = 0;
			_ops.push_back(c);
		}
		else num = num * 10 + c - '0';
	}

	_nums.push_back(num);
}

void Op(vector<ll>& _nums, vector<ll>& _ops,
	char _op, vector<ll>& _rnums, vector<ll>& _rops)
{

	/*
	
	�ش� ���� ����
	���� ���ڴ� rnums, ���� ������ rops�� ����
	*/

	_rnums.push_back(_nums[0]);
	for (int i = 0; i < _ops.size(); i++)
	{

		if (_ops[i] == _op)
		{

			// �����ؾ� �ϴ� ���길 �����Ѵ�
			int idx = _rnums.size() - 1;

			if (_op == '*') _rnums[idx] *= _nums[i + 1];
			else if (_op == '+') _rnums[idx] += _nums[i + 1];
			else _rnums[idx] -= _nums[i + 1];
		}
		else 
		{

			// �����ؾ� �� ������ �ƴϹǷ� ���� ���� ����θ� �ѱ��
			_rnums.push_back(_nums[i + 1]);
			_rops.push_back(_ops[i]);
		}
	}
}

ll DFS(vector<ll>& _nums, vector<ll>& _ops, int _state = 0b111)
{

	/*
	
	������ �ϳ��� �����ϸ鼭 �ִ밪�� ã�´�
	*/

	if (!_state) return _nums[0];

	ll ret = 0;

	// ���� ���ڿ� ������
	vector<ll> rnums, rops;

	if (_state & (1 << 0))
	{

		// ���� ���� ����
		Op(_nums, _ops, '*', rnums, rops);
		ll chk = DFS(rnums, rops, _state ^ (1 << 0));
		chk = Abs(chk);
		ret = ret < chk ? chk : ret;
	}

	if (_state & (1 << 1))
	{

		// ���� ���� ����
		rnums.clear();
		rops.clear();
		Op(_nums, _ops, '+', rnums, rops);
		ll chk = DFS(rnums, rops, _state ^ (1 << 1));
		chk = Abs(chk);
		ret = ret < chk ? chk : ret;
	}

	if (_state & (1 << 2))
	{

		// ���� ���� ����
		rnums.clear();
		rops.clear();

		Op(_nums, _ops, '-', rnums, rops);
		ll chk = DFS(rnums, rops, _state ^ (1 << 2));
		chk = Abs(chk);
		ret = ret < chk ? chk : ret;
	}

	return ret;
}

ll solution(string _expression)
{

	vector<ll> nums, ops;
	ReadString(_expression, nums, ops);
	ll answer = DFS(nums, ops);
	return answer;
}