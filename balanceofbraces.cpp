#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE,"rus");
	char nazv[100];// строковой массив в которое собственно говоря будет записываться название файла
	cout << "Введите название файла:";
	cin >> nazv;
	ifstream inpfile(nazv);// открываем файл для чтения
	if(!inpfile.is_open())
		cout << "Файл не может быть открыт";
	else
	{
		int kolotkrck(0);//счетчик количества {
		int kolzakrck(0);//счетчик количества } изначально равный нулю
		char symv;// переменная для считывания символов из входного файла
		inpfile>>symv; // считываем один символ из входного файла
		while(inpfile)
		{
			if(symv=='{')kolotkrck++;
			if(symv=='}')
				{
					kolzakrck++;
					if(kolzakrck!=kolotkrck)break;
			}
			inpfile&gt;&gt;symv;//считываем следующий символ

		}
		inpfile.close();

		ofstream outfile("out.txt");//открываем выходной файл для записи

		if(!outfile.is_open())cout&lt;&lt;"Невозможно открыть файл";

		if(kolotkrck==0 &amp;&amp; kolzakrck==0)
			{
				cout&lt;&lt;"Открывающихся и закрывающихся скобок не наблюдается";
				outfile&lt;&lt;"Открывающихся и закрывающихся скобок не наблюдается";
		}
		else
		{
			if(kolotkrck==kolzakrck)
			{
				cout&lt;&lt;"количество Открывающихся и закрывающихся скобок одинаково";
				outfile&lt;&lt;"количество Открывающихся и закрывающихся скобок одинаково";
			}
			else
			{
                 cout&lt;&lt;"количество Открывающихся и закрывающихся скобок различно";
				outfile&lt;&lt;"количество Открывающихся и закрывающихся скобок различно";
			}
		}
	}
	return 0;
}