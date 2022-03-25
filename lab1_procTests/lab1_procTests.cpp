#include "pch.h"
#include "CppUnitTest.h"
#include "../Bush.h"
#include "../Container.h"
#include "../Flower.h"
#include "../Tree.h"
#include "../Plant.h"
#include "../Bush.cpp"
#include "../Container.cpp"
#include "../Flower.cpp"
#include "../Tree.cpp"
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
			char name[] = "Poplar";
			//strcpy(pt->r.name, name);
			strcpy(pt->name, name);

			int expected = 4;
			//int actual = 4;
			int actual = consonants(*pt);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod1)
		{

		}

		TEST_METHOD(TestMethod2)
		{

		}
	};
}