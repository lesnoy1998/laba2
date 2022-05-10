#pragma once
class XTIMEX
{
private:
	int hours;
	int minutes;
	int seconds;

	int* tmp = 0;
	int user_set = 0;
public:
	XTIMEX();
	~XTIMEX();
	void printt();
	void setH();
	void setM();
	void setS();
	void setUserSet(int a);
	XTIMEX& operator ++ (); //префикс
	XTIMEX& operator ++ (int); //постфикс

	XTIMEX& operator -- (); //префикс
	XTIMEX& operator -- (int); //постфикс
};

void sort(int *h, int *m, int *s);