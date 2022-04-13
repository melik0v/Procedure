#include "pch.h"
#include <fstream>
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

		TEST_METHOD(TreeInput)
		{
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Tree_Input.txt");
			tree tmp;
			tree* actual = In(tmp, ifst);
			tree expected;
			expected.age = 10;
			Assert::AreEqual(expected.age, actual->age);
		}

		TEST_METHOD(TreeOutput)
		{
			ofstream ofst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Tree_Output.txt");
			tree tmp;
			tmp.age = 10;
			Out(tmp, ofst);
			ofst.close();
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Tree_Output.txt");
			string expected = "It is Tree: age = 10";
			string actual;
			getline(ifst, actual, '\n');
			ifst.close();
			Assert::AreEqual(expected, actual);
			
		}
		
		TEST_METHOD(BushInput)
		{
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Bush_Input.txt");
			bush tmp;
			bush* actual = In(tmp, ifst);
			bush expected;
			expected.mof = bush::Month::MAY;
			Assert::AreEqual(int(expected.mof), int(actual->mof));
		}

		TEST_METHOD(BushOutput)
		{
			ofstream ofst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Bush_Output.txt");
			bush tmp;
			tmp.mof = bush::Month::MAY;
			Out(tmp, ofst);
			ofst.close();
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Bush_Output.txt");
			string expected = "It is Bush: month of flowering = May";
			string actual;
			getline(ifst, actual, '\n');
			ifst.close();
			Assert::AreEqual(expected, actual);
		}
		
		TEST_METHOD(FlowerInput)
		{
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Flower_Input.txt");
			flower tmp;
			flower* actual = In(tmp, ifst);
			flower expected;
			expected.tof = flower::type::HOME;
			Assert::AreEqual(int(expected.tof), int(actual->tof));
		}
		
		TEST_METHOD(FlowerOutput)
		{
			ofstream ofst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Flower_Output.txt");
			flower tmp;
			tmp.tof = flower::type::GARDEN;
			Out(tmp, ofst);
			ofst.close();
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Flower_Output.txt");
			string expected = "It is Flower: type = Garden";
			string actual;
			getline(ifst, actual, '\n');
			ifst.close();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PlantInput)
		{
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Plant_Input.txt");
			plant* actual = In(ifst);
			plant expected;
			expected.k = plant::key::TREE;
			expected.name = "Pipe";
			expected.hbt = plant::habitat::STEPPE;
			Assert::AreEqual(int(expected.k), int(actual->k));
			Assert::AreEqual(int(expected.hbt), int(actual->hbt));
			Assert::AreEqual(expected.name, actual->name);

		}

		TEST_METHOD(Plant_Output)
		{
			plant pt;
			pt.k = plant::key::FLOWER;
			pt.name = "Rose";
			pt.hbt = plant::habitat::DESERT;
			pt.f.tof = flower::type::WILD;

			ofstream ofst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Plant_Output.txt");
			Out(pt, ofst);
			ofst.close();
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Plant_Output.txt");
			string actual;
			getline(ifst, actual, '\0');
			ifst.close();
			string expected = "Name = Rose, It is Flower: type = Wild\nHabitat = desert\n";
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(ContainerOutput)
		{
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_In.txt");
			ofstream ofst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_Out.txt");
			LinkedCircledList list;
			Init(list);
			LinkedCircledList_In(list, ifst);
			LinkedCircledList_Out(list, ofst);
			ifst.close();
			ofst.close();
			ifstream expected_output("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_Out_Expected.txt");
			ifstream actual_output("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_Out.txt");
			string actual;
			string expected;
			getline(actual_output, actual, '\0');
			getline(expected_output, expected, '\0');
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SortTest)
		{
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_In.txt");
			ofstream ofst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_Out_Sorted.txt");
			LinkedCircledList list;
			Init(list);
			LinkedCircledList_In(list, ifst);
			sort(list);
			LinkedCircledList_Out(list, ofst);
			ifst.close();
			ofst.close();
			ifstream expected_output("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_Out_Sorted_Expected.txt");
			ifstream actual_output("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_Out_Sorted.txt");
			string actual;
			string expected;
			getline(actual_output, actual, '\0');
			getline(expected_output, expected, '\0');
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TreeOnlyOutputTest)
		{
			ifstream ifst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Container_In.txt");
			ofstream ofst("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Tree_Only_Output.txt");
			LinkedCircledList list;
			Init(list);
			LinkedCircledList_In(list, ifst);
			OutTree(list, ofst);
			ifst.close();
			ofst.close();
			ifstream expected_output("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Tree_Only_Output_Expected.txt");
			ifstream actual_output("C:\\Users\\rusta\\Desktop\\Labs\\Programs\\lab1\\Procedure\\lab1_procTest\\Tests\\Tree_Only_Output.txt");
			string actual;
			string expected;
			getline(actual_output, actual, '\0');
			getline(expected_output, expected, '\0');
			Assert::AreEqual(expected, actual);
		}
	};
}
