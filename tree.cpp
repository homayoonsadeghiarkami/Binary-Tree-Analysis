#include "tree.h"
#include "supporting.h"
/*  BTree Constructor */
Tree::Tree()
{
	this->root = new TreeNode;
}
//// Founction To make User BTree
void Tree::build_tree()
{
	queue<TreeNode*> queue;
	int data;
	title();
	cout << "\t\t [+]Enter The Root:";
	cin >> data;
	while(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("cls");
		title();
		cout << "\t\t [+]Enter The Root:";
		std::cin >> data;
	}
	system("cls");
	title();
	this->root->data = data;
	queue.push(this->root);
	cout << endl << endl;
	printTree(this->root,nullptr,false);
	while( !queue.empty() )
	{
		cout <<"\n\n\n";
		string cmd;
		TreeNode* p = queue.front();
		queue.pop();
		cout << "\t\t If The Node That is Represented In Next Line Has Child Enter It's Data In Numeric Form Otherwise Enter \"no\" to Pass It:";
		cout << "\n\t\t Node With Data " << p->data << ":" << endl;
		cout << "\t\t [+]Enter The Left Child :";
		cin >> cmd;
		if(cmd != "no")
		{
			TreeNode* t = new TreeNode;
			p->left = t;
			t->data = stoi(cmd);
			queue.push(t);
		}
		else
		{
			p->left = nullptr;
		}
		cout <<"\t\t [+]Enter The Right Child :";
		cin >> cmd;
		if(cmd != "no")
		{
			TreeNode * t = new TreeNode;
			p->right = t;
			t->data = stoi(cmd);
			queue.push(t);
		}
		else
		{
			p->right = nullptr;
		}
		system("cls");
		title();
		cout <<endl<<endl;
		printTree(this->root,nullptr,false);
	}
	system("cls");
	title();
	cout << "\t\n\tYour Tree:"<<endl << endl;
	printTree(this->root,nullptr,false);
}

/* Returns true if given tree is BST.
 * Time Complexity: O(n)
 * Auxiliary Space : O(1) if Function Call Stack size is not considered, otherwise O(n)*/
bool Tree::isBST(TreeNode* root, TreeNode* l = nullptr, TreeNode* r = nullptr)
{
	// Base condition
	if (root == nullptr)
		return true;

	// if left node exist then check it has
	// correct data or not i.e. left node's data
	// should be less than root's data
	if (l != nullptr and root->data <= l->data)
		return false;

	// if right node exist then check it has
	// correct data or not i.e. right node's data
	// should be greater than root's data
	if (r != nullptr and root->data >= r->data)
		return false;

	// check recursively for every node.
	return isBST(root->left, l, root) and
			isBST(root->right, root, r);
}
/* Compute the "maxDepth" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.
	Time Complexity: O(n)*/
int Tree::maxDepth(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);
		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

/* Returns true if binary tree
with root as root is height-balanced
Time Complexity: O(n^2) Worst case occurs in case of skewed tree.*/
bool Tree::isAVL(TreeNode * root)
{
	int lDepth;/* for height of left subtree */
	int rDepth;/* for height of right subtree */
	/* If tree is empty then return true */
	if(root == nullptr)
		return true;

	/* Get the height of left and right sub trees */
	lDepth = this->maxDepth(root->left);
	rDepth = this->maxDepth(root->right);

	if (abs(lDepth - rDepth) <= 1 && this->isAVL(root->left) && this->isAVL(root->right))
		return true;
	/* If we reach here then
	tree is not height-balanced */
	return false;
}
//  Function to check binary tree is a Max-Heap or Not.
bool Tree::isMaxHeap(TreeNode * root)
{
	//  Base case : single node & Empty Tree satisfy property
	if(root == nullptr or (root->left == nullptr and root->right == nullptr))
		return true;
	bool flag1 = false;
	bool flag2 = false;
	if(root->left and root->data >= root->left->data)
		flag1 = true;
	if(root->right and root->data >= root->right->data)
		flag2 = true;
	return ((flag1 and flag2) and isMaxHeap(root->left) and isMaxHeap(root->right));
}

//  Function to check binary tree is a Min-Heap or Not.
bool Tree::isMinHeap(TreeNode * root)
{
	//  Base case : single node & Empty Tree satisfy property
	if(root == nullptr or (root->left == nullptr and root->right == nullptr))
		return true;
	bool lNode = false;
	bool rNode = false;
	if(root->left and root->data <= root->left->data)
		lNode = true;
	if(root->right and root->data <= root->right->data)
		rNode = true;
	return ((lNode and rNode) and isMinHeap(root->left) and isMinHeap(root->right));
}
