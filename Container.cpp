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
		Node* Temp = NULL;
		while (obj._sizeList > 1)
		{
			Temp = obj._last->_prev;
			delete obj._last;
			obj._last = Temp;
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
		Node* Temp;
		while (!fin.eof())
		{
			Temp = new Node;
			Temp->_next = NULL;
			Temp->_plant = In(fin);

			if (Temp->_plant == NULL)
			{
				break;
			}

			if (obj._first == NULL)
			{
				obj._first = obj._last = Temp;
				Temp->_prev = Temp;
				Temp->_next = obj._first;
			}
			else
			{
				Temp->_prev = obj._last;
				obj._last->_next = Temp;
				Temp->_next = obj._first;
				obj._last = Temp;
			}
			obj._sizeList++;
		}
	}

	void LinkedCircledListOut(LinkedCircledList& obj, ofstream& fout)
	{

		Node* Temp = obj._first;
		fout << "List contains " << obj._sizeList << " elements" << endl;

		for (int i = 0; i < obj._sizeList; i++)
		{
			Out(*(Temp->_plant), fout);
			fout << "Consonants = " << Consonants(*(Temp->_plant)) << endl;
			Temp = Temp->_next;
		}
		fout << endl;
		for (int i = 0; i < obj._sizeList; i++)
		{
			OutTree(*(Temp->_plant), fout);
			Temp = Temp->_next;
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
		Plant* tmp;
		tmp = first->_plant;
		first->_plant = second->_plant;
		second->_plant = tmp;
		return;
	}
}