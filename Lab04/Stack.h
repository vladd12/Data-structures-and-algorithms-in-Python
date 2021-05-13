#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

// ����� ��� �����
template <class Type> class MyStack {
// ���������� ����� ������
protected:
	unsigned int size;
	std::vector<Type> stack;

// ��������� ����� ������
public:
	// ����������� ������
	MyStack() {
		this->size = 0;
	}

	// ����� ��� �������� ����������� �����
	bool isEmpty() {
		return (stack.size() == 0);
	}

	// ����� ��� ������� �����
	void clear() {
		stack.clear();
		this->size = 0;
	}

	// ����� ���������� ���������� ��������� � �����
	unsigned int getSize() {
		return this->size;
	}

	// ����� ���������� �������� � ����
	void push(Type element) {
		stack.push_back(element);
		this->size += 1;
	}

	// ����� ���������� �������� � ������� �����
	Type peek() {
		if (this->isEmpty()) {
			std::cout << "Stack is empty! Error!" << std::endl;
			return (Type)0;
		}
		else return stack.back();
	}

	// ����� ���������� � �������� �������� �� �����
	Type pop() {
		if (this->isEmpty()) {
			std::cout << "Stack is empty! Error!" << std::endl;
			return (Type)0;
		}
		else {
			Type ret = stack.back();
			stack.pop_back();
			this->size -= 1;
			return ret;
		}
	}

	// ����� ��� ������ ��������� ����� � �������
	void print() {
		if (this->isEmpty()) std::cout << "Stack is empty!" << std::endl;
		else {
			for (size_t i = 0; i < this->size; i++) {
				std::cout << stack[i] << " ";
			}
			std::cout << std::endl;
		}
	}

};

#endif STACK_H
