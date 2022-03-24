#include <fstream>
#include "Tree.h"

using namespace std;

namespace Melikov
{

	// Ввод параметров дерева из файла
	void In(tree& r, ifstream& ifst) {
		ifst >> r.age;
	}

	// Вывод параметров дерева в поток
	void Out(tree& r, ofstream& ofst) {
		ofst << "It is Tree: age = " << r.age
			<< endl;
	}
}