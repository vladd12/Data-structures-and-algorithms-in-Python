#ifndef TASK5_H
#define TASK5_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// Пространство имён для практических задач
namespace tasks {
	// Объявления функций
	void Task5Problem1Wrapper();
	bool Task5Problem1(string str1, string str2);
	void stringSort(char* str, int first, int last);
	void Task5Problem2Wrapper();
	string Task5Problem2(string str);
	bool isPalindrom(string str);
	void Task5Problem3Wrapper();
	int Task5Problem3(string text);

	// Быстрая сортировка строки по алфавиту
	void stringSort(char* str, int first, int last) {
		if (first < last) {
			int left = first, right = last, middle = (int)str[(left + right) / 2];
			do {
				while (str[left] < middle) left++;
				while (str[right] > middle) right--;
				if (left <= right) {
					int tmp = str[left];
					str[left] = str[right];
					str[right] = tmp;
					left++;
					right--;
				}
			} while (left <= right);
			stringSort(str, first, right);
			stringSort(str, left, last);
		}
	}

	// Функция для первой задачи о строках (основные действия)
	bool Task5Problem1(string str1, string str2) {
		// Начальная проверка
		if (str1.length() != str2.length()) {
			cout << "Строки имеют разную длину!\n";
			return false;
		}

		// Копирование строк в указатели char и их сортировка
		size_t size = str1.length();
		char* sorted1 = new char[size];
		char* sorted2 = new char[size];
		memcpy(sorted1, str1.data(), size * sizeof(char));
		memcpy(sorted2, str2.data(), size * sizeof(char));
		stringSort(sorted1, 0, size - 1);
		stringSort(sorted2, 0, size - 1);

		// Флаги проверки выигрыша первой и второй строки
		bool flagFirstWon = true, flagSecondWon = true;
		// Проверяем, побеждает ли первая строка вторую
		for (size_t i = 0; i < size; i++) {
			if (!(sorted1[i] >= sorted2[i])) {
				flagFirstWon = false;
				break;
			}
		}

		// Если первая строка не победила, то проверяем вторую
		if (!flagFirstWon) {
			for (size_t i = 0; i < size; i++) {
				if (!(sorted2[i] >= sorted1[i])) {
					flagSecondWon = false;
					break;
				}
			}
		}
		else flagSecondWon = false;

		// Возвращаем результат
		return (flagFirstWon || flagSecondWon);
	}

	// Функция для первой задачи о строках (обёртка)
	void Task5Problem1Wrapper() {
		string str1, str2;
		cout << "Задача №1.\nВведите первую строку: ";
		cin >> str1;
		cout << "Введите вторую строку: ";
		cin >> str2;
		bool result = Task5Problem1(str1, str2);
		cout << "Результат для строк " << str1 << " и " << str2 << ": ";
		if (result) cout << "true.\n\n";
		else cout << "false.\n\n";
	}

	// Функция для проверки, является ли строка палиндромом
	bool isPalindrom(string str) {
		size_t length = str.length();
		if (length == 0 || length == 1) return true;
		else {
			bool flag = true;
			for (size_t i = 0; i < length / 2; i++) {
				if (!(str[i] == str[length - (i + 1)])) {
					flag = false;
					break;
				}
			}
			return flag;
		}
	}

	// Функция для второй задачи о строках
	string Task5Problem2(string str) {
		// Начальная проверка
		size_t length = str.length();
		if (length == 0) return str;
		else if (length == 1) return str;

		// Обрезаем первый символ из строки
		string result = str.substr(0, 1);
		// Основной цикл для вычислений
		for (size_t i = 1; i < length; i++) {
			// Находим наименьшую область
			size_t offset;
			if (i <= (length - (i + 1))) offset = i;
			else offset = (length - (i + 1));
			// Во вложенном цикле проходимся по отмеченной области и проверяем, являетя ли строка палиндромом
			for (size_t j = 0; j <= offset; j++) {
				string temp1, temp2;
				temp1 = str.substr(i - j, 2 * j + 1);
				temp2 = str.substr(i - j, 2 * j);
				// Палиндром с нечётным количеством символов
				if (isPalindrom(temp1)) {
					if (temp1.length() > result.length()) result = temp1;
				}
				// Палиндром с чётным количеством символов
				else if (isPalindrom(temp2)) {
					if (temp2.length() > result.length()) result = temp2;
				}
				else break;
			}
		}

		// Возвращаем результат
		return result;
	}

	// Функция для второй задачи о строках (обёртка)
	void Task5Problem2Wrapper() {
		string input, result;
		cout << "Задача №2.\nВведите строку: ";
		cin >> input;
		result = Task5Problem2(input);
		cout << "Результат для строки " << input << ": " << result << ".\n\n";
	}

	// Функция для третьей задачи о строках
	int Task5Problem3(string text) {
		int n = text.length();
		vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(n, 0));
		for (int i = 0; i < n; i++) {
			unsigned long long tmp = 0;
			for (int j = i; j < n; j++) {
				tmp = tmp * 29 + (text[j] - 'a' + 1);
				dp[i][j] = tmp;
			}
		}
		unordered_set<int> rnt;
		for (int i = 0; i < n - 1; i++) {
			for (int w = 1; i + 2 * w <= n; w++) {
				if (dp[i][i + w - 1] == dp[i + w][i + 2 * w - 1]) rnt.insert(dp[i][i + w - 1]);
			}
		}
		return rnt.size();
	}

	// Функция для третьей задачи о строках (обёртка)
	void Task5Problem3Wrapper() {
		string input;
		cout << "Задача №3.\nВведите строку: ";
		cin >> input;
		int result = Task5Problem3(input);
		cout << "Результат для строки " << input << ": " << result << ".\n\n";
	}

}

#endif TASK5_H