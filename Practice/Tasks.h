#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include "Task5.h"

using namespace std;

// ������������ ��� ��� ������������ �����
namespace tasks {
	// ������� ��� ������ ������� �� ������������ �����
	void chooseTask() {
		int taskNum = 0;
		cout << "�������� ������������ ������� (�� 1 �� 5, ����� ������ �������� - �����): ";
		cin >> taskNum;
		switch (taskNum) {
		case 1:
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			break;
		case 5:
			cout << "������ �� ������.\n";
			Task5Problem1Wrapper();
			Task5Problem2Wrapper();
			Task5Problem3Wrapper();
			break;
		default:
			cout << "������������ ��������, ����� �� ���������.\n";
			break;
		}
	}

}

#endif TASKS_H
