#ifndef GETTIME_H
#define GETTIME_H

#include <ctime>

// Функция для подсчёта времени выполнения участка кода (в секундах)
double getTime(clock_t start, clock_t end) {
	return (end - start) / 1000.0f;
}


#endif GETTIME_H
