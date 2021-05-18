#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <string>
#include "Lab3Strings.h"

using namespace std;

// Пространство имён 3 лабораторной работы
namespace lab3 {
	// Главная функция для лабораторной работы
	void Lab3Start() {
		// Сначала выполняется поиск строк разными методами
		cout << "Алгоритм КМП.\n";
		KMP_Wrapper();
		cout << "\nАлгоритм БМ.\n";
		BM_Wrapper();
		cout << endl;
	}

}

#endif LAB3_H
