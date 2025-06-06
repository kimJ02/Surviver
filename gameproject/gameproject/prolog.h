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
		cout << "프롤로그: 프로젝트의 시작" << endl;
		cout << "이름을 입력하세요 : ";
		getline(cin, name);
		system("cls");

		cout << "어… 나 지금 뭘 해야 하지? " << endl;
		cout << "나는 대학교 3학년 " << name << "," << endl;
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
