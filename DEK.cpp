#include "DEK.h"
#include <ctime>
#include <iostream>

DEK::DEK(int count)
{
	dk1 = new dk[count];
	cnt = count;
	for (int i = 0; i < count; i++)
	{
		dk1[i].n = 15 + rand() % (21 - 15);
		if (i + 1 >= count)
		{
			dk1[i].next = &(dk1[0]);
		}
		else
		{
			dk1[i].next = &(dk1[i + 1]);
		}
	}

}
DEK::~DEK()
{
	delete[] dk1;
}
void DEK::show()
{
	char str[3];
	for (int i = 0; i < cnt; i++)
	{
		if ((dk1[i].n > 9) && (i < 10))
		{
			str[0] = ' ';
			str[1] = ' ';
			str[2] = '\0';
		}
		else
		{
			str[0] = ' ';
			str[1] = '\0';
		}
		std::cout << i << str;
	}
	std::cout << "\n";
	for (int i = 0; i < cnt; i++)
	{
		std::cout << dk1[i].n << " ";
	}
	std::cout << "\n";
}
DEK& DEK::operator + (int a)
{
	dk1[0].n += a;
	return *this;
}

DEK& DEK::operator = (DEK& a2)
{
	DEK tmp(a2.cnt);
	for (int i = 0; i < a2.cnt; i++)
	{
		tmp.dk1[i].n = a2.dk1[i].n;
		tmp.dk1[i].next = a2.dk1[i].next;
	}
	delete[] dk1;
	dk1 = new dk[a2.cnt];
	for (int i = 0; i < a2.cnt; i++)
	{
		dk1[i].n = tmp.dk1[i].n;
		dk1[i].next = tmp.dk1[i].next;
	}
	return *this;
}

DEK& operator +(int x, DEK& y)
{
	y.dk1[y.cnt-1].n += x;
	return y;
}

DEK& DEK::operator * (int a)
{
	for (int i = 0; i < cnt; i++)
	{
		dk1[i].n *= a;
	}
	return *this;
}

DEK& operator *(int x, DEK& y)
{
	y.dk1[y.cnt - 1].n *= x;
	return y;
}



DEK& DEK::operator += (int a2)
{
	int tmp;
	for (int i = cnt-1; i > 0; i--)
	{
		dk1[i].n = dk1[i - 1].n;
	}
	dk1[0].n = a2;
	return *this;
}


DEK& DEK::operator *= (int a2)
{
	dk1[0].n *= a2;
	return *this;
}

bool DEK::operator == (DEK& a2)
{
	if (cnt != a2.cnt)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < cnt; i++)
		{
			if (dk1[i].n != a2.dk1[i].n) { return false; }
		}
	}
	return true;
}

bool DEK::operator != (DEK& a2)
{
	if (*this == a2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
