#include <fstream>
#include "Tree.h"

using namespace std;

namespace Melikov
{

	// ���� ���������� ������ �� �����
	void In(tree& r, ifstream& ifst) {
		ifst >> r.age;
	}

	// ����� ���������� ������ � �����
	void Out(tree& r, ofstream& ofst) {
		ofst << "It is Tree: age = " << r.age
			<< endl;
	}
}