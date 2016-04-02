// queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;


struct Node //�������� ���� ������
{
	int data; //�������������� ����
	Node *next; //��������� �� ��������� �������
};
struct Queue //�������� �������
{
	int size; //������� ������� �������
	Node *first; //��������� �� ������ �������
	Node *last; //��������� �� ����� �������
};

void Creation(Queue *Q) //�������� �������
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
	Q->size = 0;
}

int Top(Queue *Q) //����� ���������� ��������
{
	return Q->first->next->data;
}

void Add(Queue *Q, int newvalue) //���������� ��������
{
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = newvalue; //���������� �������� � �����
	Q->last->next = NULL; //��������� ��������� �� ��������� �������
	Q->size++;
}


void Delete(Queue *Q) //�������� ��������
{
	Q->first = Q->first->next; //�������� ���������
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
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	cout << "������� :" << endl;
	cout << "���� :" << endl;
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
	cout << "����� :" << endl;
	for (int i = 0; i < k; i++)
		cout << exit[i] << endl;
	system("pause");
	return 0;
	return 0;
}

