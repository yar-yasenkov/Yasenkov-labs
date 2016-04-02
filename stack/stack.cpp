// stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;



struct stack
{
	int value;
	struct stack *next;
};

stack *sp;


void push(int newvalue)
{
	stack *node= new stack;
	if (sp == NULL)
	{
		node->value = newvalue;
		node->next = NULL;
		sp = node;
	}
	else
	{
		node->value = newvalue;
		node->next = sp;
		sp = node;
	}
}

int gettop()
{
	return sp->value;
}

void pop()
{
	if (sp == NULL)
	{
		cout << "стек пустой" << endl;
	}
	else
	{
		sp = sp->next;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int numact, val;
	int k = 0;
	int exit[20];
	char str[64];
	char *act = new char[64];
	char strvyvod[256];
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	cout << "стек :" << endl;
	cout << "вход :" << endl;
	fstream finput;
	finput.open("stack.txt", ios::in);
	if (finput.is_open())
	{
		finput.getline(str, 64);
		cout << str << endl;;
		numact = atoi(str);
		for (int i = 0; i < numact; i++)
		{
			finput.getline(str, 64);
			cout << str << endl;
			act = strtok(str, " ");
			if (!strcmp(act, "add"))
			{
				val = atoi(strtok(NULL, " "));
				push(val);
			}
			if (!strcmp(str, "del"))
			{
				pop();
			}
			if (!strcmp(str, "get"))
			{
				exit[k] = gettop();
				k++;
			}
		}
	}
	cout << "выход :" << endl;
	for (int i = 0; i < k; i++)
		cout << exit[i] << endl;
	system("pause");
	return 0;
}


