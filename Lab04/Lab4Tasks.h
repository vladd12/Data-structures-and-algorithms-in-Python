#ifndef LAB4TASKS_H
#define LAB4TASKS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Deque.h"
#include "Stack.h"

using namespace std;

namespace lab4 {
	// Объявления функций
	vector<string> readFile(char* pathFile);
	bool isDigit(char sym);
	bool isCharacter(char sym);
	void Task09();
	bool Task09Calc(string input);
	bool isBoolean(char sym);
	int getPriority(char sym);
	char operationAnd(MyStack<char>* stack);
	char operationOr(MyStack<char>* stack);
	char operationXor(MyStack<char>* stack);
	char operationDeny(MyStack<char>* stack);
	void Task10();
	int Task10Calc(string input);
	int max(MyStack<char>* stack);
	int min(MyStack<char>* stack);
	void Task11();
	bool Task11Calc(string input);

	// Чтение из файла массива строк
	vector<string> readFile(char* pathFile) {
		string temp;
		vector <string> result;
		ifstream in(pathFile);
		while (in >> temp) result.push_back(temp);
		return result;
	}

	// Проверка на то, является ли символ цифрой
	bool isDigit(char sym) {
		return ((int)sym >= 48 && (int)sym <= 59);
	}

	// Проверка на то, является ли символ буквой английского алфавита
	bool isCharacter(char sym) {
		return (((int)sym >= 65 && (int)sym <= 90) || ((int)sym >= 97 && (int)sym <= 122));
	}

	// Проверка на то, является ли символ булевым значением
	bool isBoolean(char sym) {
		return (sym == 'T' || sym == 'F');
	}

	// Функция для получения приоритета операции
	int getPriority(char sym) {
		switch (sym) {
		case '(':
			return 3;
		case 'N':
		case 'A':
			return 2;
		case 'O':
		case 'X':
			return 1;
		default:
			break;
		}
		return 0;
	}

