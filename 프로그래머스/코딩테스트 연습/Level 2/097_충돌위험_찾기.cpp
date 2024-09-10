/*
��¥ : 2024. 9. 10
�̸� : �輺��
���� : �浹���� ã��
	� ���� ���ʹ� �κ��� �̿��� �ڵ� ��� �ý����� ��Ѵ�
	��� �ý����� �۵��ϴ� ��Ģ�� ������ ����

	1. ���� ���Ϳ��� r,c�� ���� 2���� ��ǥ�� 
	��Ÿ�� �� �ִ� n���� ����Ʈ�� �����Ѵ�
	�� ����Ʈ�� 1 ~ n���� ���� �ٸ� ��ȣ�� ���´�

	2. �κ����� ������ ��� ��ΰ� �����Ѵ�
	��� ��δ� m���� ����Ʈ�� �����ǰ�
	�κ��� ù ����Ʈ���� ������ �Ҵ�� ����Ʈ�� ������� �湮�Ѵ�

	3. ��� �ý��ۿ� ���Ǵ� �κ��� x ���̰�,
	��� �κ��� 0�ʿ� ���ÿ� ����Ѵ�
	�κ��� 1�ʸ��� r��ǥ�� c��ǥ �� �ϳ��� 1��ŭ �����ϰų�
	������ ��ǥ�� �̵��� �� �ִ�

	4. ���� ����Ʈ�� �̵��� ���� �׻� �ִ� ��η� �̵��ϸ�
	�ִ� ��ΰ� ���� ������ ���, r��ǥ�� ���ϴ� �̵���
	c��ǥ�� ���ϴ� �̵����� ���� �Ѵ�

	5. ������ ����Ʈ�� ������ �κ��� ����� ��ġ�� ���� ���͸� �����
	�κ��� ���� ���͸� ����� ��δ� ������� �ʴ´�

	�̵� �� ���� ��ǥ�� �κ��� 2�� �̻� ���δٸ� �浹�� ���ɼ��� �ִ�
	���� ��Ȳ���� �Ǵ��Ѵ�

	�������� ����� ���� ������� �κ��� ������ �� ������ ��Ȳ�� 
	�� �� �� �Ͼ���� �˰� �ʹ�
	���� � �ð��� ���� ��ǥ���� ���� ��Ȳ�� �߻��Ѵٸ� 
	�� Ƚ���� ��� ���Ѵ�

	��� ����Ʈ n���� ��ǥ�� ���� 2���� ���� �迭 points�� 
	�κ� x���� � ��θ� ���� 2���� ���� �迭 routes�� �Ű������� �־��� ��,
	��� �κ��� ����� ��ĥ ������ �߻��ϴ� ������ ��Ȳ�� Ƚ����
	return �ϴ� solution �Լ� ����

	points�� ���̴� 100 ���� 2 �̻��� �ڿ���

	points[i]�� i + 1 �� ����Ʈ�� { r��ǥ, c��ǥ }�� ��Ÿ����
	���̰� 2�� ���� �迭�̴�
	r, c �� 100 ������ �ڿ���
	���� ��ǥ�� ���� ����Ʈ�� �����ϴ� �Է��� ����

	routes�� ���̴� �κ��� ���� ���� 100 ���� 2 �̻��� �ڿ����̴�
	routes[i]�� ���̵� 100 ���� 2 �̻��� �ڿ����̰�,
	i + 1 ��° �κ��� ��۰�θ� ��Ÿ����
	routes[i]�� ��� ����

	routes[i][j]�� n���� �۰�
	���� ����Ʈ�� �������� �湮�ϴ� �Է��� �־����� �ʴ´�

	
	parameter
	{ { 3, 2 }, { 6, 4 }, { 4, 7 }, { 1, 4 } },
	{ { 4, 2 }, { 1, 3 }, { 2, 4 } }


	return
	1


	sol
	3�� �� { 4, 4 }�� ��ǥ���� 1, 2�� �浹�� 1�� �Ͼ��
	�ܴ̿� �浹�� �Ͼ�� �ʴ´�
*/

#include <vector>

using namespace std;

inline void Move(vector<int>& _pos, vector<int>& _goal)
{

	/*
	
	�̵�
	pos�� goal�� �ٸ� ��츸 �;��Ѵ�
	*/
	if (_pos[0] < _goal[0]) _pos[0]++;
	else if (_pos[0] > _goal[0]) _pos[0]--;
	else if (_pos[1] < _goal[1]) _pos[1]++;
	else _pos[1]--;
}

inline bool IsGoal(vector<int>& _pos, vector<int>& _goal)
{

	/*
	
	������ ���� Ȯ��
	*/
	return _pos[0] == _goal[0] && _pos[1] == _goal[1];
}

inline int CntCollision(vector<vector<int>>& _robot, vector<vector<int>>& _map)
{

	/*
	
	�浹 ���� Ȯ��
	*/

	int ret = 0;
	for (int i = 0; i < _robot.size(); i++)
	{

		if (_map[_robot[i][0]][_robot[i][1]] > 1) ret++;
		_map[_robot[i][0]][_robot[i][1]] = 0;
	}

	return ret;
}

inline int Simulation(vector<vector<int>>& _points, vector<vector<int>>& _routes)
{

	/*
	
	�ùķ��̼�
	*/

	// �ʱ� ����
	int ret = 0;

	vector<vector<int>> map(101, vector<int>(101, 0));
	vector<int> idxs(_routes.size(), 1);

	vector<vector<int>> robot;
	robot.reserve(_routes.size());

	for (int i = 0; i < _routes.size(); i++)
	{

		robot.push_back(_points[_routes[i][0] - 1]);
		map[robot[i][0]][robot[i][1]]++;
	}

	ret += CntCollision(robot, map);
	
	// �ùķ��̼�
	while (true)
	{

		bool flag = true;
		for (int i = 0; i < robot.size(); i++)
		{

			int& idx = idxs[i];
			if (idx == 0) continue;

			if (IsGoal(robot[i], _points[_routes[i][idx] - 1])) 
			{

				idx++;
				if (idx == _routes[i].size())
				{

					idx = 0;
					continue;
				}
			}

			flag = false;
			Move(robot[i], _points[_routes[i][idx] - 1]);
			map[robot[i][0]][robot[i][1]]++;
		}

		if (flag) break;

		ret += CntCollision(robot, map);
	}

	return ret;
}

int solution(vector<vector<int>> _points, vector<vector<int>> _routes)
{

	/*

	�ùķ��̼�
	�κ��� ���� A(100), ���� �ִ� �ý� �Ÿ� B(200), routes�� ���� C(100)
	�ð� ���⵵ O(A x B x C)
	*/
	int answer = Simulation(_points, _routes);
	return answer;
}