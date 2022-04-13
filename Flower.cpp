#include "Flower.h"
#include <fstream>

using namespace std;

namespace Melikov {
	// ���� ���������� ������ �� �����
	flower* In(flower& f, ifstream& ifst) {
		int temp;
		ifst >> temp;
		f.tof = (flower::type)temp;
		return &f;
	}

	// ����� ���������� ������ � �����
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