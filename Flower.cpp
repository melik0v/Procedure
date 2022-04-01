#include "Flower.h"
#include <fstream>
#include <string>
#define WRONG_FLOWER 0

using namespace std;

namespace Melikov {
	// Ввод параметров цветка из файла
	void In(flower& f, ifstream& ifst) {
		string temp;
		ifst >> temp;
		bool valid = true;
		for (int i = 0; i < temp.length(); i++)
		{
			if (!isdigit(temp[i]) || i > 9)
			{
				f.tof = (flower::type)WRONG_FLOWER;
				valid = false;
				return;
			}
		}
		if (valid)
			f.tof = (flower::type)stoi(temp);
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
		default:
			ofst << "Wrong flower" << endl;
			break;
		}
	}
}