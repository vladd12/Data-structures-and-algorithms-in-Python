#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <string>
#include <vector>
#include "Lab4/Lab4.h"

using namespace std;

// ������������ ��� ��� ������������ �����
// �������: https://neerc.ifmo.ru/archive/2019/northern/nwq-2019-tutorials.pdf
namespace tasks {
	// ��� ����� ��� ���� ������
	typedef unsigned long long big_num;
	// ���������� ������� (������ �� 27 �������)
	void Task2Problem1Wrapper();
	bool Task2Problem1(char* pathfile);
	void Task2Problem2Wrapper();
	big_num Task2Problem2(big_num n);
	void Task2Problem3Wrapper();
	void Task2Problem3(string str, int* result);

	// ������� ������� � ���� ����������� �������, ������ ������
	bool Task2Problem1(char* pathfile) {
		// ���������� ����� � ��� ��������, �������� �������������� ������ � �������
		vector<string> file = lab4::readFile(pathfile);
		if (file.size() == 0 || file.size() == 1) {
			cout << "����� ������ ����!\n\n";
			return false;
		}

		// �������� �������
		int size = stoi(file[0]);
		if (size > (int)file.size() - 1) size = file.size() - 1;

		// �������� ���������� �� ����� � �������� ���������
		MyStack<char> stack;
		for (size_t i = 1; i < (unsigned int)size + 1; i++) {
			vector<string> separated = lab4::separate(file[i], " ");
			string action = separated[0], party = separated[1];
			if (action[0] == 'a' || action[0] == 'A') stack.push(party[0]);
			else if (action[0] == 'v' || action[0] == 'V') {
				if (stack.isEmpty()) return false;
				else if (stack.pop() != party[0]) return false;
			}
		}

		// ��������� �������� � ������� ����������
		if (stack.getSize() == 0) return true;
		else return false;
	}

	// ������ ��� ������ ������
	void Task2Problem1Wrapper() {
		// ���������� ������� � ����� �����������
		bool flag = Task2Problem1("Tasks/T01.txt");
		cout << "��������� ��� ����� \"Tasks/T01.txt\": ";
		if (flag) cout << "YES.\n\n";
		else cout << "NO.\n\n";
	}

	// ������ ������
	big_num Task2Problem2(big_num n) {
		// ������������������ ��������
		if (n % 3 == 0) return 3;
		else if (n % 2 == 1) {
			const big_num max = (big_num)sqrt((double)n);
			for (big_num i = 3; i < max; i++) {
				if (n % i == 0) return i;
			}
			return n;
		}
		else if (n % 2 == 0 && n % 4 != 0) {
			const big_num max = (big_num)sqrt((double)n);
			for (big_num i = 3; i < max; i++) {
				if (n % i == 0) return i;
			}
			return n / 2;
		}
		else if (n % 4 == 0) return 4;
		else return n;
	}

	// ������ ��� ������ ������
	void Task2Problem2Wrapper() {
		// ���������� ������� � ����� �����������
		big_num n;
		cout << "������� ����� ����� ������������: ";
		cin >> n;
		cout << "���-�� ����� ����������� ����������� ���������������: " << Task2Problem2(n) << "\n\n";
	}

	// ������ ������
	void Task2Problem3(string str, int* result) {
		if (str.length() == 1) {
			if (stoi(str) == 1) {
				result[0] = -1;
				return;
			}
			else {
				result[0] = 10;
				result[1] = 2;
				return;
			}
		}
		else {
			int sum = 0;
			for (size_t i = 0; i < str.length(); i++) {
				string sub = str.substr(i, 1);
				sum = sum + stoi(sub);
			}
			if (sum == 1) {
				result[0] = 10;
				result[1] = 2;
				return;
			}
			else {
				result[0] = sum + 1;
				result[1] = sum;
			}
		}



	}

	// ������ ��� ������ ������
	void Task2Problem3Wrapper() {
		// ���������� ������� � ����� �����������
		string str;
		cout << "������� ����� N: ";
		cin >> str;
		int* result = new int[2];
		Task2Problem3(str, result);
		cout << "���������: ";
		if (result[0] == -1) cout << result[0] << ".\n\n";
		else cout << result[0] << ", " << result[1] << ".\n\n";
		delete[] result;
	}

}

#endif TASK2_H