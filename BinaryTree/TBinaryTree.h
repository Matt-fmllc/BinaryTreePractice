#pragma once


/////////////////////////////////////////////////////////////////
//
//	Binary Tree Template
//
//	Matthew Altman
//	1-15-19
//	
/////////////////////////////////////////////////////////////////


// <NOTE><MA> improvements:
//		a non-recursive implementation
//		iterators



namespace BinaryTreeTemplate
{

	//forward declaration
	template< typename O, typename F = CompareFunc<O> >
	class TBinaryTree;

	template<typename O>
	class TNode;

	// Compare Function
	// Binary Tree uses this function to order the tree
	// there are only 3 outcomes allowed 
	// a return value of 0 denotes one path
	// a return value of 1 denotes the other path
	// a return value of 2 denotes equality
	// ONLY 0,1 or 2 are valid responses from this function
	// all other return values are ignored

	template<typename O>
	struct CompareFunction {
		virtual unsigned long operator()(TNode<O>* Obj1, TNode<O>* Obj2) const
		{
			// 1 is greater than 2
			if (Obj1->Data > Obj2->Data) {
				return 0;
			}
			// 1 is less than 2
			else if (Obj1->Data < Obj2->Data) {
				return 1;
			}
			// 1 is equal to 2
			else {
				return 2;
			}
		}
	};


	// Binary Tree Node (Template)
	// Data element of the tree
	// maintains the tree structure
	// stores the data element

	template<typename O>
	class TNode 
	{
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


	// Template Binary Tree
	// O(n) = O(log n) on average, O(n) in worst case
	// 
	// Generic Binary Tree Implementation
	// Basic Methods
	//	Put - adds an element to the tree
	//  Remove - removes an element from the tree
	//  Search - returns data the element
	//
	// User must implement the Compare function
	// Since the objects are an unknown type
	// an example, or a default one, exists 
	// for use at the top of the file

	template< typename O, typename F = CompareFunc<O> >
	class TBinaryTree
	{
	private:
		TNode<O>*	m_pRoot;
		F			CompFunc;

		bool RecurseAdd(TNode<O>* pCurNode, TNode<O>* pNewNode);
		bool RecurseRemove(TNode<O>* pCurNode, TNode<O>* pNewNode);
		bool RecurseSearch(TNode<O>* pCurNode, TNode<O>* pNewNode);
		
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
	

	// RecurseAdd
	// Recursive Add to the tree implementation
	template<typename O, typename F = CompareFunc<O> >
	bool TBinaryTree<O, F>::RecurseAdd(TNode<O>* pCurNode, TNode<O>* pNewNode)
	{
		unsigned long iVal = CompFunc(pCurNode, pNewNode);
		if (iVal == 0 || iVal == 2) {
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

	// Put
	// external interface for adding elements to the tree
	template<typename O, typename F = CompareFunc<O> >
	bool TBinaryTree<O, F>::Put(const O& Object)
	{
		TNode<O>* pNode = new TNode<O>(Object);

		if (!m_pRoot) {
			m_pRoot = pNode;
			return true;
		}

		return RecurseAdd(m_pRoot, pNode);
	}

	// RecurseRemove
	// Recursive Removal to the tree implementation
	template<typename O, typename F = CompareFunc<O> >
	bool TBinaryTree<O, F>::RecurseRemove(TNode<O>* pCurNode, TNode<O>* pSearchNode)
	{
		unsigned long iVal = CompFunc(pCurNode, pSearchNode);
		if (iVal == 2) {
			// node found
			printf("\nFound Node");
		}
		else if (iVal == 0) {
			// right branch
			if (pCurNode->pRight == nullptr) {
				return false;
			}
			else {
				RecurseRemove(pCurNode->pRight, pSearchNode);
			}
		}
		else if (iVal == 1) {
			// left branch
			if (pCurNode->pLeft == nullptr) {
				return false;
			}
			else {
				RecurseRemove(pCurNode->pLeft, pSearchNode);
			}
		}
		return true;
	}

	// Remove
	// external interface for removing elements from the tree
	template<typename O, typename F = CompareFunc<O> >
	bool TBinaryTree<O, F>::Remove(const O& Object)
	{
		bool bSuccess = false;

		TNode<O>* pSearchNode = new TNode<O>(Object);
		
		// check for empty list
		if (m_pRoot == nullptr) {
			bSuccess = false;
		}
		else {
			bSuccess = RecurseRemove(m_pRoot, pSearchNode);
		}

		// delete the node that was created for the search
		delete pSearchNode; 

		// return success
		return bSuccess;
	}

	// RecurseSearch
	// Recursively Search implementation for tree
	template<typename O, typename F = CompareFunc<O> >
	bool TBinaryTree<O, F>::RecurseSearch(TNode<O>* pCurNode, TNode<O>* pSearchNode)
	{
		unsigned long iVal = CompFunc(pCurNode, pSearchNode);
		if (iVal == 2) {
			// node found
			return true;
		}
		else if (iVal == 0) {
			// right branch
			if (pCurNode->pRight == nullptr) {
				return false;
			}
			else {
				return RecurseSearch(pCurNode->pRight, pSearchNode);
			}
		}
		else if (iVal == 1) {
			// left branch
			if (pCurNode->pLeft == nullptr) {
				return false;
			}
			else {
				return RecurseSearch(pCurNode->pLeft, pSearchNode);
			}
		}

		return false; // to get around compiler warning
	}

	// Search
	// external interface for fetching elements in the tree
	template<typename O, typename F = CompareFunc<O> >
	bool TBinaryTree<O, F>::Search(const O& Object)
	{
		bool bSuccess = false;

		TNode<O>* pSearchNode = new TNode<O>(Object);

		// check for empty list
		if (m_pRoot == nullptr) {
			bSuccess = false;
		}
		else {
			bSuccess = RecurseSearch(m_pRoot, pSearchNode);
		}

		// delete the node that was created for the search
		delete pSearchNode;

		// return success
		return bSuccess;
	}


} // end namespace