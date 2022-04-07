#include <fstream>
#include "Tree.h"

using namespace std;

namespace Melikov
{

	// Ввод параметров дерева из файла
	void In(Tree& _r, ifstream& ifst) 
	{
		ifst >> _r._age;
	}

	// Вывод параметров дерева в поток
	void Out(Tree& _r, ofstream& ofst) 
	{
		ofst << "It is tree: age = " << _r._age
			<< endl;
	}
}