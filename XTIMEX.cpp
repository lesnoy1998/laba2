#include "XTIMEX.h"
#include <iostream>
#include <ctime>


XTIMEX::XTIMEX()
{
	srand(time(0));
	hours = 0 + rand() % 24;
	minutes = 0 + rand() % 60;
	seconds = 0 + rand() % 60;
}

XTIMEX::~XTIMEX()
{
	//srand(time(0));
	hours = 0;
	minutes = 0;
	seconds = 0;
}

void XTIMEX::printt()
{
	std::cout << hours << ":" << minutes << ":" << seconds << "\n";
}

XTIMEX& XTIMEX::operator ++ () //увеличение всех на минимальную разницу
{
	int arr[3] = { hours, minutes, seconds };
	int min = 61;
	int tmp1;
	for (int i = 0; i < 3; i++)
	{
		if (i != 2) { tmp1 = i + 1; }
		else { tmp1 = 0; }

		if (abs(arr[i] - arr[tmp1]) <= min) { min = abs(arr[i] - arr[tmp1]); }
	}
	std::cout << "\n\n VIBRANO CHISLO " << min << "\n\n";
	minutes += min;
	hours += min;
	seconds += min;
	//printt();
	sort(&hours, &minutes, &seconds);
	return *this;
}

XTIMEX& XTIMEX::operator ++ (int) // увеличение выбранного
{
	int arr[3] = { hours, minutes, seconds };
	int max = -1;
	for (int i = 0; i < 3; i++)
	{
		if (abs(arr[i]) >= max) { max = abs(arr[i]); }
	}
	std::cout << "\n\n VIBRANO CHISLO " << max << "\n\n";

	*tmp += max;
	tmp = 0;

	sort(&hours, &minutes, &seconds);
	return *this;
}

XTIMEX& XTIMEX::operator -- () //уменьшаем всех на наибольшую разницу
{
	int arr[3] = { hours, minutes, seconds };
	int min = -1;
	int tmp1;
	for (int i = 0; i < 3; i++)
	{
		if (i != 2) { tmp1 = i + 1; }
		else { tmp1 = 0; }

		if (abs(arr[i] - arr[tmp1]) >= min) { min = abs(arr[i] - arr[tmp1]); }
	}
	std::cout << "\n\n VIBRANO CHISLO " << min << "\n\n";
	minutes -= min;
	hours -= min;
	seconds -= min;
	//printt();
	sort(&hours, &minutes, &seconds);
	return *this;

}

XTIMEX& XTIMEX::operator -- (int) //уменьшаем выбранное на выбранное
{
	*tmp -= user_set;
	tmp = 0;
	user_set = 0;

	sort(&hours, &minutes, &seconds);
	return *this;
}

void sort(int *h, int *m, int *s)
{
	while (1)
	{
		if (*m > 59) { (*h)++; (*m) -= 60; }
		else if (*s > 59) { (*m)++; (*s) -= 60; }
		else if (*h < 0) { *h = 0; *m = 0; *s = 0; }
		else if (*m < 0) { *m = 0; *s = 0; }
		else if (*s < 0) { *s = 0; }
		else { break; }
	}
	return;
}




void XTIMEX::setH()
{
	tmp = &hours;
}
void XTIMEX::setM()
{
	tmp = &minutes;
}
void XTIMEX::setS()
{
	tmp = &seconds;
}


void XTIMEX::setUserSet(int a)
{
	user_set = a;
}