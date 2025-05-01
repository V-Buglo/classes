#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Counter {
	int __i;

public:
	//������������
	Counter() { __i = 1; }
	Counter(int i) { __i = i; }
	Counter(Counter& C) { __i = C.__i; }

	void increment() { __i++; }
	void decrement() { __i--; }
	void print() { cout << "�������: " << __i << endl; }
};

int main() {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string change;
	cout << "�� ������ ������� ��������� �������� ��������? ������� ��, ���� ���: ";
	cin >> change;
	transform(change.begin(), change.end(), change.begin(), ::tolower);
	int value = 1;

	// � ��� ������� �� ������ ��� ������������� �������: 
	// ��� ��� � ������ ������� (if) ������� ������ ������ ������������� (� ��� ��������� ��� �� �������), 
	// ����� ��� ���� ��� ����������� ��� ����������� ������� (if)
	// � ������ ��� ����� � ����������� ����� (while) 
	if (change== "��")
	{
		cout << "������� ���������  �������� ��������: ";
		cin >> value;
	}

	Counter counter(value);

	while (true) {
		char changeComand;
		cout << "'+' - ��������� �� 1 ; '-' - ������� �� 1; '=' - ����� ��������; 'x' - ����� �� ���������;" << endl;
		cout << "������� �������: ";
		
		cin >> changeComand;
		changeComand = (char) tolower(changeComand);

		if (changeComand == 'x' or changeComand == '�')
			break;

		switch (changeComand)
		{
		case '+': counter.increment(); break;
		case '-': counter.decrement(); break;
		case '=': counter.print(); break;
		default:
			cout << "������������ ����!" << endl;
			break;
		}

		cin.ignore();

	}

	return 0;
}