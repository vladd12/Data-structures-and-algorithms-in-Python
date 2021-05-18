#ifndef GETTIME_H
#define GETTIME_H

#include <time.h>

// Функция для подсчёта времени выполнения участка кода (в секундах)
double getTime(clock_t start, clock_t end) {
	return (end - start) / 1000.0f;
}


#endif GETTIME_H
