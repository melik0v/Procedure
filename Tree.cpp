#include <fstream>
#include "Tree.h"

using namespace std;

namespace Melikov
{

	// ���� ���������� ������ �� �����
	tree* In(tree& r, ifstream& ifst) {
		ifst >> r.age;
		return &r;
	}

	// ����� ���������� ������ � �����
	void Out(tree& r, ofstream& ofst) {
		ofst << "It is Tree: age = " << r.age
			<< endl;
	}
}