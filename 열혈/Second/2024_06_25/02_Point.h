/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : Point Ŭ����
	���� p153 ~ 154

	01�� point Ŭ������ �����ߴ�
	������� x�� y�� private�� �����ؼ� ���Ƿ� ���� ����Ǵ� ���� ���Ҵ�
	x�� y�� ������ ��Ȳ�̴�

	��ſ� ���� ���� �� ������ ���� �Լ��� �߰��� �����ߴ�
	�� �Լ� ������ ��������� ����Ǵ� ���� ������ �� �ִ�
*/

#ifndef __POINT_H__
#define __POINT_H__

class Point
{

private:
	int x;
	int y;

public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};
#endif