// BinaryTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <memory>
#include <cassert>

BinaryTree::BinaryTree() noexcept:
	m_pRootNode(nullptr)
{

}

BinaryTree::~BinaryTree()
{

}

Node* BinaryTree::CreateNode() noexcept
{
	Node* pNode = nullptr;

	pNode = (Node*)malloc(sizeof(Node));
	if (!pNode) {
		//static_assert(0 && "Unable to allocate memory");
		return nullptr;
	}
	else {
		return pNode;
	}
}

bool BinaryTree::AddValue(int* _pValue)
{
	if (_pValue == nullptr) {
		//static_assert(0 && "Passed in bad value");
		return false;
	}

	// check for empty tree
	if (!m_pRootNode) {
		m_pRootNode = CreateNode();
		m_pRootNode->pParent = nullptr;
		m_pRootNode->pLeftChild = nullptr;
		m_pRootNode->pRightChild = nullptr;
		m_pRootNode->pData = _pValue;
		return true;
	}

	// create a node
	Node* pNode = CreateNode();
	if (!pNode) {
		//static_assert(0 && "Unable to allocate new node");
		return false;
	}
	pNode->pData = _pValue;
	pNode->pParent = nullptr;
	pNode->pLeftChild = nullptr;
	pNode->pRightChild = nullptr;

	const bool bInsertSuccess = InsertNode(m_pRootNode, pNode);
	return (bInsertSuccess);
}

bool BinaryTree::InsertNode(Node* _pCurNode, Node* _pNewNode)
{
	assert(_pCurNode);
	if (*_pCurNode->pData <= *_pNewNode->pData) {
		// right branch, value is greater than
		if (_pCurNode->pRightChild != nullptr) {
			// node in place, recurse
			return InsertNode(_pCurNode->pRightChild, _pNewNode);
		}
		else {
			// available slot
			_pCurNode->pRightChild = _pNewNode;
			_pNewNode->pParent = _pCurNode;
			return true;
		}
	}
	else {
		// left branch, value is lesser than
		if (_pCurNode->pLeftChild != nullptr) {
			// node is in place, recurse
			return InsertNode(_pCurNode->pLeftChild, _pNewNode);
		}
		else {
			// available slot
			_pCurNode->pLeftChild = _pNewNode;
			_pNewNode->pParent = _pCurNode;
			return true;
		}
	}
}

bool BinaryTree::Traverse(Node* _pNode, int _iValue)
{
	assert(_pNode);

	if (*_pNode->pData == _iValue)
		return true;

	if (*_pNode->pData <= _iValue) {
		// right branch
		if (_pNode->pRightChild) {
			return Traverse(_pNode->pRightChild, _iValue);
		}
		else {
			return false;
		}
	}
	else {
		if (_pNode->pLeftChild) {
			return Traverse(_pNode->pLeftChild, _iValue);
		}
		else {
			return false;
		}
	}
}

bool BinaryTree::SearchTree(int _iValue)
{
	bool bResult = false;

	if (m_pRootNode == nullptr)
		return false;
	
	if (*m_pRootNode->pData == _iValue)
		return true;
	else {
		bResult = Traverse(m_pRootNode, _iValue);
	}
	return bResult;
}