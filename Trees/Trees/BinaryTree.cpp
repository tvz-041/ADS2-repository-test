#include <random>
#include <iostream>

#include "BinaryTree.h"

Node *BinaryTree::getRoot()
{
	return m_root;
}

Node *BinaryTree::addNode(Node *subTreeRoot, const int key)
{
	if (subTreeRoot == nullptr) {
		if (m_root == nullptr) {
			m_root = new Node(key);
			return m_root;
		} else {
			return nullptr;
		}
	}

	if (subTreeRoot->leftChild == nullptr) {
		subTreeRoot->leftChild = new Node(key);
		return subTreeRoot->leftChild;
	} else if (subTreeRoot->rightChild == nullptr) {
		subTreeRoot->rightChild = new Node(key);
		return subTreeRoot->rightChild;
	} else {
		if (rand() % 2) {
			return addNode(subTreeRoot->leftChild, key);
		} else {
			return addNode(subTreeRoot->rightChild, key);
		}
	}
}

bool BinaryTree::findAndEraseNode(Node * subTreeRoot, const int key)
{
	//TODO: реализовать
	return false;
}

void BinaryTree::printHorizontal()
{
	printHorizontal(m_root);
}

void BinaryTree::printHorizontal(Node *subTreeRoot, const int level)
{
	using std::cout;
	using std::endl;

	if (subTreeRoot == nullptr) {
		if (subTreeRoot == m_root) {
			cout << "Tree is empty" << endl;
		}
		return;
	}

	printHorizontal(subTreeRoot->rightChild, level + 1);

	for (int i = 0; i < level; i++)
		cout << "   ";
	cout << subTreeRoot->key << endl;
	
	printHorizontal(subTreeRoot->leftChild, level + 1);
}

void BinaryTree::printLevel(const int level)
{
	printLevel(m_root, level, 0);
}

void BinaryTree::printLevel(Node * subTreeRoot, const int level, const int currentLevel)
{
	using std::cout;
	using std::endl;

	if (subTreeRoot == nullptr) {
		if (subTreeRoot == m_root) {
			cout << "Tree is empty" << endl;
		}
		return;
	}

	if (currentLevel == level) {
		cout << subTreeRoot->key << "   ";
	} else if (currentLevel < level) {
		printLevel(subTreeRoot->leftChild, level, currentLevel + 1);
		printLevel(subTreeRoot->rightChild, level, currentLevel + 1);
	}
}
