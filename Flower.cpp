#include "Flower.h"
#include <fstream>

using namespace std;

namespace Melikov {
	// Ввод параметров цветка из файла
	void In(flower& f, ifstream& ifst) {
		int temp;
		ifst >> temp;
		f.tof = (flower::type)temp;
	}

	// Вывод параметров цветка в поток
	void Out(flower& f, ofstream& ofst) {
		switch (f.tof)
		{
		case (f.HOME):
			ofst << "It is Flower: type = " << "Home" << endl;
			break;
		case (f.GARDEN):
			ofst << "It is Flower: type = " << "Garden" << endl;
			break;
		case (f.WILD):
			ofst << "It is Flower: type = " << "Wild" << endl;
			break;
		}
	}
}