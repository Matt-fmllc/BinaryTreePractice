#pragma once



typedef struct _Node
{
	_Node* pParent;
	_Node* pLeftChild;
	_Node* pRightChild;

	int*   pData;
} Node;

 
class BinaryTree
{
private:
	Node*	m_pRootNode;

protected:
	Node* CreateNode() noexcept;
	bool InsertNode(Node* pCurNode, Node* pNewNode);
	bool Traverse(Node* _pNode, int _iValue);

public:
	BinaryTree() noexcept;
	~BinaryTree();

	bool AddValue(int* _pValue);
	bool SearchTree(int _iValue);
};

