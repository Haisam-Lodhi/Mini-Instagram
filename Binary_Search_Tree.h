#pragma once

#include <string>
using namespace std;

struct TreeNode {
	string value;
	TreeNode* left;
	TreeNode* right;
};

class IntBinaryTree {
private:
	TreeNode* root;

	void makeDeletion(TreeNode*&);
	void deleteNode(string, TreeNode*&);
	void displayInOrder(TreeNode*);

public:
	IntBinaryTree();

	void insertNode(string);
	bool search(string);
	void showNodesInOrder() { displayInOrder(root); }
};
