#include "Container.h"
#include "Plant.h"
#include <fstream>
#include <iostream>
using namespace std;
namespace Melikov
{

	void Init(LinkedCircledList& obj)
	{
		obj._first = NULL;
		obj._last = obj._first;
		obj._sizeList = 0;
	}

	void Clear(LinkedCircledList& obj)
	{
		Node* temp = NULL;
		while (obj._sizeList > 1)
		{
			temp = obj._last->_prev;
			delete obj._last;
			obj._last = temp;
			obj._sizeList--;
		}
		if (obj._sizeList == 1)
		{
			delete obj._first;
			obj._sizeList--;
		}
	}

	void LinkedCircledListIn(LinkedCircledList& obj, ifstream& fin)
	{
		Node* temp;
		while (!fin.eof())
		{
			temp = new Node;
			temp->_next = NULL;
			temp->_plant = In(fin);

			if (temp->_plant == NULL)
			{
				break;
			}

			if (obj._first == NULL)
			{
				obj._first = obj._last = temp;
				temp->_prev = temp;
				temp->_next = obj._first;
			}
			else
			{
				temp->_prev = obj._last;
				obj._last->_next = temp;
				temp->_next = obj._first;
				obj._last = temp;
			}
			obj._sizeList++;
		}
	}

	void LinkedCircledListOut(LinkedCircledList& obj, ofstream& fout)
	{

		Node* temp = obj._first;
		fout << "List contains " << obj._sizeList << " elements" << endl;

		for (int i = 0; i < obj._sizeList; i++)
		{
			Out(*(temp->_plant), fout);
			fout << "Consonants = " << Consonants(*(temp->_plant)) << endl;
			temp = temp->_next;
		}
		fout << endl;
		for (int i = 0; i < obj._sizeList; i++)
		{
			OutTree(*(temp->_plant), fout);
			temp = temp->_next;
		}
		fout << endl;
	}

	bool Compare(Plant* first, Plant* second) 
	{
		return Consonants(*first) > Consonants(*second);
	}

	void Sort(LinkedCircledList& obj) 
	{
		if (obj._sizeList < 2) 
		{
			return;
		}

		Node* current = obj._first;
		bool flag = false;

		do
		{
			current = obj._first;
			flag = false;
			for (int i = 0; i < (obj._sizeList - 1); ++i)
			{
				if (Compare(current->_plant, current->_next->_plant))
				{
					Swap(current, current->_next);
					flag = true;
				}
				else
				{
					current = current->_next;
				}
			}
		} while (flag);
	}

	void Swap(Node* first, Node* second) 
	{
		Plant* temp;
		temp = first->_plant;
		first->_plant = second->_plant;
		second->_plant = temp;
		return;
	}
}