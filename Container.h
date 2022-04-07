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

	struct LinkedCircledList
	{
		Node* _first;
		Node* _last;
		size_t _sizeList;
	};

	void Init(LinkedCircledList& obj);
	void Clear(LinkedCircledList& obj);

	void LinkedCircledListIn(LinkedCircledList& obj, ifstream& fin);
	void LinkedCircledListOut(LinkedCircledList& obj, ofstream& fout);
	int Consonants(Plant& pt);
	void Sort(LinkedCircledList& obj);
	bool Compare(Plant* first, Plant* second);
	void Swap(Node* first, Node* second);

}

#endif