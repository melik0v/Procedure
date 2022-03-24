#include <fstream>
#include "Bush.h"

using namespace std;
namespace Melikov
{
	// Ввод параметров кустарника из файла
	void In(bush& t, ifstream& ifst) {
		int temp;
		ifst >> temp;
		t.mof = (bush::Month)temp;
	}

	// Вывод параметров кусарника в поток
	void Out(bush& t, ofstream& ofst) {
		switch (t.mof)
		{
			case (t.JANUARY):
				ofst << "It is Bush: month of flowering = " << "January" << endl;
				break;
			case (t.FEBRUARY):
				ofst << "It is Bush: month of flowering = " << "February" << endl;
				break;
			case (t.MARCH):
				ofst << "It is Bush: month of flowering = " << "March" << endl;
				break;
			case (t.APRIL):
				ofst << "It is Bush: month of flowering = " << "April" << endl;
				break;
			case (t.MAY):
				ofst << "It is Bush: month of flowering = " << "May" << endl;
				break;
			case (t.JUNE):
				ofst << "It is Bush: month of flowering = " << "June" << endl;
				break;
			case (t.JULY):
				ofst << "It is Bush: month of flowering = " << "July" << endl;
				break;
			case (t.AUGUST):
				ofst << "It is Bush: month of flowering = " << "August" << endl;
				break;
			case (t.SEPTEMBER):
				ofst << "It is Bush: month of flowering = " << "September" << endl;
				break;
			case (t.OCTOBER):
				ofst << "It is Bush: month of flowering = " << "October" << endl;
				break;
			case (t.NOVEMBER):
				ofst << "It is Bush: month of flowering = " << "November" << endl;
				break;
			case (t.DECEMBER):
				ofst << "It is Bush: month of flowering = " << "December" << endl;
				break;
			default:
				ofst << "Error: " << t.mof << " is invalid number of month!" << endl;
				break;
		}
		
	}
}