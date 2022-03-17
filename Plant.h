#include <fstream>
using namespace std;

#pragma once
#ifndef __Plant__
#define __Plant__

// Подключение необходимых типов данных
#include "Tree.h"
#include "Bush.h"
namespace Melikov
{
	// структура, обобщающая все имеющиеся растения
	struct plant {
		plant() {}
		// значения ключей для каждого из растений
		enum key { TREE, BUSH };
		key k; // ключ
		// используемые альтернативы
		union { // используем включение
			tree r;
			bush t;
		};
	};
	//
	plant* In(ifstream& ifst);
	// Сигнатуры требуемых внешних функций
	void In(tree& r, ifstream& ist);
	void In(bush& t, ifstream& ist);

	//
	void Out(plant& s, ofstream& ofst);
	void OutTree(plant& s, ofstream& ofst);
	// Сигнатуры требуемых внешних функций.
	void Out(tree& r, ofstream& ofst);
	void Out(bush& t, ofstream& ofst);
}

#endif
