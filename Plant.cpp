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
}
