#include <iostream>
#include <locale.h>
#include "XTIMEX.h"
#include "DEK.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	while (1)
	{
		cout << "Введите номер задания (1 - унарное, 2 - бинарное)\n";
		int n;
		cin >> n;
		if (n == 1) //унарные
		{
			XTIMEX tmp;
			while (1)
			{
				int n2 = -99;
				if (n2 != -99) { cout << "\nСоздан элемент класса ВРЕМЯ. Случайные значения часов, минут, секунд сгенерированы соответственно:\n"; }
				else { cout << "\nРезультат:\n"; }
				tmp.printt();
				cout << "\nЧто вы хотите сделать\n1 - Префиксное инкрементирование (увеличить на мин разницу)\n2 - Постфиксное инкрементирование (с выбором поля)\n3 - Префиксное декрементирование (уменьшить на  макс разницу)\n4 - Постфиксное декрементирование (выбор поля, выбор значения)\n";
				cin >> n2;
				if (n2 == 1)
				{
					++tmp;
				}
				else if (n2 == 2)
				{
					cout << "Что вы хотите увеличить: \n1 - часы\n2 - минуты\n3 - секунды\n";
					int n3;
					cin >> n3;
					switch (n3)
					{
					case 1: tmp.setH(); break;
					case 2: tmp.setM(); break;
					case 3: tmp.setS(); break;
					default:
						continue;
					}
					tmp++;
				}
				else if (n2 == 3)
				{
					--tmp;
				}
				else if (n2 == 4)
				{
					cout << "Что вы хотите уменьшить: \n1 - часы\n2 - минуты\n3 - секунды\n";
					int n3;
					cin >> n3;
					switch (n3)
					{
					case 1: tmp.setH(); break;
					case 2: tmp.setM(); break;
					case 3: tmp.setS(); break;
					default:
						continue;
					}
					cout << "На сколько хотите уменьшить:\n";
					cin >> n3;
					tmp.setUserSet(n3);
					tmp--;
				}
				else
				{
					break;
				}
			}
		
		}
		else if (n == 2) //бинарные
		{
			cout << "\nУкажите размер ДЕКа\n";
			int n2 = -99;
			int dd;
			cin >> dd;
			if (dd <= 0 || dd > 50) { continue; }
			DEK dek1(dd);
			n2 = -99;
			while (1)
			{
				if (n2 == -99) { cout << "\nСоздан элемент класса ДЕК. Случайные значения сгенерированы соответственно:\n"; } else { cout << "Результат:\n"; }
				dek1.show();
				cout << "Что вы хотите сделать?\n1 - Оператор сложения\n2 - Оператор умножения\n3 - += (добавить элемент в дек)\n4 - *= (умножение верхушки на польз число)\n5 - создать новый дек, присвоить ему старый и сравнить на идентичность\n6 - создать новый дек(не идентичный) и сравнить со старым\n";
				cin >> n2;
				if (n2 == 1)
				{
					cout << "\nДобавить к началу или к концу очереди?\n1-начало\n2-конец\n";
					cin >> n2;
					int tmp;
					cout << "Сколько добавить?\n";
					cin >> tmp;
					switch (n2)
					{
					case 1: dek1 = dek1 + tmp; break;
					case 2: dek1 = tmp + dek1; break;
					default:
						break;
					}
				}
				else if (n2 == 2)
				{
					cout << "\nУмножить все элементы очереди или только последний?\n1-все\n2-конец\n";
					cin >> n2;
					int tmp;
					cout << "На сколько умножить?\n";
					cin >> tmp;
					switch (n2)
					{
					case 1: dek1 = dek1 * tmp; break;
					case 2: dek1 = tmp * dek1; break;
					default:
						break;
					}
				}
				else if (n2 == 3)
				{
					cout << "\nВведите значение добавляемого элемента\n";
					cin >> n2;
					dek1 += n2;
				}
				else if (n2 == 4)
				{
					cout << "\nВведите значение\n";
					cin >> n2;
					dek1 *= n2;
				}
				else if (n2 == 5)
				{
					DEK dek2(dd);
					dek2 = dek1;
					cout << "\nОба дека идентичны: \n";
					dek1.show();
					cout << "\nРезультат сравнения : " << (dek1 == dek2) << "\n";
					
				}
				else if (n2 == 6)
				{
					DEK dek2(dd);
					cout << "\nБыл создан: \n";
					dek2.show();
					cout << "\nНаш старый: \n";
					dek1.show();
					cout << "\nОни неидентичны? Результат: " << (dek1 != dek2) << "\n";
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
	
}