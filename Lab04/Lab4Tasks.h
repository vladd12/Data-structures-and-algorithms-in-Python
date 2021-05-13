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
	// ���������� �������
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

	// ������ �� ����� ������� �����
	vector<string> readFile(char* pathFile) {
		string temp;
		vector <string> result;
		ifstream in(pathFile);
		while (in >> temp) result.push_back(temp);
		return result;
	}

	// �������� �� ��, �������� �� ������ ������
	bool isDigit(char sym) {
		return ((int)sym >= 48 && (int)sym <= 59);
	}

	// �������� �� ��, �������� �� ������ ������ ����������� ��������
	bool isCharacter(char sym) {
		return (((int)sym >= 65 && (int)sym <= 90) || ((int)sym >= 97 && (int)sym <= 122));
	}

	// �������� �� ��, �������� �� ������ ������� ���������
	bool isBoolean(char sym) {
		return (sym == 'T' || sym == 'F');
	}

	// ������� ��� ��������� ���������� ��������
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

	// ������� ��� �������� "�"
	char operationAnd(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'F' || second == 'F') return 'F';
		else return 'T';
	}

	// ������� ��� �������� "���"
	char operationOr(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'F' && second == 'F') return 'F';
		else return 'T';
	}

	// ������� ��� �������� "����������� ���"
	char operationXor(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'F' && second == 'F' || second == 'T' && first == 'T') return 'F';
		else return 'T';
	}

	// ������� ��� �������� "��"
	char operationDeny(MyStack<char>* stack) {
		char first = stack->pop();
		if (first == 'F') return 'T';
		else return 'F';
	}

	// �������� ������� ��� ������� ���������� ������������������ � ������� 9
	bool Task09Calc(string input) {
		// ��������� ��������
		if (input.length() == 0) {
			cout << "������� ������ ������!\n";
			return false;
		}
		string output = "";
		MyStack<char> stack;

		// ������� �������� � ����
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
					cout << "������������ ��������� ���������.\n";
					return false;
					break;
				}
			}
		}

		// ���������� �������� �� �����
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

		// ��������� �������� � ������� �����������
		if (stack.getSize() != 0) {
			cout << "������������ ��������� ���������.\n";
			return false;
		}
		if (output[0] == 'T') return true;
		else return false;
	}

	// ������� 9
	void Task09() {
		string str = readFile("Lab4/Task09.txt")[0];
		bool result = Task09Calc(str);
		cout << "��������� ��� ��������� " << str << ": ";
		if (result) cout << "true.\n";
		else cout << "false.\n";
	}

	// ������� ��� �������� ���������� ���������
	int max(MyStack<char>* stack) {
		int first = stack->pop() - '0';
		int second = stack->pop() - '0';
		if (first >= second) return first;
		else return second;
	}

	// ������� ��� �������� ���������� ��������
	int min(MyStack<char>* stack) {
		int first = stack->pop() - '0';
		int second = stack->pop() - '0';
		if (first < second) return first;
		else return second;
	}

	// �������� ������� ��� ������� ������ � ������� 10
	int Task10Calc(string input) {
		// ��������� ��������
		if (input.length() == 0) {
			cout << "������� ������ ������!\n";
			return -1;
		}
		MyStack<char> stack;
		string output = "";

		// ������� �������� � ����
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
						cout << "������������ ��������� ���������.\n";
						return -1;
					}
					stack.pop();
					stack.pop();
					output += stack.pop();
					break;
				default:
					cout << "������������ ��������� ���������.\n";
					return -1;
					break;
				}
			}
		}

		// ���������� �������� �� �����
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
					cout << "������������ ��������� ���������.\n";
					return -1;
					break;
				}
			}
		}

		// ��������� �������� � ������� �����������
		if (stack.getSize() != 0) {
			cout << "������������ ��������� ���������.\n";
			return -1;
		}
		int result = output[0] - '0';
		return result;
	}

	// ������� 10
	void Task10() {
		string str = readFile("Lab4/Task10.txt")[0];
		int result = Task10Calc(str);
		cout << "��������� ��� ��������� " << str << ": " << result << endl;
	}

	// ������� ��� ��������, �������� �� ������ ����������
	bool isName(char sym) {
		if (sym == 'X' || sym == 'Y' || sym == 'Z') return true;
		else return false;
	}

	// ������� ��� �������� ��������
	char PMoper(MyStack<char>* stack) {
		char first = stack->pop();
		char second = stack->pop();
		if (first == 'X' || first == 'Y' || first == 'Z') {
			if (second == 'X' || second == 'Y' || second == 'Z') return 'X';
		}
		return 'T';
	}

	// ������� ��� ��������, �������� �� �������� ��������� ����������
	bool Task11Calc(string input) {
		// ��������� ��������
		if (input.length() == 0) {
			cout << "������� ������ ������!\n";
			return false;
		}
		MyStack<char> stack;
		string output = "";

		// ������� �������� � ����
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
					cout << "������������ ��������� ���������.\n";
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
					cout << "������������ ��������� ���������.\n";
					return false;
					break;
				}
			}
		}

		// ��������� �������� � ������� �����������
		if (stack.getSize() != 0) {
			cout << "������������ ��������� ���������.\n";
			return false;
		}
		else return true;
	}

	// ������� 11
	void Task11() {
		string str = readFile("Lab4/Task11.txt")[0];
		bool result = Task11Calc(str);
		cout << "��������� " << str << " �������� ";
		if (result) cout << "����������.\n";
		else cout << "������������.\n";
	}

}

#endif LAB4TASKS_H