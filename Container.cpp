#include "Container.h"
#include "Plant.h"
#include <fstream>
#include <iostream>
using namespace std;
namespace Melikov
{

	void Init(LinkedCircledList& obj)
	{
		obj.First = NULL;
		obj.Last = obj.First;
		obj.SizeList = 0;
	}

	void Clear(LinkedCircledList& obj)
	{
		Node* Temp = NULL;
		while (obj.SizeList > 1)
		{
			Temp = obj.Last->Prev;
			delete obj.Last;
			obj.Last = Temp;
			obj.SizeList--;
		}
		if (obj.SizeList == 1)
			delete obj.First;
		obj.SizeList--;
	}

	void LinkedCircledList_In(LinkedCircledList& obj, ifstream& fin)
	{
		Node* Temp;
				
		while (!fin.eof())
		{
			Temp = new Node;
			Temp->Next = NULL;
			Temp->plant = In(fin);

			if (Temp->plant == NULL)
				break;

			if (obj.First == NULL)
			{
				obj.First = obj.Last = Temp;
				Temp->Prev = Temp;
				Temp->Next = obj.First;
			}
			else
			{
				Temp->Prev = obj.Last;
				obj.Last->Next = Temp;
				Temp->Next = obj.First;
				obj.Last = Temp;
			}
			obj.SizeList++;
		}
	}

	void LinkedCircledList_Out(LinkedCircledList& obj, ofstream& fout)
	{

		Node* Temp = obj.First;
		fout << "List contains " << obj.SizeList << " elements" << endl;
		
		for (int i = 0; i < obj.SizeList; i++)
		{
			Out(*(Temp->plant), fout);
			fout << "Consonants = " << consonants(*(Temp->plant)) << endl;
			Temp = Temp->Next;
			
		}
		fout << endl;
		for (int i = 0; i < obj.SizeList; i++)
		{
			OutTree(*(Temp->plant), fout);
			Temp = Temp->Next;
		}
		fout << endl;
	}

	bool compare(plant* first, plant* second) {
		return consonants(*first) > consonants(*second);
	}

	void sort(LinkedCircledList& obj) {
		if (obj.SizeList < 2) {
			return;
		}

		Node* current = obj.First;
		bool flag = false;

		do
		{
			current = obj.First;
			flag = false;
			for (int i = 0; i < (obj.SizeList - 1); ++i) 
			{
				if (compare(current->plant, current->Next->plant)) 
				{
					swap(current, current->Next);
					flag = true;
				}
				else
				{
					current = current->Next;
				}
			}
		} while (flag);
	}

	void swap(Node* first, Node* second) {

		plant* tmp;
		tmp = first->plant;
		first->plant = second->plant;
		second->plant = tmp;
		return;
	}
}