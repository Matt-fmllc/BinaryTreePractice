#include "stdafx.h"

#include "BinaryTree.h"

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

	return 0;
}

