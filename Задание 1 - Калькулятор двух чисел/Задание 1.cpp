#include <iostream>
#include <Windows.h>

using namespace std;

class Calculator {

private:
	double num1;
	double num2;

public:
	double add() {
		return num1 + num2;
	}

	double multiply() {
		return num1 * num2;
	}

	double subtract_1_2() {
		return num1 - num2;
	}

	double subtract_2_1() {
		return num2 - num1;
	}

	double divide_1_2() {
		return num1 / num2;
	}

	double divide_2_1() {
		return  num2 / num1;
	}

	bool set_num1(double valuenum1) {
		if (valuenum1 == 0)
			return false;

		num1 = valuenum1;

		return true;
	}

	bool set_num2(double valuenum2) {
		if (valuenum2 == 0)
			return false;

		num2 = valuenum2;

		return true;
	}

};


int main() {

	setlocale(LC_ALL, "rus");

	while (true) {

		Calculator myNumbers;
		double i;
		bool num1, num2;

		cout << "Введите num1(<>0): ";
		cin >> i;
		num1 = myNumbers.set_num1(i);

		cout << "Введите num2(<>0): ";
		cin >> i;
		num2 = myNumbers.set_num2(i);

		if (num1 && num2) {
			cout << "num1 + num2 = " << myNumbers.add() << endl;
			cout << "num1 * num2 = " << myNumbers.multiply() << endl;
			cout << "num1 - num2 = " << myNumbers.subtract_1_2() << endl;
			cout << "num2 - num1 = " << myNumbers.subtract_2_1() << endl;
			cout << "num1 / num2 = " << myNumbers.divide_1_2() << endl;
			cout << "num2 / num1 = " << myNumbers.divide_2_1() << endl;
		}
		else
		{
			cout << "Некорретный ввод" << endl;
		}

	}

	return 0;

}