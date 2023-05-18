#include<iostream>
#include <windows.h>
#include<time.h>
using namespace std;
void bros(int kubik);
int res();

void main()
{
	char brosok;
	do
	{
		setlocale(LC_ALL, "Russian");
		srand(time(NULL));

		cout << "Привет! Сыграем в кубики? Правила очень простые: ";
		cout << "\nПобеждает тот, у кого сумма по итогам пяти бросков больше!";
		cout << "\nПоехали...\n\n";


		int total_chel = 0;
		int total_komp = 0;

		do
		{
			cout << "Разыграем очередность бросков? Нажми * для броска\n";
			cin >> brosok;
		} while (brosok != '*');

		int res_chel, res_komp;
		do
		{
			res_chel = res();
			cout << "Ваш результат: " << res_chel << "\n";
			res_komp = res();
			cout << "\nМой результат: " << res_komp << "\n";
		} while (res_chel == res_komp);

		if (res_chel > res_komp)
		{
			cout << "\nВы начинаете первым :(\n";
			for (int i = 1; i <= 5; i++)
			{
				do
				{
					cout << "Нажми * для броска\n";
					cin >> brosok;
				} while (brosok != '*');
				cout << "Вы:\n";
				total_chel += res();
				cout << "Я:\n";
				total_komp += res();
				cout << "Следующий ход:\n";
			}
			cout << "Ваш общий результат (сумма очков за 5 бросков): " << total_chel << "\n";
			cout << "\nМой общий результат (сумма очков за 5 бросков): " << total_komp << "\n";
		}
		else
		{
			cout << "\nЯ начинаю первым :)\n";
			for (int i = 1; i <= 5; i++)
			{
				cout << "Я:\n";
				total_komp += res();
				do
				{
					cout << "Нажми * для броска\n";
					cin >> brosok;
				} while (brosok != '*');
				cout << "Вы:\n";
				total_chel += res();
				cout << "Следующий ход:\n";
			}
			cout << "Ваш общий результат (сумма очков за 5 бросков): " << total_chel << "\n";
			cout << "\nМой общий результат (сумма очков за 5 бросков): " << total_komp << "\n";
		}

		if (total_chel == total_komp)
		{
			cout << "\n\nНИЧЬЯ!\n\n";
		}
		else
		{
			if (total_chel > total_komp)
			{
				cout << "\n\nВы выиграли!\n\n";
			}
			if (total_chel < total_komp)
			{
				cout << "\n\nЯ выиграл! Я же всё-таки умнее тебя\n\n";
			}
		}
		cout << "\nЕсли хотите продолжить, нажмите *: ";
		cin >> brosok;
	} while (brosok == '*');
}

void bros(int kubik)
{
	switch (kubik)
	{
	case 1:
		cout << "***********\n";
		cout << "*                  *\n";
		cout << "*                  *\n";
		cout << "*        *        *\n";
		cout << "*                  *\n";
		cout << "*                  *\n";
		cout << "***********\n";
		break;
	case 2:
		cout << "***********\n";
		cout << "*                  *\n";
		cout << "*        *        *\n";
		cout << "*                  *\n";
		cout << "*        *        *\n";
		cout << "*                  *\n";
		cout << "***********\n";
		break;
	case 3:
		cout << "***********\n";
		cout << "*                  *\n";
		cout << "*    *            *\n";
		cout << "*        *        *\n";
		cout << "*            *    *\n";
		cout << "*                  *\n";
		cout << "***********\n";
		break;
	case 4:
		cout << "***********\n";
		cout << "*                  *\n";
		cout << "*    *      *    *\n";
		cout << "*                  *\n";
		cout << "*    *      *    *\n";
		cout << "*                  *\n";
		cout << "***********\n";
		break;
	case 5:
		cout << "***********\n";
		cout << "*                  *\n";
		cout << "*    *      *    *\n";
		cout << "*        *        *\n";
		cout << "*    *      *    *\n";
		cout << "*                  *\n";
		cout << "***********\n";
		break;
	case 6:
		cout << "***********\n";
		cout << "*                  *\n";
		cout << "*    *      *    *\n";
		cout << "*    *      *    *\n";
		cout << "*    *      *    *\n";
		cout << "*                  *\n";
		cout << "***********\n";
		break;
	}
}
int res()
{
	int kubik_1 = rand() % 6 + 1;
	bros(kubik_1);
	int kubik_2 = rand() % 6 + 1;
	bros(kubik_2);
	int rezult;
	rezult = kubik_1 + kubik_2;
	cout << "Результат: " << rezult << "\n\n";
	return rezult;
}