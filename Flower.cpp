#include "Flower.h"
#include <fstream>

using namespace std;

namespace Melikov {
	// Ввод параметров цветка из файла
	void In(Flower& _f, ifstream& ifst) 
	{
		int temp;
		ifst >> temp;
		_f._tof = (Flower::Type)temp;
	}

	// Вывод параметров цветка в поток
	void Out(Flower& _f, ofstream& ofst) 
	{
		switch (_f._tof)
		{
		case (_f.HOME):
			ofst << "It is flower: type = " << "Home" << endl;
			break;
		case (_f.GARDEN):
			ofst << "It is flower: type = " << "Garden" << endl;
			break;
		case (_f.WILD):
			ofst << "It is flower: type = " << "Wild" << endl;
			break;
		}
	}
}