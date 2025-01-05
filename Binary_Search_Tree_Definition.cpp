#include<iostream>
#include"Binary_Search_Tree.h"
using namespace std;

IntBinaryTree::IntBinaryTree() {
	root = nullptr;
}

bool IntBinaryTree::search(string num) {
	TreeNode* nodePtr = root;

	while (nodePtr != nullptr) {
		if (nodePtr->value == num) {
			return true;
		}
		else if (num < nodePtr->value) {
			nodePtr = nodePtr->left;
		}
		else {
			nodePtr = nodePtr->right;
		}
	}

	return false;
}

void IntBinaryTree::insertNode(string num) {
	TreeNode* newNode = new TreeNode{ num, nullptr, nullptr };

	if (!root) {
		root = newNode;
		return;
	}

	TreeNode* nodePtr = root;
	TreeNode* parentPtr = nullptr;

	while (nodePtr != nullptr) {
		parentPtr = nodePtr;
		if (num < nodePtr->value) {
			nodePtr = nodePtr->left;
		}
		else if (num > nodePtr->value) {
			nodePtr = nodePtr->right;
		}
		else {
			cout << "Duplicate value found in tree.\n";
			return;
		}
	}

	if (num < parentPtr->value) {
		parentPtr->left = newNode;
	}
	else {
		parentPtr->right = newNode;
	}
}

void IntBinaryTree::deleteNode(string num, TreeNode*& nodePtr) {
	if (nodePtr == nullptr) {
		cout << num << " Not found.\n";
		return;
	}

	if (num < nodePtr->value) {
		deleteNode(num, nodePtr->left);
	}
	else if (num > nodePtr->value) {
		deleteNode(num, nodePtr->right);
	}
	else {
		makeDeletion(nodePtr);
	}
}

void IntBinaryTree::makeDeletion(TreeNode*& nodePtr) {
	TreeNode* tempNodePtr;

	if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else {
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left) {
			tempNodePtr = tempNodePtr->left;
		}
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

void IntBinaryTree::displayInOrder(TreeNode* nodePtr) {
	if (nodePtr != nullptr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << " ";
		displayInOrder(nodePtr->right);
	}
}
