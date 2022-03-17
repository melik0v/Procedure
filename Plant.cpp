#include <fstream>
#include "Plant.h"
using namespace std;

namespace Melikov
{

	// Ввод параметров обобщенной фигуры из файла
	plant* In(ifstream& ifst)
	{
		plant* pt;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			pt = new plant;
			pt->k = plant::key::TREE;
			In(pt->r, ifst);
			return pt;
		case 2:
			pt = new plant;
			pt->k = plant::key::BUSH;
			In(pt->t, ifst);
			return pt;
		default:
			return 0;
		}
	}


	// Вывод параметров текущей фигуры в поток
	void Out(plant& s, ofstream& ofst) {
		switch (s.k) {
		case plant::key::TREE:
			Out(s.r, ofst);
			break;
		case plant::key::BUSH:
			Out(s.t, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << endl;
		}
	}

	int consonants(plant& pt) {
		char consonants[40] = { 'B', 'b', 'C', 'c', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'P', 'p', 'Q', 'q',
		'R', 'r', 'S', 's', 'T', 't', 'V', 'v', 'W', 'w', 'X', 'x', 'Z','z'};
		char* name = NULL;

		switch (pt.k)
		{
		case plant::key::TREE:
			name = pt.r.name;
			break;
		case plant::key::BUSH:
			name = pt.t.name;
			break;
		default:
			return -1;
		}
		int count = 0;
		for (int i = 0; i < 50; i++)
		{
			if (name[i] == '\0')
				break;
			for (int j = 0; j < 40; j++)
			{
				if (name[i] == consonants[j]) {
					count++;
				}
			}
		}
		return count;
	}
}
