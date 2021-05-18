#ifndef TASK3_H
#define TASK3_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "GetRandNum.h"

using namespace std;

// Пространство имён для практических задач
namespace tasks {
	// Объявления функций
	void Task3Problem1Wrapper();
	unsigned int Task3Problem1(vector<unsigned int> arr);
	bool comp(unsigned int a, unsigned int b);
	void Task3Problem2Wrapper();
	string Task3Problem2(vector<int> arr);
	bool compString(string str1, string str2);
	void Task3Problem3Wrapper();

	// Компаратор чисел для сортировки по убыванию
	bool comp(unsigned int a, unsigned int b) {
		return a > b;
	}

	// Функция для первой задачи
	unsigned int Task3Problem1(vector<unsigned int> arr) {
		// Сортируем вектор по убыванию
		sort(arr.begin(), arr.end(), comp);
		unsigned int perim = 0;

		// Через цикл пропускаем отсортированный массив и проверяем, образует ли он треугольник или нет.
		size_t bound = arr.size() - 2;
		for (size_t i = 0; i <bound; i++) {
			if (arr[i] < arr[i + 1] + arr[i + 2]) {
				perim = max(perim, arr[i] + arr[i + 1] + arr[i + 2]);
				break;
			}
		}
		return perim;
	}

	// Функция обёртка для первой задачи
	void Task3Problem1Wrapper() {
		// Ввод количества элементов массива и его вывод в консоль
		unsigned int num = 0;
		cout << "Введите количество элементов во входном массиве: ";
		cin >> num;
		cout << "Сгенерированный массив имеет следующий вид:\n";
		vector<unsigned int> input;
		for (size_t i = 0; i < num; i++) {
			unsigned int element = (unsigned int)getRandNum(1, 1000);
			cout << element << " ";
			input.push_back(element);
		}

		// Вызов функции и вывод результатов
		cout << "\nМаксимальный периметр треугольника из введённого массива: " << Task3Problem1(input) << ".\n\n";
	}

	// Компаратор для строк по убыванию
	bool compString(string str1, string str2) {
		// Выбираем минимальную длину
		size_t min_length;
		if (str1.length() < str2.length()) min_length = str1.length();
		else min_length = str2.length();

		// Посимвольно проходим по строкам
		for (size_t i = 0; i < min_length; i++) {
			if (str1[i] > str2[i]) return true;
			else if (str1[i] < str2[i]) return false;
			else continue;
		}

		// Если на некотором этапе строки были одинаковыми, то сравниваем по длине
		if (str1.length() > str2.length()) return true;
		else return false;
	}

	// Функция для второй задачи
	string Task3Problem2(vector<int> arr) {
		// Создаём вектор строк из вектора чисел
		vector<string> StringList;
		for (size_t i = 0; i < arr.size(); i++) {
			StringList.push_back(to_string(arr[i]));
		}

		// Сортируем, соединяем и возвращаем результат
		sort(StringList.begin(), StringList.end(), compString);
		string result = "";
		for (size_t i = 0; i < StringList.size(); i++) result += StringList[i];
		return result;
	}

	// Функция обёртка для второй задачи
	void Task3Problem2Wrapper() {
		// Ввод количества элементов массива и его вывод в консоль
		unsigned int num = 0;
		cout << "Введите количество элементов во входном массиве: ";
		cin >> num;
		cout << "Сгенерированный массив имеет следующий вид:\n";
		vector<int> input;
		for (size_t i = 0; i < num; i++) {
			int element = getRandNum(1, 1000);
			cout << element << " ";
			input.push_back(element);
		}

		// Вызов функции и вывод результатов
		cout << "\nМаксимальное число: " << Task3Problem2(input) << ".\n\n";
	}

	// Функция обёртка для третьей задачи
	void Task3Problem3Wrapper() {
		// Ввод количества элементов матрицы, вывод в консоль
		unsigned int rows = 0, cols = 0;
		cout << "Введите количество строк и столбцов в матрице: ";
		cin >> rows >> cols;
		cout << "Сгенерированная матрица имеет следующий вид:\n";
		vector<vector<int>> input(rows);
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				int element = getRandNum(1, 1000);
				cout << element << " ";
				input[i].push_back(element);
			}
			cout << "\n";
		}

		// Сортировка
		int c = 10;
		while (c != 0) {
			c = 0;
			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					if (i < rows - 1 && j < cols - 1) {
						if (input[i][j] > input[i + 1][j + 1]) {
							c = c + 1;
							int temp = input[i][j];
							input[i][j] = input[i + 1][j + 1];
							input[i + 1][j + 1] = temp;
						}
					}
				}
			}
		}

		// Вывод результата
		cout << "Отсоротированная матрица:\n";
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				cout << input[i][j] << " ";
			}
			cout << "\n";
		}
		cout << endl;
	}

}

#endif TASK3_H
