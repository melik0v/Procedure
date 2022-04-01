#include <fstream>
#include "Plant.h"
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
#define WRONG_PLANT 0
#define WRONG_HABITAT -1
namespace Melikov
{

	// Ввод параметров обобщенной фигуры из файла
	plant* In(ifstream& ifst)
	{
		plant* pt;
		int k;
		string tmp;
		int hbt;
		ifst >> tmp;

		if (tmp == "\0")
			return 0;
		if (!isdigit(int(tmp.front())) || tmp.length() > 1)
			k = WRONG_PLANT;
		else
			k = stoi(tmp);

		switch (k) {
		case 1:
			pt = new plant;
			pt->k = plant::key::TREE;
			In(pt->r, ifst);
			break;
		case 2:
			pt = new plant;
			pt->k = plant::key::BUSH;
			In(pt->t, ifst);
			break;
		case 3:
			pt = new plant;
			pt->k = plant::key::FLOWER;
			In(pt->f, ifst);
			break;
		default:
			pt = new plant;
			pt->k = plant::key(WRONG_PLANT);
			getline(ifst, tmp, '\n');
			cout << "Wrong plant!" << endl;
			return 0;
		}
		ifst >> pt->name;
		tmp = "";
		ifst >> hbt;
		if (ifst.fail())
		{
			hbt = WRONG_HABITAT;
		}			
		pt->hbt = (plant::habitat)hbt;
		return pt;
	}


	// Вывод параметров растений в поток
	void Out(plant& s, ofstream& ofst) {
		switch (s.k) {
		case plant::key::TREE:
			Out(s.r, ofst);
			break;
		case plant::key::BUSH:
			Out(s.t, ofst);
			break;
		case plant::key::FLOWER:
			Out(s.f, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << endl;
			return;
		}
		ofst << "Name = " << s.name << ", ";
		switch (s.hbt)
		{
		case 1:
			ofst << "Habitat = tundra" << endl;
			break;
		case 2:
			ofst << "Habitat = desert" << endl;
			break;
		case 3:
			ofst << "Habitat = steppe" << endl;
			break;
		default:
			ofst << "Wrong habitat" << endl;
		}
		ofst << "Consonants = " << consonants(s) << endl;
	}

	int consonants(plant& pt) {
		char consonants[40] = { 'B', 'b', 'C', 'c', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'P', 'p', 'Q', 'q',
		'R', 'r', 'S', 's', 'T', 't', 'V', 'v', 'W', 'w', 'X', 'x', 'Z','z'};
		int count = 0;
		for (int i = 0; i < 50; i++)
		{
			if (pt.name[i] == '\0')
				break;
			for (int j = 0; j < 40; j++)
			{
				if (pt.name[i] == consonants[j]) {
					count++;
				}
			}
		}
		return count;
	}

	void OutTree(plant& s, ofstream& ofst) {
		switch (s.k) {
		case plant::key::TREE:
			ofst << "Name = " << s.name << ", ";
			Out(s.r, ofst);
			break;
		default:
			return;
		}

	}
}
