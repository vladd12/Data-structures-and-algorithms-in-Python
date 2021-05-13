#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <vector>

// ����� ��� ����
template <class Type> class MyDeque {
// ���������� ����� ������
protected:
	unsigned int size;
	std::vector<Type> deque;

// ��������� ����� ������
public:
	// ����������� ������
	MyDeque() {
		this->size = 0;
	}

	// ����� ��� �������� ����������� ����
	bool isEmpty() {
		return (deque.size() == 0);
	}

	// ����� ��� ������� ����
	void clear() {
		deque.clear();
		this->size = 0;
	}

	// ����� ���������� ���������� ��������� � ����
	unsigned int getSize() {
		return this->size;
	}

	// ����� ���������� �������� � ������ ����
	void pushFront(Type element) {
		deque.insert(deque.begin(), element);
		this->size += 1;
	}

	// ����� �������� �������� �� ������ ����
	Type popFront() {
		if (this->isEmpty()) {
			std::cout << "Deque is empty! Error!" << std::endl;
			return (Type)0;
		}
		else {
			Type ret = deque[0];
			deque.erase(deque.begin());
			std::vector<Type>(deque).swap(deque);
			this->size -= 1;
			return ret;
		}
	}

	// ����� ���������� �������� � ����� ����
	void pushBack(Type element) {
		deque.push_back(element);
		this->size += 1;
	}

	// ����� ���������� � �������� �������� �� ����� ����
	Type popBack() {
		if (this->isEmpty()) {
			std::cout << "Deque is empty! Error!" << std::endl;
			return (Type)0;
		}
		else {
			Type ret = deque.back();
			deque.pop_back();
			this->size -= 1;
			return ret;
		}
	}

	// ����� ��� ������ ��������� ���� � �������
	void print() {
		if (this->isEmpty()) std::cout << "Deque is empty!" << std::endl;
		else {
			for (size_t i = 0; i < this->size; i++) {
				std::cout << deque[i] << " ";
			}
			std::cout << std::endl;
		}
	}

};

#endif DEQUE_H