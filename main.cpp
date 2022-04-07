﻿//11 5 2 1

/*
11. Растения    1. Деревья(возраст – длинное целое)
				2. Кустарники(месяц цветения – перечислимый тип)
				Название – строка символов

5. Контейнер на основе двунаправленного кольцевого списка

2. Разбиение на модули осуществляется по объектному принципу. То
есть описание абстракций и функций их обработки группируются по виду
абстракций. При этом проводится разделение описания типов, сигнатур и
классов от их реализации. Клиентский модуль связан с основной частью
программы только минимально необходимым интерфейсом.

1. Обобщение, построенное на основе непосредственного включения
специализаций.

11. Цветы (домашние, садовые, дикие… – перечислимый тип) КЛАСС
11. Количество согласных букв в названии растения (целое число) ФУНКЦИЯ
11. Где произрастает (перечислимый тип = тундра, пустыня, степь) ПОЛЕ
11. Сортировка (по возрастанию)
*/

#include <iostream>
#include <fstream>
#include <clocale>
#include "Container.h"
using namespace std;
using namespace Melikov;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 3) 
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	LinkedCircledList container;
	Init(container);
	LinkedCircledListIn(container, ifst);
	ofst << "Filled container. " << endl;
	LinkedCircledListOut(container, ofst);
	ofst << "Sorted container." << endl;
	Sort(container);
	LinkedCircledListOut(container, ofst);
	Clear(container);
	ofst << "Empty container. " << endl;
	LinkedCircledListOut(container, ofst);
	cout << "Stop" << endl;
	return 0;
}
