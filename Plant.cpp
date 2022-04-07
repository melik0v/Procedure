#include <fstream>
#include "Plant.h"
using namespace std;

namespace Melikov
{
	// Ввод параметров обобщенной фигуры из файла
	Plant* In(ifstream& ifst)
	{
		Plant* pt;
		int _k;
		int _hbt;
		ifst >> _k;
		switch (_k) {
		case 1:
			pt = new Plant;
			pt->_k = Plant::Key::TREE;
			In(pt->_r, ifst);
			break;
		case 2:
			pt = new Plant;
			pt->_k = Plant::Key::BUSH;
			In(pt->_t, ifst);
			break;
		case 3:
			pt = new Plant;
			pt->_k = Plant::Key::FLOWER;
			In(pt->_f, ifst);
			break;
		default:
			return 0;
		}
		ifst >> pt->_name >> _hbt;
		pt->_hbt = (Plant::Habitat)_hbt;
		return pt;
	}


	// Вывод параметров растений в поток
	void Out(Plant& s, ofstream& ofst) 
	{
		ofst << "Name = " << s._name << ", ";
		switch (s._k) {
		case Plant::Key::TREE:
			Out(s._r, ofst);
			break;
		case Plant::Key::BUSH:
			Out(s._t, ofst);
			break;
		case Plant::Key::FLOWER:
			Out(s._f, ofst);
			break;
		default:
			ofst << "Incorrect plant!" << endl;
		}
		switch (s._hbt)
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

	int Consonants(Plant& pt) 
	{
		char consonants[40] = { 'B', 'b', 'C', 'c', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'P', 'p', 'Q', 'q',
		'R', 'r', 'S', 's', 'T', 't', 'V', 'v', 'W', 'w', 'X', 'x', 'Z','z' };
		int count = 0;
		for (int i = 0; i < 50; i++)
		{
			if (pt._name[i] == '\0')
			{
				break;
			}
			for (int j = 0; j < 40; j++)
			{
				if (pt._name[i] == consonants[j]) 
				{
					count++;
				}
			}
		}
		return count;
	}

	void OutTree(Plant& s, ofstream& ofst) 
	{
		switch (s._k) 
		{
		case Plant::Key::TREE:
			ofst << "Name = " << s._name << ", ";
			Out(s._r, ofst);
			break;
		default:
			return;
		}

	}
}
