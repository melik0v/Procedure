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
		int hbt;
		ifst >> k;
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
			return 0;
		}
		ifst >> hbt;
		pt->hbt = (plant::habitat)hbt;
		return pt;
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
		case plant::key::FLOWER:
			Out(s.f, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << endl;
		}
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
		}
	}
}
