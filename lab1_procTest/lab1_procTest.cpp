#include "pch.h"
#include "CppUnitTest.h"
#include "../Bush.h"
#include "../Tree.h"
#include "../Flower.h"
#include "../Container.h"
#include "../Plant.h"
#include "../Bush.cpp"
#include "../Tree.cpp"
#include "../Flower.cpp"
#include "../Container.cpp"
#include "../Plant.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Melikov
{
	TEST_CLASS(lab1procTest)
	{
	public:
		
		TEST_METHOD(consonantsTest)
		{
			plant* pt;
			pt = new plant;
			pt->k = plant::key::TREE;
			pt->r.age = 10;
			pt->hbt = plant::habitat::STEPPE;
			string name = "Poplar";
			//strcpy(pt->r.name, name);
			pt->name = name;

			int expected = 4;
			//int actual = 4;
			int actual = consonants(*pt);

			Assert::AreEqual(expected, actual);
		}
	};
}
