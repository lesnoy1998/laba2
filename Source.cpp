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
		cout << "������� ����� ������� (1 - �������, 2 - ��������)\n";
		int n;
		cin >> n;
		if (n == 1) //�������
		{
			XTIMEX tmp;
			while (1)
			{
				int n2 = -99;
				if (n2 != -99) { cout << "\n������ ������� ������ �����. ��������� �������� �����, �����, ������ ������������� ��������������:\n"; }
				else { cout << "\n���������:\n"; }
				tmp.printt();
				cout << "\n��� �� ������ �������\n1 - ���������� ����������������� (��������� �� ��� �������)\n2 - ����������� ����������������� (� ������� ����)\n3 - ���������� ����������������� (��������� ��  ���� �������)\n4 - ����������� ����������������� (����� ����, ����� ��������)\n";
				cin >> n2;
				if (n2 == 1)
				{
					++tmp;
				}
				else if (n2 == 2)
				{
					cout << "��� �� ������ ���������: \n1 - ����\n2 - ������\n3 - �������\n";
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
					cout << "��� �� ������ ���������: \n1 - ����\n2 - ������\n3 - �������\n";
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
					cout << "�� ������� ������ ���������:\n";
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
		else if (n == 2) //��������
		{
			cout << "\n������� ������ ����\n";
			int n2 = -99;
			int dd;
			cin >> dd;
			if (dd <= 0 || dd > 50) { continue; }
			DEK dek1(dd);
			n2 = -99;
			while (1)
			{
				if (n2 == -99) { cout << "\n������ ������� ������ ���. ��������� �������� ������������� ��������������:\n"; } else { cout << "���������:\n"; }
				dek1.show();
				cout << "��� �� ������ �������?\n1 - �������� ��������\n2 - �������� ���������\n3 - += (�������� ������� � ���)\n4 - *= (��������� �������� �� ����� �����)\n5 - ������� ����� ���, ��������� ��� ������ � �������� �� ������������\n6 - ������� ����� ���(�� ����������) � �������� �� ������\n";
				cin >> n2;
				if (n2 == 1)
				{
					cout << "\n�������� � ������ ��� � ����� �������?\n1-������\n2-�����\n";
					cin >> n2;
					int tmp;
					cout << "������� ��������?\n";
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
					cout << "\n�������� ��� �������� ������� ��� ������ ���������?\n1-���\n2-�����\n";
					cin >> n2;
					int tmp;
					cout << "�� ������� ��������?\n";
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
					cout << "\n������� �������� ������������ ��������\n";
					cin >> n2;
					dek1 += n2;
				}
				else if (n2 == 4)
				{
					cout << "\n������� ��������\n";
					cin >> n2;
					dek1 *= n2;
				}
				else if (n2 == 5)
				{
					DEK dek2(dd);
					dek2 = dek1;
					cout << "\n��� ���� ���������: \n";
					dek1.show();
					cout << "\n��������� ��������� : " << (dek1 == dek2) << "\n";
					
				}
				else if (n2 == 6)
				{
					DEK dek2(dd);
					cout << "\n��� ������: \n";
					dek2.show();
					cout << "\n��� ������: \n";
					dek1.show();
					cout << "\n��� �����������? ���������: " << (dek1 != dek2) << "\n";
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