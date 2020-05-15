/* Напишите программу, которая запрашивает у пользователя номер месяца и затем выводит соответствующее название времени года. 
   В случае, если пользователь введёт недопустимое число, программа должна вывести сообщение об ошибке.
*/
#include <iostream>
#include <Windows.h> // для кириллицы

using std::cout; using std::cin; using std::endl;

// перечисление месяцев
enum Months
{
	Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec  
};

Months numberRequest() // запрос у пользователя номера месяца
{
	cout << "Введите номер месяца (число от 1 до 12): ";
	int one_number = 0;        // переменная для значения

	cin >> one_number;
	while (cin.fail() || (one_number <= 0) || (one_number > 12) ) // если вводит буквы или не номера месяцев
	{
		cin.clear();
		cin.ignore(1000, '\n'); //очищаем cin
		cout << "Вы ввели нечто некорректное, введите число от 1 до 12: ";
		cin >> one_number;      //снова вводит число
		continue;
	}
	
	return static_cast<Months>(one_number); // возвращаем последнее нормально введённое число
}

// печать сезона по месяцу
void Season(const Months& m)
{
	cout << endl << "Это "; 
	switch (m)                       
	{
		case Jan:
		case Feb:
		case Dec:
			cout << "зима" << endl;
			break;
		case Mar:
		case Apr:
		case May:
			cout << "весна" << endl;
			break;
		case Jun:
		case Jul:
		case Aug:
			cout << "лето" << endl;
			break;
		case Sep:
		case Oct:
		case Nov:
			cout << "осень" << endl;
			break;
		default:
			cout << "пятый сезон" << endl;
			break;
	};
}

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251); // для ввода-вывода на кириллице

	// запрашиваем у пользователя номер месяца
	Months month = numberRequest();

	// определяем по номеру месяца сезон
	Season(month);

	return 0;
}