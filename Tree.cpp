#include <fstream>
#include "Tree.h"

using namespace std;

namespace Melikov
{

	// ���� ���������� ������ �� �����
	void In(Tree& _r, ifstream& ifst) 
	{
		ifst >> _r._age;
	}

	// ����� ���������� ������ � �����
	void Out(Tree& _r, ofstream& ofst) 
	{
		ofst << "It is tree: age = " << _r._age
			<< endl;
	}
}