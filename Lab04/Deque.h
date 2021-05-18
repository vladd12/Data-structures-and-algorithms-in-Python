#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <vector>

// Класс для дека
template <class Type> class MyDeque {
// Защищённые члены классы
protected:
	unsigned int size;
	std::vector<Type> deque;

// Публичные члены класса
public:
	// Конструктор класса
	MyDeque() {
		this->size = 0;
	}

	// Метод для проверки содержимого дека
	bool isEmpty() {
		return (deque.size() == 0);
	}

	// Метод для очистки дека
	void clear() {
		deque.clear();
		this->size = 0;
	}

	// Метод возвращает количество элементов в деке
	unsigned int getSize() {
		return this->size;
	}

	// Метод добавления элемента в начало дека
	void pushFront(Type element) {
		if (this->size == 0) this->deque.push_back(element);
		else this->deque.insert(this->deque.begin(), element);
		this->size += 1;
	}

	// Метод удаления эелеента из начала дека
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

	// Метод добавления элемента в конец дека
	void pushBack(Type element) {
		deque.push_back(element);
		this->size += 1;
	}

	// Метод считывания и удаления элемента из конца дека
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

	// Метод для вывода элементов дека в консоль
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
