#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include "Task5.h"

using namespace std;

// Пространство имён для практических задач
namespace tasks {
	// Функция для выбора задания из практических работ
	void chooseTask() {
		int taskNum = 0;
		cout << "Выберите практическое задание (от 1 до 5, любое другое значение - выход): ";
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
			cout << "Задачи на строки.\n";
			Task5Problem1Wrapper();
			Task5Problem2Wrapper();
			Task5Problem3Wrapper();
			break;
		default:
			cout << "Некорректное значение, выход из программы.\n";
			break;
		}
	}

}

#endif TASKS_H
