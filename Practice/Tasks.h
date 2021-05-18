#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
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
			cout << "Сделано на Python.\n";
			break;
		case 2:
			cout << "Задачи на дом от 27 февраля.\n";
			Task2Problem1Wrapper();
			Task2Problem2Wrapper();
			Task2Problem3Wrapper();
			break;
		case 3:
			cout << "Контрольные задачи по дисциплине СиАОД №1.\n";
			Task3Problem1Wrapper();
			Task3Problem2Wrapper();
			Task3Problem3Wrapper();
			break;
		case 4:
			cout << "Задача на интервалы.\n";
			Task4Problem1Wrapper();
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
