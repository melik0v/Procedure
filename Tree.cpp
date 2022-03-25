#include <fstream>
#include "Tree.h"
#include <string>
#define WRONG_AGE 1
using namespace std;

namespace Melikov
{

	// ���� ���������� ������ �� �����
	void In(tree& r, ifstream& ifst) {
		string temp;
		ifst >> temp;
		if (!isdigit(int(temp.front())) || temp.length() > 9)
			r.age = WRONG_AGE;
		else
			r.age = stoi(temp);
	}

	// ����� ���������� ������ � �����
	void Out(tree& r, ofstream& ofst) {
		if (r.age == WRONG_AGE)
			ofst << "Wrong age " << endl;
		else
			ofst << "It is Tree: age = " << r.age << endl;
	}
}