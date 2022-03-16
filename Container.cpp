#include "Container.h"
#include "Plant.h"
#include <fstream>
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
			Temp = Temp->Next;
		}
		fout << endl;
	}

}