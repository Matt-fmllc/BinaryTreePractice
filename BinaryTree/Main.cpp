#include "stdafx.h"

#include "BinaryTree.h"

#include "TBinaryTree.h"
using namespace BinaryTreeTemplate;

int main()
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

	return 0;
}

