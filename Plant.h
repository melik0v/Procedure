#include <fstream>
using namespace std;

#pragma once

// Подключение необходимых типов данных
#include "Tree.h"
#include "Bush.h"
#include "Flower.h"
namespace Melikov
{
	// структура, обобщающая все имеющиеся растения
	struct plant {
		plant() {}
		// значения ключей для каждого из растений
		enum key { TREE, BUSH, FLOWER };
		key k; // ключ
		// используемые альтернативы
		union { // используем включение
			tree r;
			bush t;
			flower f;
		};
		enum habitat { TUNDRA = 1, DESERT, STEPPE };
		habitat hbt;
		string name;
	};

	
	//
	plant* In(ifstream& ifst);
	// Сигнатуры требуемых внешних функций
	void In(tree& r, ifstream& ist);
	void In(bush& t, ifstream& ist);
	void In(flower& f, ifstream& ifst);
	//
	void Out(plant& s, ofstream& ofst);
	void OutTree(plant& s, ofstream& ofst);
	// Сигнатуры требуемых внешних функций.
	void Out(tree& r, ofstream& ofst);
	void Out(bush& t, ofstream& ofst);
	void Out(flower& f, ofstream& ofst);
}
