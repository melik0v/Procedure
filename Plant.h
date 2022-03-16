#include <fstream>
using namespace std;

#pragma once
#ifndef __Plant__
#define __Plant__

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
	};
	//
	plant* In(ifstream& ifst);
	// ��������� ��������� ������� �������
	void In(tree& r, ifstream& ist);
	void In(bush& t, ifstream& ist);
	void In(flower& f, ifstream& ifst);
	//
	void Out(plant& s, ofstream& ofst);
	// ��������� ��������� ������� �������.
	void Out(tree& r, ofstream& ofst);
	void Out(bush& t, ofstream& ofst);
	void Out(flower& f, ofstream& ofst);
}

#endif
