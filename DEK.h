#pragma once
struct dk {
	int n = 0;
	dk *next = 0;
};


class DEK //двусторонняя очередь
{
private:
	dk* dk1;
	int cnt;
public:
	DEK(int count);
	~DEK();
	void ADD_R();
	void ADD_L();
	void show();
	DEK& operator + (int a2);
	DEK& operator = (DEK& a2);
	DEK& operator * (int a2); //число полсе знака
	DEK& operator += (int a2);
	DEK& operator *= (int a2);

	bool operator == (DEK& a2);
	bool operator != (DEK& a2);

	friend DEK& operator+(int x, DEK& y);//число до знака
	friend DEK& operator*(int x, DEK& y);
};

