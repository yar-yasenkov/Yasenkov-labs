// queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;


struct Node //описание узла списка
{
	int data; //информационное поле
	Node *next; //указатель на следующий элемент
};
struct Queue //описание очереди
{
	int size; //счетчик размера очереди
	Node *first; //указатель на начало очереди
	Node *last; //указатель на конец очереди
};

void Creation(Queue *Q) //создание очереди
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
	Q->size = 0;
}

int Top(Queue *Q) //вывод начального элемента
{
	return Q->first->next->data;
}

void Add(Queue *Q, int newvalue) //добавление элемента
{
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = newvalue; //добавление элемента в конец
	Q->last->next = NULL; //обнуление указателя на следующий элемент
	Q->size++;
}


void Delete(Queue *Q) //удаление элемента
{
	Q->first = Q->first->next; //смещение указателя
	Q->size--;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int numact, val;
	int k = 0;
	int exit[20];
	char str[64];
	char *act = new char[64];
	char strvyvod[256];
	Queue Q;
	Creation(&Q);
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	cout << "очередь :" << endl;
	cout << "вход :" << endl;
	fstream finput;
	finput.open("queue.txt", ios::in);
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
				val = atoi(strtok(NULL, " "));
				Add(&Q, val);
			}
			if (!strcmp(str, "del"))
			{
				Delete(&Q);
			}
			if (!strcmp(str, "get"))
			{
				exit[k] = Top(&Q);
				k++;
			}
		}
	}
	cout << "выход :" << endl;
	for (int i = 0; i < k; i++)
		cout << exit[i] << endl;
	system("pause");
	return 0;
	return 0;
}

