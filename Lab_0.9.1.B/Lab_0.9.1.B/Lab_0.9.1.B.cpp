
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Specialnist { KN, IT, MATH, PHYSIC, WORK };
enum Curs { FIRST, SECOND, THIRD, FOUR };
string cursStr[] = { "I", "II", "III", "IV" };
string specialnistStr[] = { "Комп науки", "Інформатика", "Мат та ек", "Фіз та інформ", "Труд навч" };
struct Student
{
	string prizv;
	Curs curs;
	Specialnist specialnist;
	struct
	{
		int physic;
		int math;

	};
	union
	{
		int IT;
		int nummet;
		int pedagog;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
//int Students(Student* p, const int N);
int Search5(Student* p, const int N);
int Search4(Student* p, const int N);
int Search3(Student* p, const int N);
double LineSearch(Student* p, const int N);
int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	cout << "Кількість оцінок '5' з програмування: " << Search5(p, N) << endl;
	cout << "Кількість оцінок '4' з програмування: " << Search4(p, N) << endl;
	cout << "Кількість оцінок '3' з програмування: " << Search3(p, N) << endl;
	cout << "Процент студентів, які отримали і з фізики і з математики оцінки «4» або «5».: " << LineSearch(p, N) << "%" << endl;
	return 0;
}
void Create(Student* p, const int N)
{
	int specialnist;
	int curs;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс (0 - I, 1 - II, 2 - III, 3 - IV): ";
		cin >> curs;
		cout << " спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialnist;
		cout << " оцінка з фізики : "; cin >> p[i].physic;
		cout << " оцінка з математики : "; cin >> p[i].math;
		p[i].specialnist = (Specialnist)specialnist;
		p[i].curs = (Curs)curs;
		switch (p[i].specialnist)
		{
		case KN:
			cout << " оцінка з програмування : "; cin >> p[i].IT;
			break;
		case IT:
			cout << " оцінка з чисельних методів : "; cin >> p[i].nummet;
			break;
		case MATH:
		case PHYSIC:
		case WORK:
			cout << " оцінка з педагогіки : "; cin >> p[i].pedagog;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "==========================================================================================================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з програмування | Оцінка з чисельних методів | Оцінка з педагогіки |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << i + 1;
		cout << "| " << setw(9) << p[i].prizv;
		cout << "| " << setw(5) << cursStr[p[i].curs];
		cout << "| " << setw(14) << specialnistStr[p[i].specialnist];
		cout << "| " << setw(16) << p[i].physic;
		cout << "| " << setw(20) << p[i].math;
		switch (p[i].specialnist)
		{
		case KN:
			cout << "| " << setw(23) << p[i].IT << "|" << setw(29) << "|" << setw(22) << "|";
			break;
		case IT:
			cout << "| " << setw(24) << "|" << setw(28) << p[i].nummet << "|" << setw(22) << "|";
			break;
		case MATH:
		case PHYSIC:
		case WORK:
			cout << "| " << setw(24) << "|" << setw(29) << "|" << setw(21) << p[i].pedagog << "|";
			break;
		}
		cout << endl;
	}
	cout << "==========================================================================================================================================================="
		<< endl;
	cout << endl;
}
int Search5(Student* p, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].specialnist == KN) {
			if (p[i].IT == 5) {
				k++;
			}
		}
	}
	return k;
}
int Search4(Student* p, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].specialnist == KN) {
			if (p[i].IT == 4) {
				k++;
			}
		}
	}
	return k;
}
int Search3(Student* p, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].specialnist == KN) {
			if (p[i].IT == 3) {
				k++;
			}
		}
	}
	return k;
}
double LineSearch(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].specialnist == KN || p[i].specialnist == IT || p[i].specialnist == MATH || p[i].specialnist == PHYSIC || p[i].specialnist == WORK) {
			n++;
			if ((p[i].physic == 5 && p[i].math == 5) || (p[i].physic == 4 && p[i].math == 4) || ((p[i].physic == 4 && p[i].math == 5)) || ((p[i].physic == 5 && p[i].math == 4))) {
				k++;
			}
		}
	}
	return 100.0 * k / n;
}
