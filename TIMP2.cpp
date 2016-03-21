// TIMP2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <clocale>
#include <string>
using namespace std;


int markstart=0;
int markend=0;
char start[] = "/**";
int num=1;
void output(char str[256])
{
	char outstr[256];
	char outbuf[256];
	int p=256;
	if (strstr(str, "/**") != NULL)
	{
		markstart = 1;//определяем наличие символа начала мнострочного блока
		markend = 0;
	}
	if ((markstart == 1) && (markend == 0)) //если в блоке
	{		
		if (strstr(str, "\\func") != NULL) //то проверяем наличие тега \func если встретился тег 
		{
			
			for (int j = 0; j < 256; j++)
			{
				outbuf[j] = *(strstr(str, "func") + 5 + j);
			}
			p = strcspn( outbuf, ")");
			for (int j = p+1; j < 256; j++)
			{
				outbuf[j] = 0;
			}
			cout << num << ". " << outbuf  << endl;//выводим описание функции
			num++;
		}
	}//иначе следующая строка
	if (strstr(str, "*/") != NULL)
	{
		markend = 1;//определяем наличие символа конца многострочного блока
	}
}





int _tmain(int argc, _TCHAR* argv[])
{
	char path[256];
	char bufferstr[256];
	setlocale(LC_CTYPE, "rus");
	fstream finput;
	cout << "Введит название файла для документирования" << endl;
	cin >> path;
	finput.open(path,ios::in);
	if (finput.is_open())
	{
		while (!finput.eof())
		{
			finput.getline(bufferstr, 256);
			output(bufferstr);//cout << bufferstr << endl;
		}
	}
	system("pause");
	finput.close();
	return 0;
}

