#include <iostream>
#include "Tasks\Tasks.h"
#include "Lab3\Lab3.h"
#include "Lab4\Lab4.h"

using namespace std;

// ����� ����� ���������
int main() {
	setlocale(LC_ALL, "Russian");
	int LabNum = 10;
	// ����� ������������ ������
	while (LabNum != 0) {
		cout << "������� ����� ������������ ������ (3 ��� 4, 5 - ������������ ������, 0 - �����): ";
		cin >> LabNum;
		if (LabNum == 3) lab3::Lab3Start();
		else if (LabNum == 4) lab4::Lab4Start();
		else if (LabNum == 5) tasks::chooseTask();
		else if (LabNum == 0) break;
		else cout << "������ ������������ �����. ���������� ��� ���!\n";
	}
	system("pause");
	return 0;
}