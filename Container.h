#pragma once
#ifndef __Container__
#define __Container__

#include "Plant.h"

namespace Melikov
{
	struct Node
	{
		plant* plant;
		Node* Next;
		Node* Prev;
	};

	struct LinkedCircledList
	{
		Node* First;
		Node* Last;
		size_t SizeList;
	};

	void Init(LinkedCircledList& obj);
	void Clear(LinkedCircledList& obj);
	
	void LinkedCircledList_In(LinkedCircledList& obj, ifstream& fin);
	void LinkedCircledList_Out(LinkedCircledList& obj, ofstream& fout);
	int consonants(plant& pt);
	void sort(LinkedCircledList& obj);
	bool compare(plant* first, plant* second);
	void swap(Node* first, Node* second);

}

#endif