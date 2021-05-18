#include <iostream>
#include "Tasks\Tasks.h"
#include "Lab3\Lab3.h"
#include "Lab4\Lab4.h"

using namespace std;

// Точка входа программы
int main() {
	setlocale(LC_ALL, "Russian");
	int LabNum = 10;
	// Выбор лабораторной работы
	while (LabNum != 0) {
		cout << "Введите номер лабораторной работы (3 или 4, 5 - практические задачи, 0 - выход): ";
		cin >> LabNum;
		if (LabNum == 3) lab3::Lab3Start();
		else if (LabNum == 4) lab4::Lab4Start();
		else if (LabNum == 5) tasks::chooseTask();
		else if (LabNum == 0) break;
		else cout << "Выбран неправильный номер. Попробуйте ещё раз!\n";
	}
	system("pause");
	return 0;
}