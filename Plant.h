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
	struct Plant {
		Plant() {}
		// значения ключей для каждого из растений
		enum Key 
		{ 
			TREE, 
			BUSH, 
			FLOWER 
		};
		Key _k; // ключ
		// используемые альтернативы
		union 
		{ // используем включение
			Tree _r;
			Bush _t;
			Flower _f;
		};
		enum Habitat { TUNDRA = 1, DESERT, STEPPE };
		Habitat _hbt;
		string _name;
	};


	//
	Plant* In(ifstream& ifst);
	// Сигнатуры требуемых внешних функций
	void In(Tree& _r, ifstream& ist);
	void In(Bush& _t, ifstream& ist);
	void In(Flower& _f, ifstream& ifst);
	//
	void Out(Plant& s, ofstream& ofst);
	void OutTree(Plant& s, ofstream& ofst);
	// Сигнатуры требуемых внешних функций.
	void Out(Tree& _r, ofstream& ofst);
	void Out(Bush& _t, ofstream& ofst);
	void Out(Flower& _f, ofstream& ofst);
}
