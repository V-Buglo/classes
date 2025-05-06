#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Counter {
private:
	int i_;

public:
	//конструкторы
	Counter() { i_ = 1; }
	Counter(int i) { i_ = i; }
	Counter(Counter& C) { i_ = C.i_; }

	void increment() { i_++; }
	void decrement() { i_--; }
	void print() { cout << "Счётчик: " << i_ << endl; }
};

int main() {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Counter counter;

	string change;
	cout << "Вы хотите указать начальное значение счётчика? Введите да, если так: ";
	cin >> change;
	transform(change.begin(), change.end(), change.begin(), ::tolower);
	int value = 1;

	if (change== "да")
	{
		cout << "Введите начальное  значение счётчика: ";
		cin >> value;
		counter = Counter(value);
	}

	while (true) {
		char changeComand;
		cout << "'+' - прибавить на 1 ; '-' - убавить на 1; '=' - вывод счетчика; 'x' - выйти из программы;" << endl;
		cout << "Введите команду: ";
		
		cin >> changeComand;
		changeComand = (char) tolower(changeComand);

		if (changeComand == 'x' or changeComand == 'х')
			break;

		switch (changeComand)
		{
		case '+': counter.increment(); break;
		case '-': counter.decrement(); break;
		case '=': counter.print(); break;
		default:
			cout << "Некорректный ввод!" << endl;
			break;
		}

		cin.ignore();

	}

	return 0;
}