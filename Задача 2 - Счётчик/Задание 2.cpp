#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Counter {
private:
	int i_;

public:
	//������������
	Counter() { i_ = 1; }
	Counter(int i) { i_ = i; }
	Counter(Counter& C) { i_ = C.i_; }

	void increment() { i_++; }
	void decrement() { i_--; }
	void print() { cout << "�������: " << i_ << endl; }
};

int main() {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Counter counter;

	string change;
	cout << "�� ������ ������� ��������� �������� ��������? ������� ��, ���� ���: ";
	cin >> change;
	transform(change.begin(), change.end(), change.begin(), ::tolower);
	int value = 1;

	if (change== "��")
	{
		cout << "������� ���������  �������� ��������: ";
		cin >> value;
		counter = Counter(value);
	}

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