#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\\BinaryTree\TBinaryTree.h"
using namespace BinaryTreeTemplate;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeUnitTests
{		
	const int iTestRuns = 2500;


	TEST_CLASS(BinaryTreeTemplate_UnitTests)
	{
	public:


		TEST_METHOD(PutSearchTests)
		{
			TBinaryTree<int, CompareFunction<int>> BTree;

			int iTestVals[iTestRuns] = { 0 };
			std::srand(7654321);
			for (int x = 0; x < iTestRuns; x++) {
				iTestVals[x] = std::rand();
				BTree.Put(iTestVals[x]);
			}

			bool bRetVal = false;
			for (int x = 0; x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x]);
				Assert::IsTrue(bRetVal);
			}
		}

		TEST_METHOD(PutSearchNegativeTests)
		{
			TBinaryTree<int, CompareFunction<int>> BTree;

			int iTestVals[iTestRuns] = { 0 };
			std::srand(7654321);
			for (int x = 0; x < iTestRuns; x++) {
				iTestVals[x] = std::rand();
				BTree.Put(iTestVals[x]);
			}

			bool bRetVal = false;
			for (int x = 0; x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x] * -1);
				Assert::IsFalse(bRetVal);
			}
		}

		TEST_METHOD(PutRemoveTests)
		{
			TBinaryTree<int, CompareFunction<int>> BTree;

			// add a bunch of nodes to the tree
			int iTestVals[iTestRuns] = { 0 };
			std::srand(7654321);
			for (int x = 0; x < iTestRuns; x++) {
				iTestVals[x] = std::rand();
				BTree.Put(iTestVals[x]);
			}

			// check if all those nodes got added
			bool bRetVal = false;
			for (int x = 0; x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x]);
				Assert::IsTrue(bRetVal);
			}

			// now remove half the nodes
			for (int x = 0; x < (iTestRuns/2); x++) {
				BTree.Remove(iTestVals[x]);
			}
			
			// now test to see if the remainder of the nodes 
			// are still in the tree
			for (int x = (iTestRuns / 2); x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x]);
				Assert::IsTrue(bRetVal);
			}

			// now add the removed ones back
			for (int x = 0; x < (iTestRuns / 2); x++) {
				BTree.Put(iTestVals[x]);
			}

			// now check to see if all are there again
			for (int x = 0; x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x]);
				Assert::IsTrue(bRetVal);
			}
		}

		TEST_METHOD(PutRemoveNegativeTests)
		{
			TBinaryTree<int, CompareFunction<int>> BTree;

			// add a bunch of nodes to the tree
			int iTestVals[iTestRuns] = { 0 };
			std::srand(7654321);
			for (int x = 0; x < iTestRuns; x++) {
				iTestVals[x] = std::rand();
				BTree.Put(iTestVals[x]);
			}

			// check if all those nodes got added
			bool bRetVal = false;
			for (int x = 0; x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x]);
				Assert::IsTrue(bRetVal);
			}

			// now remove half the nodes
			for (int x = 0; x < (iTestRuns / 2); x++) {
				BTree.Remove(iTestVals[x]);
			}

			// now test to see if the remainder of the nodes 
			// are still in the tree
			for (int x = (iTestRuns / 2); x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x]);
				Assert::IsTrue(bRetVal);
			}

			// now add the removed ones back
			for (int x = 0; x < (iTestRuns / 2); x++) {
				BTree.Put(iTestVals[x]);
			}

			// now check to see if all are there again
			for (int x = 0; x < iTestRuns; x++) {
				bRetVal = BTree.Search(iTestVals[x] * -1);
				Assert::IsFalse(bRetVal);
			}
		}
	};
}