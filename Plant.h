#include <fstream>
using namespace std;

#pragma once
#ifndef __Plant__
#define __Plant__

// ����������� ����������� ����� ������
#include "Tree.h"
#include "Bush.h"
namespace Melikov
{
	// ���������, ���������� ��� ��������� ��������
	struct plant {
		plant() {}
		// �������� ������ ��� ������� �� ��������
		enum key { TREE, BUSH };
		key k; // ����
		// ������������ ������������
		union { // ���������� ���������
			tree r;
			bush t;
		};
		enum habitat { TUNDRA = 1, DESERT, STEPPE };
		habitat hbt;
	};
	//
	plant* In(ifstream& ifst);
	// ��������� ��������� ������� �������
	void In(tree& r, ifstream& ist);
	void In(bush& t, ifstream& ist);

	//
	void Out(plant& s, ofstream& ofst);
	// ��������� ��������� ������� �������.
	void Out(tree& r, ofstream& ofst);
	void Out(bush& t, ofstream& ofst);
}

#endif
