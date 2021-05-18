#ifndef GETRANDNUM_H
#define GETRANDNUM_H

#include <random>

// Функция получения случайного числа в заданном диапазоне
int getRandNum(int start, int end) {
	std::random_device random_device; // Источник энтропии.
	// Генератор случайных чисел. (Здесь берется одно инициализирующее значение, можно брать больше)
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(start, end); // Равномерное распределение [start, end]
	int x = distribution(generator); // Случайное число
	return x;
}

#endif GETRANDNUM_H
