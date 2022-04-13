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
	struct plant {
		plant() {}
		// �������� ������ ��� ������� �� ��������
		enum key { TREE, BUSH, FLOWER };
		key k; // ����
		// ������������ ������������
		union { // ���������� ���������
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
	// ��������� ��������� ������� �������
	tree* In(tree& r, ifstream& ifst);
	bush* In(bush& t, ifstream& ifst);
	flower* In(flower& f, ifstream& ifst);
	//
	void Out(plant& s, ofstream& ofst);
	// ��������� ��������� ������� �������.
	void Out(tree& r, ofstream& ofst);
	void Out(bush& t, ofstream& ofst);
	void Out(flower& f, ofstream& ofst);
}
