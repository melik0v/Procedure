#include <fstream>
using namespace std;

#pragma once

// ����������� ����������� ����� ������
#include "Tree.h"
#include "Bush.h"
#include "Flower.h"
namespace Melikov
{
	// ���������, ���������� ��� ��������� ��������
	struct Plant {
		Plant() {}
		// �������� ������ ��� ������� �� ��������
		enum Key 
		{ 
			TREE, 
			BUSH, 
			FLOWER 
		};
		Key _k; // ����
		// ������������ ������������
		union 
		{ // ���������� ���������
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
	// ��������� ��������� ������� �������
	void In(Tree& _r, ifstream& ist);
	void In(Bush& _t, ifstream& ist);
	void In(Flower& _f, ifstream& ifst);
	//
	void Out(Plant& s, ofstream& ofst);
	void OutTree(Plant& s, ofstream& ofst);
	// ��������� ��������� ������� �������.
	void Out(Tree& _r, ofstream& ofst);
	void Out(Bush& _t, ofstream& ofst);
	void Out(Flower& _f, ofstream& ofst);
}
