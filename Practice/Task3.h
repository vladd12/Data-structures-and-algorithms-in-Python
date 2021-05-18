#ifndef TASK3_H
#define TASK3_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "GetRandNum.h"

using namespace std;

// ������������ ��� ��� ������������ �����
namespace tasks {
	// ���������� �������
	void Task3Problem1Wrapper();
	unsigned int Task3Problem1(vector<unsigned int> arr);
	bool comp(unsigned int a, unsigned int b);
	void Task3Problem2Wrapper();
	string Task3Problem2(vector<int> arr);
	bool compString(string str1, string str2);
	void Task3Problem3Wrapper();

	// ���������� ����� ��� ���������� �� ��������
	bool comp(unsigned int a, unsigned int b) {
		return a > b;
	}

	// ������� ��� ������ ������
	unsigned int Task3Problem1(vector<unsigned int> arr) {
		// ��������� ������ �� ��������
		sort(arr.begin(), arr.end(), comp);
		unsigned int perim = 0;

		// ����� ���� ���������� ��������������� ������ � ���������, �������� �� �� ����������� ��� ���.
		size_t bound = arr.size() - 2;
		for (size_t i = 0; i <bound; i++) {
			if (arr[i] < arr[i + 1] + arr[i + 2]) {
				perim = max(perim, arr[i] + arr[i + 1] + arr[i + 2]);
				break;
			}
		}
		return perim;
	}

	// ������� ������ ��� ������ ������
	void Task3Problem1Wrapper() {
		// ���� ���������� ��������� ������� � ��� ����� � �������
		unsigned int num = 0;
		cout << "������� ���������� ��������� �� ������� �������: ";
		cin >> num;
		cout << "��������������� ������ ����� ��������� ���:\n";
		vector<unsigned int> input;
		for (size_t i = 0; i < num; i++) {
			unsigned int element = (unsigned int)getRandNum(1, 1000);
			cout << element << " ";
			input.push_back(element);
		}

		// ����� ������� � ����� �����������
		cout << "\n������������ �������� ������������ �� ��������� �������: " << Task3Problem1(input) << ".\n\n";
	}

	// ���������� ��� ����� �� ��������
	bool compString(string str1, string str2) {
		// �������� ����������� �����
		size_t min_length;
		if (str1.length() < str2.length()) min_length = str1.length();
		else min_length = str2.length();

		// ����������� �������� �� �������
		for (size_t i = 0; i < min_length; i++) {
			if (str1[i] > str2[i]) return true;
			else if (str1[i] < str2[i]) return false;
			else continue;
		}

		// ���� �� ��������� ����� ������ ���� �����������, �� ���������� �� �����
		if (str1.length() > str2.length()) return true;
		else return false;
	}

	// ������� ��� ������ ������
	string Task3Problem2(vector<int> arr) {
		// ������ ������ ����� �� ������� �����
		vector<string> StringList;
		for (size_t i = 0; i < arr.size(); i++) {
			StringList.push_back(to_string(arr[i]));
		}

		// ���������, ��������� � ���������� ���������
		sort(StringList.begin(), StringList.end(), compString);
		string result = "";
		for (size_t i = 0; i < StringList.size(); i++) result += StringList[i];
		return result;
	}

	// ������� ������ ��� ������ ������
	void Task3Problem2Wrapper() {
		// ���� ���������� ��������� ������� � ��� ����� � �������
		unsigned int num = 0;
		cout << "������� ���������� ��������� �� ������� �������: ";
		cin >> num;
		cout << "��������������� ������ ����� ��������� ���:\n";
		vector<int> input;
		for (size_t i = 0; i < num; i++) {
			int element = getRandNum(1, 1000);
			cout << element << " ";
			input.push_back(element);
		}

		// ����� ������� � ����� �����������
		cout << "\n������������ �����: " << Task3Problem2(input) << ".\n\n";
	}

	// ������� ������ ��� ������� ������
	void Task3Problem3Wrapper() {
		// ���� ���������� ��������� �������, ����� � �������
		unsigned int rows = 0, cols = 0;
		cout << "������� ���������� ����� � �������� � �������: ";
		cin >> rows >> cols;
		cout << "��������������� ������� ����� ��������� ���:\n";
		vector<vector<int>> input(rows);
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				int element = getRandNum(1, 1000);
				cout << element << " ";
				input[i].push_back(element);
			}
			cout << "\n";
		}

		// ����������
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

		// ����� ����������
		cout << "���������������� �������:\n";
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