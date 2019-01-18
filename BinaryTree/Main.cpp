#include "stdafx.h"

#include "BinaryTree.h"

#include "TBinaryTree.h"
using namespace BinaryTreeTemplate;


void StandardBinaryTreePractice()
{
	BinaryTree* pBinaryTree = nullptr;
	int Values[] = { 3,5,7,0 };
	int Count = sizeof(Values) / sizeof(int);

	pBinaryTree = new BinaryTree();
	for (int x = 0; x < Count; x++) {
		pBinaryTree->AddValue(&Values[x]);
	}

	pBinaryTree->SearchTree(7);
	pBinaryTree->SearchTree(0);
	pBinaryTree->SearchTree(13);

}

void TemplateBinaryTreePractice()
{

	printf("\n Int Implementation");
	TBinaryTree<int, CompareFunction<int>> BTree;
	BTree.Put(0);
	BTree.Put(2);
	BTree.Put(1);
	BTree.Put(3);
	BTree.Put(4);
	BTree.Put(1);

	BTree.Search(2);
	BTree.Search(5);
	BTree.Search(1);

	BTree.PrintTree();
	printf("\n");
	BTree.Remove(2);
	BTree.PrintTree();
	printf("\n");
	BTree.Put(2);
	BTree.PrintTree();


	printf("\n Float Implementation");
	TBinaryTree<float, CompareFunction<float>> BTree2;
	BTree2.Put(0.f);
	BTree2.Put(2.2f);
	BTree2.Put(1.1f);
	BTree2.Put(3.3f);
	BTree2.Put(4.4f);
	BTree2.Put(1.2f);

	BTree2.Search(2.2f);
	BTree2.Search(5.1f);
	BTree2.Search(1.1f);
	BTree2.Search(1.2f);

	BTree2.PrintTree();
}

int main()
{
	StandardBinaryTreePractice();
	TemplateBinaryTreePractice();

	return 0;
}

