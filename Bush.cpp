#include <fstream>
#include "Bush.h"

using namespace std;
namespace Melikov
{
	// ���� ���������� ���������� �� �����
	void In(bush& t, ifstream& ifst) {
		int temp;
		ifst >> temp >> t.name;
		t.mof = (bush::Month)temp;
	}

	// ����� ���������� ��������� � �����
	void Out(bush& t, ofstream& ofst) {
		switch (t.mof)
		{
			case (t.JANUARY):
				ofst << "It is Bush: month of flowering = " << "January"
				<< ", name = " << t.name << endl;
				break;
			case (t.FEBRUARY):
				ofst << "It is Bush: month of flowering = " << "February"
					<< ", name = " << t.name << endl;
				break;
			case (t.MARCH):
				ofst << "It is Bush: month of flowering = " << "March"
					<< ", name = " << t.name << endl;
				break;
			case (t.APRIL):
				ofst << "It is Bush: month of flowering = " << "April"
					<< ", name = " << t.name << endl;
				break;
			case (t.MAY):
				ofst << "It is Bush: month of flowering = " << "May"
					<< ", name = " << t.name << endl;
				break;
			case (t.JUNE):
				ofst << "It is Bush: month of flowering = " << "June"
					<< ", name = " << t.name << endl;
				break;
			case (t.JULY):
				ofst << "It is Bush: month of flowering = " << "July"
					<< ", name = " << t.name << endl;
				break;
			case (t.AUGUST):
				ofst << "It is Bush: month of flowering = " << "August"
					<< ", name = " << t.name << endl;
				break;
			case (t.SEPTEMBER):
				ofst << "It is Bush: month of flowering = " << "September"
					<< ", name = " << t.name << endl;
				break;
			case (t.OCTOBER):
				ofst << "It is Bush: month of flowering = " << "October"
					<< ", name = " << t.name << endl;
				break;
			case (t.NOVEMBER):
				ofst << "It is Bush: month of flowering = " << "November"
					<< ", name = " << t.name << endl;
				break;
			case (t.DECEMBER):
				ofst << "It is Bush: month of flowering = " << "December"
					<< ", name = " << t.name << endl;
				break;
			default:
				ofst << "Error: " << t.mof << " is invalid number of month!" << endl;
				break;
		}
		
	}
}