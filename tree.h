#ifndef TREE_H
#define TREE_H
/* A binary tree node has data, pointer to left child
and a pointer to right child */
class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
	{
		this->left = nullptr;
		this->right = nullptr;
	}
};
class Tree
{
public:
	TreeNode* root;
	int depth;
	Tree();
	void build_tree();
	bool isBST(TreeNode* root, TreeNode* l, TreeNode* r);
	int maxDepth(TreeNode * root);
	bool isAVL(TreeNode * root);
	bool isMaxHeap(TreeNode * root);
	bool isMinHeap(TreeNode * root);
};

#endif // TREE_H