	// Функция для операции "И"
	char operationAnd(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'F' || second == 'F') return 'F';
		else return 'T';
	}

	// Функция для операции "ИЛИ"
	char operationOr(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'F' && second == 'F') return 'F';
		else return 'T';
	}

	// Функция для операции "ИСКЛЮЧАЮЩЕЕ ИЛИ"
	char operationXor(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'F' && second == 'F' || second == 'T' && first == 'T') return 'F';
		else return 'T';
	}

	// Функция для операции "НЕ"
	char operationDeny(MyStack<char>* stack) {
		char first = stack->pop();
		if (first == 'F') return 'T';
		else return 'F';
	}

	// Основная функция для решения логической последовательности в задании 9
	bool Task09Calc(string input) {
		// Начальная проверка
		if (input.length() == 0) {
			cout << "Введена пустая строка!\n";
			return false;
		}
		string output = "";
		MyStack<char> stack;

		// Заносим операции в стек
		for (size_t i = 0; i < input.length(); i++) {
			char sym = input[i];
			if (isBoolean(sym)) output += sym;
			else {
				switch (sym) {
				case '(':
					break;
				case ')':
					break;
				case 'A':
				case 'O':
				case 'X':
				case 'N':
					if (stack.isEmpty()) stack.push(sym);
					else {
						while (stack.getSize() > 0 && (getPriority(sym) <= stack.peek())) {
							if ('(' == stack.peek()) break;
							else output += stack.pop();
						}
						stack.push(sym);
					}
					break;
				default:
					cout << "Некорректный синтаксис выражения.\n";
					return false;
					break;
				}
			}
		}

		// Выполнение операций из стека
		while (!stack.isEmpty()) output += stack.pop();
		while (!isBoolean(output[output.length() - 1])) {
			if (isBoolean(output[0])) {
				stack.push(output[0]);
				output = output.substr(1);
			}
			else {
				char oper = output[0];
				output = output.substr(1);
				switch (oper) {
				case 'A':
					output = operationAnd(&stack) + output;
					break;
				case 'O':
					output = operationOr(&stack) + output;
					break;
				case 'X':
					output = operationXor(&stack) + output;
					break;
				case 'N':
					output = operationDeny(&stack) + output;
					break;
				default:
					break;
				}
			}
		}

		// Финальная проверка и возврат результатов
		if (stack.getSize() != 0) {
			cout << "Некорректный синтаксис выражения.\n";
			return false;
		}
		if (output[0] == 'T') return true;
		else return false;
	}

	// Задание 9
	void Task09() {
		string str = readFile("Lab4/Task09.txt")[0];
		bool result = Task09Calc(str);
		cout << "Результат для выражения " << str << ": ";
		if (result) cout << "true.\n";
		else cout << "false.\n";
	}

	// Функция для операции нахождения максимума
	int max(MyStack<char>* stack) {
		int first = stack->pop() - '0';
		int second = stack->pop() - '0';
		if (first >= second) return first;
		else return second;
	}

	// Функция для операция нахождения минимума
	int min(MyStack<char>* stack) {
		int first = stack->pop() - '0';
		int second = stack->pop() - '0';
		if (first < second) return first;
		else return second;
	}

	// Основная функция для решения записи в задании 10
	int Task10Calc(string input) {
		// Начальная проверка
		if (input.length() == 0) {
			cout << "Введена пустая строка!\n";
			return -1;
		}
		MyStack<char> stack;
		string output = "";

		// Заносим операции в стек
		for (size_t i = 0; i < input.length(); i++) {
			char sym = input[i];
			if (isDigit(sym)) output += sym;
			else {
				switch (sym) {
				case '(':
				case ',':
				case 'M':
				case 'N':
					stack.push(sym);
					break;
				case ')':
					if (stack.peek() != ',') {
						cout << "Некорректный синтаксис выражения.\n";
						return -1;
					}
					stack.pop();
					stack.pop();
					output += stack.pop();
					break;
				default:
					cout << "Некорректный синтаксис выражения.\n";
					return -1;
					break;
				}
			}
		}

		// Выполнение операций из стека
		while (!stack.isEmpty()) output += stack.pop();
		while (!isDigit(output[output.length() - 1])) {
			if (isDigit(output[0])) {
				stack.push(output[0]);
				output = output.substr(1);
			}
			else {
				char operation = output[0];
				output = output.substr(1);
				switch (operation)
				{
				case 'M':
					output = to_string(max(&stack)) + output;
					break;
				case 'N':
					output = to_string(min(&stack)) + output;
					break;
				default:
					cout << "Некорректный синтаксис выражения.\n";
					return -1;
					break;
				}
			}
		}

		// Финальная проверка и возврат результатов
		if (stack.getSize() != 0) {
			cout << "Некорректный синтаксис выражения.\n";
			return -1;
		}
		int result = output[0] - '0';
		return result;
	}

	// Задание 10
	void Task10() {
		string str = readFile("Lab4/Task10.txt")[0];
		int result = Task10Calc(str);
		cout << "Результат для выражения " << str << ": " << result << endl;
	}

	// Функция для проверки, является ли символ переменной
	bool isName(char sym) {
		if (sym == 'X' || sym == 'Y' || sym == 'Z') return true;
		else return false;
	}

	// Функция для проверки операций
	char PMoper(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'X' || first == 'Y' || first == 'Z') {
			if (second == 'X' || second == 'Y' || second == 'Z') return 'X';
		}
		return 'T';
	}

	// Функция для проверки, является ли введённое выражение правильным
	bool Task11Calc(string input) {
		// Начальная проверка
		if (input.length() == 0) {
			cout << "Введена пустая строка!\n";
			return false;
		}
		MyStack<char> stack;
		string output = "";

		// Заносим операции в стек
		for (size_t i = 0; i < input.length(); i++) {
			char sym = input[i];
			if (isName(sym)) output += sym;
			else {
				switch (sym) {
				case '(':
				case '+':
				case '-':
					stack.push(sym);
					break;
				case ')':
					while (stack.peek() != '(') output += stack.pop();
					stack.pop();
					break;
				default:
					cout << "Некорректный синтаксис выражения.\n";
					return false;
					break;
				}
			}
		}

		// 
		while (!stack.isEmpty()) output += stack.pop();
		while (!isName(output[output.length() - 1])) {
			if (isName(output[0])) {
				stack.push(output[0]);
				output = output.substr(1);
			}
			else {
				char operation = output[0];
				output = output.substr(1);
				switch (operation) {
				case '+':
				case '-':
					output = PMoper(&stack) + output;
					break;
				default:
					cout << "Некорректный синтаксис выражения.\n";
					return false;
					break;
				}
			}
		}

		// Финальная проверка и возврат результатов
		if (stack.getSize() != 0) {
			cout << "Некорректный синтаксис выражения.\n";
			return false;
		}
		else return true;
	}

	// Задание 11
	void Task11() {
		string str = readFile("Lab4/Task11.txt")[0];
		bool result = Task11Calc(str);
		cout << "Выражение " << str << " является ";
		if (result) cout << "корректным.\n";
		else cout << "некорректным.\n";
	}

}

#endif LAB4TASKS_H
