#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <string>
#include "Lab3Strings.h"

using namespace std;

// ������������ ��� 3 ������������ ������
namespace lab3 {
	// ������� ������� ��� ������������ ������
	void Lab3Start() {
		// ������� ����������� ����� ����� ������� ��������
		cout << "�������� ���.\n";
		KMP_Wrapper();
		cout << "\n�������� ��.\n";
		BM_Wrapper();
		cout << endl;
	}







}

#endif LAB3_H
