#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

// Класс для стека
template <class Type> class MyStack {
// Защищённые члены классы
protected:
	unsigned int size;
	std::vector<Type> stack;

// Публичные члены класса
public:
	// Конструктор класса
	MyStack() {
		this->size = 0;
	}

	// Метод для проверки содержимого стека
	bool isEmpty() {
		return (stack.size() == 0);
	}

	// Метод для очистки стека
	void clear() {
		stack.clear();
		this->size = 0;
	}

	// Метод возвращает количество элементов в стеке
	unsigned int getSize() {
		return this->size;
	}

	// Метод добавления элемента в стек
	void push(Type element) {
		stack.push_back(element);
		this->size += 1;
	}

	// Метод возвращает значение с вершины стека
	Type peek() {
		if (this->isEmpty()) {
			std::cout << "Stack is empty! Error!" << std::endl;
			return (Type)0;
		}
		else return stack.back();
	}

	// Метод считывания и удаления элемента из стека
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

	// Метод для вывода элементов стека в консоль
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
