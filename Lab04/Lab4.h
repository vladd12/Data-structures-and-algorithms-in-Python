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
		case 1:
			cout << "Задача №1.\n";
			Task01("Lab4/Task01.txt");
			break;
		case 2:
			cout << "Задача №2.\n";
			Task02();
			break;
		case 3:
			cout << "Задача №3.\n";
			Task03();
			break;
		case 4:
			cout << "Задача №4.\n";
			Task04();
			break;
		case 5:
			cout << "Задача №5.\n";
			Task05();
			break;
		case 6:
			cout << "Задача №6.\n";
			Task06();
			break;
		case 7:
			cout << "Задача №7.\n";
			Task07();
			break;
		case 8:
			cout << "Задача №8.\n";
			Task08();
			break;
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
