#include <iostream>
#include <Windows.h>

using namespace std;

class Calculator {
	double __num1;
	double __num2;

	double add() {
		return __num1 + __num2;
	}

	double multiply(){
		return __num1 * __num2;
	}

	double subtract_1_2(){
		return __num1 - __num2;
	}

	double subtract_2_1(){
		return __num2 - __num1;
	}

	double divide_1_2(){
		return __num1 / __num2;
	}

	double divide_2_1(){
		return  __num2 / __num1;
	}

public:
	bool set_num1(double num1){
		if (num1 == 0)
			return false;
		
		__num1 = num1;

		return true;
	}
	bool set_num2(double num2){
		if (num2 == 0)
			return false;

		__num2 = num2;

		return true;
	}
	
	void get_perform_arithmetic(){
		cout << "num1 + num2 = " << add()<<endl;
		cout << "num1 * num2 = " << multiply() << endl;;
		cout << "num1 - num2 = " << subtract_1_2() << endl;;
		cout << "num2 - num1 = " << subtract_2_1() << endl;;
		cout << "num1 / num2 = " << divide_1_2() << endl;;
		cout << "num2 / num1 = " << divide_2_1() << endl;;
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

		if (num1 && num2)
			myNumbers.get_perform_arithmetic();
		else
		{
			cout << "Некорретный ввод" << endl;
		}

	}

	return 0;

}