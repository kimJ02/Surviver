#pragma once
#include <iostream>
#include <string>
#include "FileIO.h"
using namespace std;

class prolog
{
public:
	string name;
	string enter;
	void print_prolog()
	{
		cout << "���ѷα�: ������Ʈ�� ����" << endl;
		cout << "�̸��� �Է��ϼ��� : ";
		getline(cin, name);
		system("cls");

		cout << "� �� ���� �� �ؾ� ����? " << endl;
		cout << "���� ���б� 3�г� " << name << "," << endl;
		FileIO::printFile("Story/prolog1.txt");

		cout << " ENTER ";
		getline(cin, enter);
		if (enter.empty())
		{
			system("cls");
		}

		FileIO::printFile("Story/prolog2.txt");

		cout << " ENTER ";
		getline(cin, enter);
		if (enter.empty())
		{
			system("cls");
		}

	};

};
