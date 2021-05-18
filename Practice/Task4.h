#ifndef TASK4_H
#define TASK4_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "Lab4/Lab4.h"

using namespace std;

// Пространство имён для практических задач
namespace tasks {
	// Объявления функций
	void Task4Problem1Wrapper();
	vector<vector<int>> Intervals(vector<vector<int>> input);
	bool IntervalComparer(vector<int> x, vector<int> y);

	// Компаратор для сравнения отрезков
	bool IntervalComparer(vector<int> x, vector<int> y) {
		return x[0] < y[0];
	}

	// Функция для выполнения задания
	vector<vector<int>> Intervals(vector<vector<int>> input) {
		// Проверка и сортировка
		if (input.size() == 0) return input;
		sort(input.begin(), input.end(), IntervalComparer);

		// Основной цикл
		MyStack<vector<int>> stack;
		vector<int> current = input[0];
		for (size_t i = 1; i < input.size(); i++) {
			vector<int> next = input[i];
			if (current[1] >= next[0]) current[1] = max(current[1], next[1]);
			else {
				stack.push(current);
				current = next;
			}
		}
		stack.push(current);

		// Возвращаем элементы из стека
		vector<vector<int>> ret(stack.getSize());
		for (int i = ret.size() - 1; i >= 0; i--) {
			ret[i] = stack.pop();
		}
		return ret;
	}

	// Функция обёртка для задания
	void Task4Problem1Wrapper() {
		cout << "Результат выполнения для [ [1, 3], [2, 6], [8, 10], [15, 18] ]:\n[ ";
		vector<vector<int>> result = Intervals({ { 1, 3 },{ 2, 6 },{ 8, 10 },{ 15, 18 } });
		for (size_t i = 0; i < result.size(); i++) {
			cout << "[" << result[i][0] << ", " << result[i][1] << "] ";
		}
		cout << "]\n";
		cout << "Результат выполнения для [ [1, 4], [4, 5] ]:\n[ ";
		result = Intervals({ { 1, 4 },{ 4, 5 } });
		for (size_t i = 0; i < result.size(); i++) {
			cout << "[" << result[i][0] << ", " << result[i][1] << "] ";
		}
		cout << "]\n";
		cout << endl;
	}

}

#endif TASK4_H