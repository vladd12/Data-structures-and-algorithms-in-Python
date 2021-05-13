#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include "Lab4Tasks.h"

using namespace std;

// Пространство имён 4 лабораторной работы
namespace lab4 {

	// Функция для выбора задания из лабораторной работы
	void Lab4Start() {
		int taskNum = 0;
		cout << "Выберите задание (от 1 до 11, любое другое значение - выход): ";
		cin >> taskNum;
		switch (taskNum) {
		case 9:
			cout << "Задача №9.\n";
			Task09();
			break;
		case 10:
			cout << "Задача №10.\n";
			Task10();
			break;
		case 11:
			cout << "Задача №11.\n";
			Task11();
			break;
		default:
			break;
		}
	}

}

#endif LAB4_H