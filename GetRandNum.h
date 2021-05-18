#ifndef GETRANDNUM_H
#define GETRANDNUM_H

#include <random>

// ������� ��������� ���������� ����� � �������� ���������
int getRandNum(int start, int end) {
	std::random_device random_device; // �������� ��������.
	// ��������� ��������� �����. (����� ������� ���� ���������������� ��������, ����� ����� ������)
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(start, end); // ����������� ������������� [start, end]
	int x = distribution(generator); // ��������� �����
	return x;
}

#endif GETRANDNUM_H
