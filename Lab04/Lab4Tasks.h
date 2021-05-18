#ifndef LAB4TASKS_H
#define LAB4TASKS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GetTime.h"
#include "Deque.h"
#include "Stack.h"

using namespace std;

// Пространство имён 4 лабораторной работы
namespace lab4 {
	// Объявления функций
	vector<string> readFile(char* pathFile);
	void Task01(char* pathfile);
	bool compareString(string in1, string in2);
	void Task02();
	string encode(string input, MyDeque<char>* cipher);
	string decode(string input, MyDeque<char>* cipher);
	void Task03();
	void HanoiSolver(MyStack<size_t>* from, MyStack<size_t>* buf, MyStack<size_t>* to, size_t count);
	void Task04();
	bool Task04Calc(char* pathfile);
	void Task05();
	bool Task05Calc(char* pathfile);
	void Task06();
	bool Task06Calc(char* pathfile, MyStack<char>* arr);
	bool isDigit(char sym);
	bool isCharacter(char sym);
	void Task07();
	vector<string> separate(string str, string separator);



	
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
		while (getline(in, temp)) result.push_back(temp);
		in.close();
		return result;
	}

	// Функция сравнения двух строк, возвращает true, если сначала должна быть первая строка, false - если вторая
	bool compareString(string in1, string in2) {
		// in1 - сверяемая строка, in2 - temp sorted строка
		size_t size = 0;
		if (in1.length() <= in2.length()) size = in1.length();
		else size = in2.length();
		
		// Основной цикл. Посимвольно сравниваем строки с использованием переменной-флага
		bool flag = true;
		size_t counter = 0;
		for (size_t i = 0; i < size; i++) {
			// Если первая строка по индексу должна быть перед второй
			if ((int)in1[i] < (int)in2[i]) break;
			// Если первая строка должна быть после второй
			else if ((int)in1[i] > (int)in2[i]) {
				flag = false;
				return flag;
			}
			// Если символы совпадают
			else {
				counter += 1;
				continue;
			}
		}
		// Если длина первой строки больше второй, но символы совпали, то она должна идти второй, flag = false
		if (flag && (counter == size) && (in1.length() > in2.length())) flag = false;
		// После прохождения предыдущих проверок возвращаем флаг
		return flag;
	}

	// Задание 1
	void Task01(char* pathfile) {
		// Считывание файла и его проверка
		vector<string> file = readFile(pathfile);
		if (file.size() == 0) {
			cout << "Введён пустой файл!\n\n";
			return;
		}

		// Основной цикл
		clock_t start = clock(), end;
		MyDeque<string> result, temp_field;
		result.pushFront(file[0]);
		size_t file_size = file.size();
		for (size_t i = 1; i < file_size; i++) {
			// Вытаскиваем из файла i-ую строку
			string temp = file[i];
			string sorted = result.popFront();
			// Если строка должен быть в начале дека
			if (compareString(temp, sorted)) {
				// Возвращаем элементы в нужной последовательности
				result.pushFront(sorted);
				result.pushFront(temp);
			}
			else {
				temp_field.pushBack(sorted);
				// Если дек непустой
				if (result.getSize() > 0) {
					// Пока в деке есть элементы или не найден нужный элемент
					while (result.getSize() > 0) {
						sorted = result.popFront();
						if (!compareString(temp, sorted)) temp_field.pushBack(sorted);
						else {
							temp_field.pushBack(sorted);
							break;
						}
					}
					// Строка найдена или подошли к концу дека
					result.pushFront(temp);
					// Возвращаем всё на место из временного дека
					while (temp_field.getSize() > 0) {
						result.pushFront(temp_field.popBack());
					}
				}
				// Если дек оказался пустым, возвращаем все элементы в нужном порядке
				else {
					result.pushFront(temp);
					result.pushFront(temp_field.popBack());
				}
			}
		}
		end = clock();

		// Вывод времени выполнения
		size_t result_size = result.getSize();
		cout << "Время сортировки двумя деками " << result_size << " элементов: " << getTime(start, end) << " sec.\n";
		// Вывод отсортированного дека
		cout << "Отсортированный файл:\n";
		for (size_t i = 0; i < result_size; i++) {
			cout << result.popFront() << "\n";
		}
		cout << endl;
	}

	// Функция для зашифровки
	string encode(string input, MyDeque<char>* cipher) {
		string result = "";
		for (size_t i = 0; i < input.length(); i++) {
			// Если символ пробел или перенос строки
			if (input[i] == ' ' || input[i] == '\n') result = result + input[i];
			else {
				char sym = cipher->popFront();
				// Пока не найден символ
				while (sym != input[i]) {
					cipher->pushBack(sym);
					sym = cipher->popFront();
				}
				// Символ найден, возвращаем его в дек
				cipher->pushBack(sym);
				// Пропускаем один символ
				cipher->pushBack(cipher->popFront());
				// Получаем шифруемый символ, используем его и возвращаем в дек
				sym = cipher->popFront();
				result = result + sym;
				cipher->pushBack(sym);
			}
		}
		return result;
	}

	// Функция для расширофвки
	string decode(string input, MyDeque<char>* cipher) {
		string result = "";
		for (size_t i = 0; i < input.length(); i++) {
			// Если символ пробел или перенос строки
			if (input[i] == ' ' || input[i] == '\n') result = result + input[i];
			else {
				char sym = cipher->popFront();
				// Пока не найден символ
				while (sym != input[i]) {
					cipher->pushBack(sym);
					sym = cipher->popFront();
				}
				// Символ найден, возвращаем его в дек
				cipher->pushFront(sym);
				// Пропускаем один символ
				cipher->pushFront(cipher->popBack());
				// Получаем шифруемый символ, используем его и возвращаем в дек
				sym = cipher->popBack();
				result = result + sym;
				cipher->pushFront(sym);
			}
		}
		return result;
	}

	// Задание 2
	void Task02() {
		// Считывание файла и его проверка, создание результирующего текста
		vector<string> file = readFile("Lab4/Task01.txt");
		if (file.size() == 0) {
			cout << "Введён пустой файл!\n\n";
			return;
		}
		string text = "", encoded, decoded;
		for (size_t i = 0; i < file.size(); i++) text = text + (file[i] + "\n");

		// Формируем дек для шифрования
		MyDeque<char> cipher;
		for (size_t i = 0; i < 256; i++) cipher.pushBack((char)i);

		// Шифруем и замеряем время
		clock_t start, end;
		start = clock();
		encoded = encode(text, &cipher);
		end = clock();
		cout << "Время шифрования текста деком: " << getTime(start, end) << " sec.\n";
		cout << "Результат шифрования:\n" << encoded << "\n";

		// Расшифровываем и замеряем время
		start = clock();
		decoded = decode(encoded, &cipher);
		end = clock();
		cout << "Время расшифрования текста деком: " << getTime(start, end) << " sec.\n";
		cout << "Результат расшифрования:\n" << decoded << "\n\n";
	}

	// Функция для решения загадки о Ханойских башнях
	void HanoiSolver(MyStack<size_t>* from, MyStack<size_t>* buf, MyStack<size_t>* to, size_t count) {
		if (count != 0) {
			HanoiSolver(from, to, buf, count - 1);
			to->push(from->pop());
			HanoiSolver(buf, from, to, count - 1);
		}
	}

	// Задание 3
	void Task03() {
		// Ввод количества колец на первом стержне, заполнение первого стека
		size_t num;
		cout << "Введите количество колец на первом стержне: ";
		cin >> num;
		MyStack<size_t> first, second, third;
		for (size_t i = 1; i <= num; i++) first.push(i);

		// Вывод содержимого стеков перед операцией перемещения
		cout << "\nИзначальное содержимое стеков:\n";
		cout << "First: "; first.print(); cout << "Second: "; second.print(); cout << "Third: "; third.print();

		// Выполнение операции по решению задачи, замеры времени
		clock_t start = clock(), end;
		HanoiSolver(&first, &second, &third, num);
		end = clock();

		// Вывод содержимого стеков после операции перемещения и времени выполнения
		cout << "\nСодержимое стеков после перемещения:\n";
		cout << "First: "; first.print(); cout << "Second: "; second.print(); cout << "Third: "; third.print();
		cout << "Время выполнения операции перемещения: " << getTime(start, end) << " sec.\n\n";
	}

	// Основная функция для решения 4 задачи
	bool Task04Calc(char* pathfile) {
		// Считывание файла и его проверка, создание результирующей строки с текстом
		vector<string> file = readFile(pathfile);
		if (file.size() == 0) {
			cout << "Введён пустой файл!\n";
			return false;
		}
		string text = "";
		for (size_t i = 0; i < file.size(); i++) text = text + (file[i] + "\n");

		// Добавляем и удаляем элементы из стека, соблюдая баланс
		MyStack<char> stack;
		for (size_t i = 0; i < text.length(); i++) {
			if (text[i] == '(') stack.push('(');
			else if (text[i] == ')') {
				if (stack.getSize() > 0) stack.pop();
				else return false;
			}
		}

		// Финальная проверка
		if (stack.getSize() > 0) return false;
		else return true;
	}

	// Задание 4
	void Task04() {
		// Выполнение функции и вывод результатов
		bool flag = Task04Calc("Lab4/Deque.h");
		cout << "Результат для файла \"Lab4/Deque.h\": ";
		if (flag) cout << "true.\n\n";
		else cout << "false.\n\n";
	}

	// Основная функция для решения 5 задачи
	bool Task05Calc(char* pathfile) {
		// Считывание файла и его проверка, создание результирующей строки с текстом
		vector<string> file = readFile(pathfile);
		if (file.size() == 0) {
			cout << "Введён пустой файл!\n";
			return false;
		}
		string text = "";
		for (size_t i = 0; i < file.size(); i++) text = text + (file[i] + "\n");

		// Добавляем элементы в дек
		MyDeque<char> deque;
		for (size_t i = 0; i < text.length(); i++) {
			if (text[i] == '[') deque.pushFront('[');
			else if (text[i] == ']') deque.pushBack(']');
		}

		// Проверка элементов в деке
		while (deque.getSize() > 1) {
			if (!(deque.popFront() == '[' && deque.popBack() == ']')) return false;
		}
		if (deque.isEmpty()) return true;
		else return false;
	}

	// Задание 5
	void Task05() {
		// Выполнение функции и вывод результатов
		bool flag = Task05Calc("Lab4/Deque.h");
		cout << "Результат для файла \"Lab4/Deque.h\": ";
		if (flag) cout << "true.\n\n";
		else cout << "false.\n\n";
	}

	// Проверка на то, является ли символ цифрой
	bool isDigit(char sym) {
		return ((int)sym >= 48 && (int)sym <= 57);
	}

	// Проверка на то, является ли символ буквой английского алфавита
	bool isCharacter(char sym) {
		return (((int)sym >= 65 && (int)sym <= 90) || ((int)sym >= 97 && (int)sym <= 122));
	}

	// Основная функция для решения 6 задачи
	bool Task06Calc(char* pathfile, MyStack<char>* arr) {
		// Считывание файла и его проверка, создание результирующей строки с текстом
		vector<string> file = readFile(pathfile);
		if (file.size() == 0) {
			cout << "Введён пустой файл!\n\n";
			return false;
		}
		string text = "";
		for (size_t i = 0; i < file.size(); i++) text = text + (file[i] + "\n");

		// Заполнение 3 стеков
		for (int i = text.length() - 1; i >= 0; i--) {
			if (isDigit(text[i])) arr[0].push(text[i]);
			else if (isCharacter(text[i])) arr[1].push(text[i]);
			else arr[2].push(text[i]);
		}
		return true;
	}

	// Задание 6
	void Task06() {
		// Выполнение функции и вывод результатов
		const size_t arr_size = 3;
		MyStack<char>* syms = new MyStack<char>[arr_size];
		bool flag = Task06Calc("Lab4/Deque.h", syms);
		// Если функция успешно выполнилась, выводим поочерёдно содержимое стеков
		if (flag) {
			for (size_t i = 0; i < arr_size; i++) {
				while (!syms[i].isEmpty()) cout << syms[i].pop();
			}
			cout << endl;
			delete[] syms;
		}
		// В противном случае выходим из функции
		else {
			delete[] syms;
			return;
		}
	}

	// Функция для получения массива подстрок из строки через указанный разделитель
	vector<string> separate(string str, string separator) {
		vector<string> arr;
		size_t prev = 0;
		size_t next;
		size_t delta = separator.length();
		while ((next = str.find(separator, prev)) != string::npos) {
			arr.push_back(str.substr(prev, next - prev));
			prev = next + delta;
		}
		arr.push_back(str.substr(prev));
		return arr;
	}

	// Задание 7
	void Task07() {
		// Считывание файла и его проверка, создание результирующей строки с текстом
		vector<string> file = readFile("Lab4/Task07.txt");
		if (file.size() == 0) {
			cout << "Введён пустой файл!\n\n";
			return;
		}
		string text = "";
		for (size_t i = 0; i < file.size(); i++) text = text + (file[i] + " ");

		// Повторно используем массив file, пишем туда подстроки через разделитель " "
		file = separate(text, " ");

		// Циклично конвертируем значения в числовой тип, затем кладём их в дек
		MyDeque<int> deque;
		// Сначала все отрицательные числа
		for (size_t i = 0; i < file.size() - 1; i++) {
			int num = std::stoi(file[i]);
			if (num < 0) deque.pushBack(num);
		}
		// Затем все положительные
		for (size_t i = 0; i < file.size() - 1; i++) {
			int num = std::stoi(file[i]);
			if (num >= 0) deque.pushBack(num);
		}

		// Вывод элементов
		while (!deque.isEmpty()) cout << deque.popFront() << " ";
		cout << "\n\n";
	}

	// Задание 8
	void Task08() {
		// Считывание файла и его проверка
		vector<string> file = readFile("Lab4/Deque.h");
		if (file.size() == 0) {
			cout << "Введён пустой файл!\n\n";
			return;
		}

		// Создаём стек и пушим туда все строки из файла
		MyStack<string> stack;
		for (size_t i = 0; i < file.size(); i++) {
			stack.push(file[i]);
		}
		// Затем выводим все строки из стека
		while (!stack.isEmpty()) cout << stack.pop() << "\n";
		cout << endl;
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
