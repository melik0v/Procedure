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
using namespace Melikov;

namespace lab1_procTest
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
			pt->name = name;

			int expected = 4;
			int actual = consonants(*pt);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(compareTest)
		{
			plant* first = new plant;
			plant* second = new plant;
			first->name = "Maple";
			second->name = "Oak";

			bool expected = true;
			bool actual = compare(first, second);
			
			Assert::AreEqual(expected, actual);
		}
	};
}
