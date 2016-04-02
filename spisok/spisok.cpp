// spisok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
struct List
{
	int value;
	List *pNext;
	List *pPrev;
};
List *head; //указатель на первый элемент списка

void addpos(int newvalue, int position)//новое значение и позиция символа
{
	List  *node = new List; //новый узел списка
	node->value = newvalue;//писвоили новое значение
	if ((head == NULL))
	{
		node->pNext = node; //установка указателя next
		node->pPrev =  node;
		head = node; //определяется голова списка
	}
	else 
	{
		List *p = head;
		for (int i = position; i > 0; i--)
		{
			p = p->pNext;
		}
		p->pPrev->pNext = node;
		node->pPrev = p->pPrev;
		node->pNext = p; //добавление элемента
		p->pPrev = node;
	}
}

int DeleteList(int position)
{
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	if ( head->pNext == head) //если это последний элемент в списке
	{
		delete head; //удаление элемента
		head = NULL;
	}
	else
	{
		List *a = head;
		for (int i = position; i>0; i--) a = a->pNext;
		if (a == head) head = a->pNext;
		a->pPrev->pNext = a->pNext; //удаление элемента
		a->pNext->pPrev = a->pPrev;
		delete a;
	}
}

int Get(int position)
{
	int ch;
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	else
	{
		List *a = head;
		for (int i = position; i > 0; i--) a = a->pNext;
		ch = a->value;
	}
	return ch;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int numact, pos, val;
	int k = 0;
	int exit[20];
	char str[64];
	char *act=new char[64];
	char strvyvod[256];
	char path[256];
	char bufferstr[256];
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	cout << "список :" << endl;
	cout << "вход :" << endl;
	fstream finput;
	finput.open("spisok.txt", ios::in);
	if (finput.is_open())
	{
		finput.getline(str, 64);
		cout << str << endl;
		numact = atoi(str);
		for (int i = 0; i < numact; i++)
	    {
		   finput.getline(str, 64);
		   cout << str << endl;
		   act = strtok(str, " ");
		   if (!strcmp(act, "add"))
		   {
			   pos = atoi(strtok(NULL, " "));
			   val = atoi(strtok(NULL, " "));
			   addpos(val, pos);
		   }
		   if (!strcmp(act, "del"))
		   {
			    pos = atoi(strtok(NULL, " "));
			    DeleteList(pos);
		   }
		   if (!strcmp(act, "get"))
		   {
			    pos = atoi(strtok(NULL, " "));
			    exit[k]=Get(pos);
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

