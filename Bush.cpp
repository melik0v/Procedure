#include <fstream>
#include "Bush.h"

using namespace std;
namespace Melikov
{
	// Ввод параметров кустарника из файла
	void In(Bush& _t, ifstream& ifst) 
	{
		int temp;
		ifst >> temp;
		_t._mof = (Bush::Month)temp;
	}

	// Вывод параметров кусарника в поток
	void Out(Bush& _t, ofstream& ofst) 
	{
		switch (_t._mof)
		{
		case (_t.JANUARY):
			ofst << "It is bush: month of flowering = " << "January" << endl;
			break;
		case (_t.FEBRUARY):
			ofst << "It is bush: month of flowering = " << "February" << endl;
			break;
		case (_t.MARCH):
			ofst << "It is bush: month of flowering = " << "March" << endl;
			break;
		case (_t.APRIL):
			ofst << "It is bush: month of flowering = " << "April" << endl;
			break;
		case (_t.MAY):
			ofst << "It is bush: month of flowering = " << "May" << endl;
			break;
		case (_t.JUNE):
			ofst << "It is bush: month of flowering = " << "June" << endl;
			break;
		case (_t.JULY):
			ofst << "It is bush: month of flowering = " << "July" << endl;
			break;
		case (_t.AUGUST):
			ofst << "It is ush: month of flowering = " << "August" << endl;
			break;
		case (_t.SEPTEMBER):
			ofst << "It is bush: month of flowering = " << "September" << endl;
			break;
		case (_t.OCTOBER):
			ofst << "It is bush: month of flowering = " << "October" << endl;
			break;
		case (_t.NOVEMBER):
			ofst << "It is bush: month of flowering = " << "November" << endl;
			break;
		case (_t.DECEMBER):
			ofst << "It is bush: month of flowering = " << "December" << endl;
			break;
		default:
			ofst << "Error: " << _t._mof << " is invalid number of month!" << endl;
			break;
		}

	}
}