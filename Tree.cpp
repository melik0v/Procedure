#include <fstream>
#include "Tree.h"
#include <string>
#define WRONG_AGE 1
using namespace std;

namespace Melikov
{

	// Ввод параметров дерева из файла
	void In(tree& r, ifstream& ifst) {
		string temp;
		ifst >> temp;
		bool valid = true;
		for (int i = 0; i < temp.length(); i++)
		{
			if (!isdigit(temp[i]) || i > 9)
			{
				r.age = WRONG_AGE;
				valid = false;
				break;
			}
		}
		if (valid)
			r.age = stoi(temp);

	}

	// Вывод параметров дерева в поток
	void Out(tree& r, ofstream& ofst) {
		if (r.age == WRONG_AGE)
			ofst << "Wrong age " << endl;
		else
			ofst << "It is Tree: age = " << r.age << endl;
	}
}