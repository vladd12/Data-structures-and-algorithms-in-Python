#ifndef TASK5_H
#define TASK5_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// ������������ ��� ��� ������������ �����
namespace tasks {
	// ���������� �������
	void Task5Problem1Wrapper();
	bool Task5Problem1(string str1, string str2);
	void stringSort(char* str, int first, int last);
	void Task5Problem2Wrapper();
	string Task5Problem2(string str);
	bool isPalindrom(string str);
	void Task5Problem3Wrapper();
	int Task5Problem3(string text);

	// ������� ���������� ������ �� ��������
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

	// ������� ��� ������ ������ � ������� (�������� ��������)
	bool Task5Problem1(string str1, string str2) {
		// ��������� ��������
		if (str1.length() != str2.length()) {
			cout << "������ ����� ������ �����!\n";
			return false;
		}

		// ����������� ����� � ��������� char � �� ����������
		size_t size = str1.length();
		char* sorted1 = new char[size];
		char* sorted2 = new char[size];
		memcpy(sorted1, str1.data(), size * sizeof(char));
		memcpy(sorted2, str2.data(), size * sizeof(char));
		stringSort(sorted1, 0, size - 1);
		stringSort(sorted2, 0, size - 1);

		// ����� �������� �������� ������ � ������ ������
		bool flagFirstWon = true, flagSecondWon = true;
		// ���������, ��������� �� ������ ������ ������
		for (size_t i = 0; i < size; i++) {
			if (!(sorted1[i] >= sorted2[i])) {
				flagFirstWon = false;
				break;
			}
		}

		// ���� ������ ������ �� ��������, �� ��������� ������
		if (!flagFirstWon) {
			for (size_t i = 0; i < size; i++) {
				if (!(sorted2[i] >= sorted1[i])) {
					flagSecondWon = false;
					break;
				}
			}
		}
		else flagSecondWon = false;

		// ���������� ���������
		return (flagFirstWon || flagSecondWon);
	}

	// ������� ��� ������ ������ � ������� (������)
	void Task5Problem1Wrapper() {
		string str1, str2;
		cout << "������ �1.\n������� ������ ������: ";
		cin >> str1;
		cout << "������� ������ ������: ";
		cin >> str2;
		bool result = Task5Problem1(str1, str2);
		cout << "��������� ��� ����� " << str1 << " � " << str2 << ": ";
		if (result) cout << "true.\n\n";
		else cout << "false.\n\n";
	}

	// ������� ��� ��������, �������� �� ������ �����������
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

	// ������� ��� ������ ������ � �������
	string Task5Problem2(string str) {
		// ��������� ��������
		size_t length = str.length();
		if (length == 0) return str;
		else if (length == 1) return str;

		// �������� ������ ������ �� ������
		string result = str.substr(0, 1);
		// �������� ���� ��� ����������
		for (size_t i = 1; i < length; i++) {
			// ������� ���������� �������
			size_t offset;
			if (i <= (length - (i + 1))) offset = i;
			else offset = (length - (i + 1));
			// �� ��������� ����� ���������� �� ���������� ������� � ���������, ������� �� ������ �����������
			for (size_t j = 0; j <= offset; j++) {
				string temp1, temp2;
				temp1 = str.substr(i - j, 2 * j + 1);
				temp2 = str.substr(i - j, 2 * j);
				// ��������� � �������� ����������� ��������
				if (isPalindrom(temp1)) {
					if (temp1.length() > result.length()) result = temp1;
				}
				// ��������� � ������ ����������� ��������
				else if (isPalindrom(temp2)) {
					if (temp2.length() > result.length()) result = temp2;
				}
				else break;
			}
		}

		// ���������� ���������
		return result;
	}

	// ������� ��� ������ ������ � ������� (������)
	void Task5Problem2Wrapper() {
		string input, result;
		cout << "������ �2.\n������� ������: ";
		cin >> input;
		result = Task5Problem2(input);
		cout << "��������� ��� ������ " << input << ": " << result << ".\n\n";
	}

	// ������� ��� ������� ������ � �������
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

	// ������� ��� ������� ������ � ������� (������)
	void Task5Problem3Wrapper() {
		string input;
		cout << "������ �3.\n������� ������: ";
		cin >> input;
		int result = Task5Problem3(input);
		cout << "��������� ��� ������ " << input << ": " << result << ".\n\n";
	}

}

#endif TASK5_H