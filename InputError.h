#pragma once

#include <iostream>
#include <string>
#include "MyException.h"
using namespace std; 

namespace Error {
	class InputError : public MyException {
	public:
		InputError(int code = 0) : MyException(code) {};

		void ErrorText() override;
		static int Input(int min, int max);
		static int InputNumber();
		static char* inputStringWithoutNumbers();
	};
}

void InputError::ErrorText() 
{
	cout << "������ ����� (��� " << code << "): ";
	switch (this->code)
	{
	case 1:
	{
		cout << "����� ������������ ������." << endl;
		cout << "���� ����� ��������, ����� ����, ��������." << endl;
		break;
	}
	case 2:
	{
		cout << "�� ����� ������� ������ ����� ���� �������� ������ �� ����� �����!" << endl;
		break;
	}
	default:
		cout << "��������� ����" << endl;
		break;
	}
}
int InputError::Input(int min, int max)
{
	bool flag = true;
	int value;
	do
	{
		try
		{
			rewind(stdin);
			cin >> value;
			flag = true;
			if (!cin || cin.peek() != '\n')
			{
				flag = false;
				throw InputError(2);
			}
			if (value<min || value>max)
			{
				flag = false;
				throw "Limit error";
			}
		}
		catch (InputError e)
		{
			rewind(stdin);
			e.ErrorText();
		}
		catch (...)
		{
			rewind(stdin);
			cout << "������� ������������ ��������. ���������� ������ �������� � ��������� (" << min << "," << max << ")." << endl;
		}
	} while (!flag);
	return value;
}
int InputError::InputNumber()
{
	int input;
	try
	{
		rewind(stdin);
		cin >> input;
		if (!cin || cin.peek() != '\n')
		{
			throw InputError(2);
		}
	}
	catch (InputError e)
	{
		e.ErrorText();
		rewind(stdin);
		input = InputNumber();
	}
	rewind(stdin);
	return input;
}
char* InputError::inputStringWithoutNumbers()
{
	rewind(stdin);
	char input;
	char* buffer = new char[20];
	int i = 0;
	bool flag = true;
	while (flag) {
		try {
			input = cin.get();
			if (input != '\n' && (input < 'a' || input > 'z') && (input < 'A' || input > 'Z')) {
				throw (InputError(4));
			}
			if (input == '\n') {
				input = '\0';
				flag = false;
			}
			buffer[i] = input;
			i++;
		}
		catch (InputError e)
		{
			rewind(stdin);
			e.ErrorText();
		}
	}
	return buffer;
}
