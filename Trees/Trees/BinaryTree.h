#pragma once

#include <vector>

struct Node
{
	Node(const int key = 13, Node *leftChild = nullptr, Node *rightChild = nullptr) :
		key(key),
		leftChild(leftChild),
		rightChild(rightChild)
	{}

	int key = 10;
	Node *leftChild = nullptr;
	Node *rightChild = nullptr;
};

class BinaryTree
{
public:
	BinaryTree() = default;

	Node *getRoot();
	Node *addNode(Node *subTreeRoot, const int key);
	virtual bool findAndEraseNode(Node *subTreeRoot, const int key);

	void printHorizontal();
	void printHorizontal(Node *subTreeRoot, const int level = 0);

	void printLevel(const int level);
	void printLevel(Node *subTreeRoot, const int level, const int currentLevel = 0);

protected:
	Node *m_root = nullptr;
};

class SearchTree : public BinaryTree
{
public:
	SearchTree() = default;

	bool findAndEraseNode(Node *subTreeRoot, const int key) override;

	//Всё, что ниже - только на оценку "4".
	static SearchTree buildOptimalSearchTree(
		const std::vector<int> &keysAscending, 
		const std::vector<int> &equalKeysFrequences,
		const std::vector<int> &betweenKeysFrequences
	);

private:
	static std::vector<std::vector<int>> calculateOptimalTreeNodesMatrix(
		const std::vector<int> &keysAscending,
		const std::vector<int> &equalKeysFrequences,
		const std::vector<int> &betweenKeysFrequences
	);

	static Node *buildOptimalSearchTree(
		const std::vector<int> &keysAscending,
		const std::vector<std::vector<int>> &nodesIndexesMatrix,
		const int nodeIndexRow, const int nodeIndexColumn
	);
};
