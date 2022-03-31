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

bool SearchTree::findAndEraseNode(Node * subTreeRoot, const int key)
{
	//TODO: реализовать
	return false;
}

SearchTree SearchTree::buildOptimalSearchTree(
	const std::vector<int>& keysAscending,			//d
	const std::vector<int>& equalKeysFrequences,	//p
	const std::vector<int>& betweenKeysFrequences)	//q
{
	//1. Получаем матрицу R.
	std::vector<std::vector<int>> nodesIndexesMatrix = calculateOptimalTreeNodesMatrix(
													   	   keysAscending,
													   	   equalKeysFrequences,
													   	   betweenKeysFrequences
													   );
	//2. Строим дерево по матрице R.
	SearchTree optimalTree;
	optimalTree.m_root = buildOptimalSearchTree(
							 keysAscending, 
							 nodesIndexesMatrix,
							 0, nodesIndexesMatrix.size()
						 ); //Вернёт nullptr, если матрица оказалась пустой
	return optimalTree;
}

std::vector<std::vector<int>> SearchTree::calculateOptimalTreeNodesMatrix(
	const std::vector<int> &keysAscending,
	const std::vector<int> &equalKeysFrequences,
	const std::vector<int> &betweenKeysFrequences)
{
	int nodesCount = keysAscending.size();

	if (equalKeysFrequences.size() != nodesCount || betweenKeysFrequences.size() != nodesCount + 1) {
		return std::vector<std::vector<int>>();
	}

	std::vector<std::vector<int>> costMatrix(nodesCount + 1, std::vector<int>(nodesCount + 1, -1));			//C
	std::vector<std::vector<int>> weightMatrix(nodesCount + 1, std::vector<int>(nodesCount + 1, -1));		//W
	std::vector<std::vector<int>> nodesIndexesMatrix(nodesCount + 1, std::vector<int>(nodesCount + 1, -1));	//R
	
	//TODO: реализовать

	return nodesIndexesMatrix;
}

Node *SearchTree::buildOptimalSearchTree(
	const std::vector<int>& keysAscending, 
	const std::vector<std::vector<int>>& nodesIndexesMatrix,
	const int nodeIndexRow, const int nodeIndexColumn)
{
	if (nodeIndexRow >= nodeIndexColumn) {
		return nullptr;
	}
	//WARNING: индексы/номера отличаются от лекций, разбирали на практике.
	int keyIndex = nodesIndexesMatrix[nodeIndexRow][nodeIndexColumn];
	Node *node = new Node(keysAscending[keyIndex]);

	node->leftChild = buildOptimalSearchTree(
						  keysAscending,
						  nodesIndexesMatrix,
						  nodeIndexRow, keyIndex
					  );

	node->rightChild = buildOptimalSearchTree(
						   keysAscending,
						   nodesIndexesMatrix,
						   keyIndex + 1, nodeIndexColumn
					   );

	return node;
}
