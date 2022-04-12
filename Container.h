#pragma once
#ifndef __Container__
#define __Container__

#include "Plant.h"

namespace Melikov
{
	struct Node
	{
		Plant* _plant;
		Node* _next;
		Node* _prev;
	};

	struct Container
	{
		Node* _first;
		Node* _last;
		size_t _sizeList;
	};

	void Init(Container& obj);
	void Clear(Container& obj);

	void ContainerIn(Container& obj, ifstream& fin);
	void ContainerOut(Container& obj, ofstream& fout);
	int Consonants(Plant& pt);
	void Sort(Container& obj);
	bool Compare(Plant* first, Plant* second);
	void Swap(Node* first, Node* second);

}

#endif