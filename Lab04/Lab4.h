#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include "Lab4Tasks.h"

using namespace std;

// ������������ ��� 4 ������������ ������
namespace lab4 {

	// ������� ��� ������ ������� �� ������������ ������
	void Lab4Start() {
		int taskNum = 0;
		cout << "�������� ������� (�� 1 �� 11, ����� ������ �������� - �����): ";
		cin >> taskNum;
		switch (taskNum) {
		case 9:
			cout << "������ �9.\n";
			Task09();
			break;
		case 10:
			cout << "������ �10.\n";
			Task10();
			break;
		case 11:
			cout << "������ �11.\n";
			Task11();
			break;
		default:
			break;
		}
	}

}

#endif LAB4_H