/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : Ŭ���� ���ø�
	�տ��� ������ ���ø� Ŭ������ ����

	������� : Point Ŭ������ ����
*/

#ifndef __POINT_TEMPLATE_H__
#define __POINT_TEMPLATE_H__

template <typename T>
class Point {

private:
	T xpos, ypos;

public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

#endif