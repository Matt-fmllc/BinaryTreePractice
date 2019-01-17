#pragma once

//forward declaration
template<typename O, typename F = CompareFunc<O>>
class TBinaryTree;

template<typename O>
class TNode;

template<typename O>
struct CompareFunction {
	virtual unsigned long operator()( TNode<O>* Obj1, TNode<O>* Obj2) const
	{
		if (Obj1->Data >= Obj2->Data) {
			return 0;
		}
		else
			return 1;
	}
};

template<typename O>
class TNode {
private:
protected:
public:
	O		Data;
	TNode*	pLeft;
	TNode*  pRight;
	// can add a pointer to the parent for convienience
	//CNode* pParent;

	TNode(const O& Obj) :
		Data(Obj), pLeft(nullptr), pRight(nullptr)
	{

	}
	~TNode() {}
};

template< typename O, typename F = CompareFunc<O> >
class TBinaryTree
{
private:
	TNode<O>*	m_pRoot;
	F			CompFunc;

	bool RecurseAdd(TNode<O>* pCurNode, TNode<O>* pNewNode);

protected:
public:
	TBinaryTree() :
		m_pRoot(nullptr)
	{

	}
	
	virtual ~TBinaryTree()
	{

	}

	inline bool Put(const O& Object);
	inline bool Remove(const O& Object);
	inline bool Search(const O& Object);
};

template<typename O, typename F = CompareFunc<O> >
bool TBinaryTree<O, F>::RecurseAdd(TNode<O>* pCurNode, TNode<O>* pNewNode)
{
	unsigned long iVal = CompFunc(pCurNode, pNewNode);
	if (iVal == 0) {
		// right branch
		if (pCurNode->pRight != nullptr) {
			RecurseAdd(pCurNode->pRight, pNewNode);
		}
		else {
			pCurNode->pRight = pNewNode;
		}
	}
	else if (iVal == 1) {
		// left branch
		if (pCurNode->pLeft != nullptr) {
			RecurseAdd(pCurNode->pLeft, pNewNode);
		}
		else {
			pCurNode->pLeft = pNewNode;
		}
	}
	else {
		// something happened, should always be a 1 or 0 returned
	}
	return true;
}

template<typename O, typename F = CompareFunc<O> >
bool TBinaryTree<O,F>::Put(const O& Object)
{
	TNode<O>* pNode = new TNode<O>(Object);
	
	if (!m_pRoot) {
		m_pRoot = pNode;
		return true;
	}

	return RecurseAdd(m_pRoot, pNode);
}

template<typename O, typename F = CompareFunc<O> >
bool TBinaryTree<O,F>::Remove(const O& Object)
{
	return true;
}

template<typename O, typename F = CompareFunc<O> >
bool TBinaryTree<O,F>::Search(const O& Object)
{
	return true;
}
