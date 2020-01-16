#ifndef PRINT_H
#define PRINT_H
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
/* This Class And The Two Founction Is For The Beutifull Output Of Tree*/
class Trunk
{
public:
	Trunk *prev;
	string str;
	Trunk(Trunk *prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
	if (p == nullptr)
		return;

	showTrunks(p->prev);

	cout << p->str;
}
// Recursive function to print binary tree
// It uses inorder traversal
void printTree(TreeNode *root, Trunk *prev, bool isLeft)
{
	if (root == nullptr)
		return;

	string prev_str = "    ";
	Trunk *trunk = new Trunk(prev, prev_str);

	printTree(root->right, trunk, true);

	if (!prev)
		trunk->str = "---";
	else if (isLeft)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << root->data << endl;

	if (prev)
		prev->str = prev_str;
	trunk->str = "   |";

	printTree(root->left, trunk, false);
}
void title()
{
	cout <<"\t\t      /$$$$$$$  /$$                                      /$$$$$$$$                           \n"<<
		   "\t\t     | $$__  $$|__/                                     |__  $$__/                           \n"<<
		   "\t\t     | $$  \\ $$ /$$ /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$| $$  /$$$$$$   /$$$$$$   /$$$$$$ \n"<<
		   "\t\t     | $$$$$$$ | $$| $$__  $$ |____  $$ /$$__  $$| $$  | $$| $$ /$$__  $$ /$$__  $$ /$$__  $$\n"<<
		   "\t\t     | $$__  $$| $$| $$  \\ $$  /$$$$$$$| $$  \\__/| $$  | $$| $$| $$  \\__/| $$$$$$$$| $$$$$$$$\n"<<
		   "\t\t     | $$  \\ $$| $$| $$  | $$ /$$__  $$| $$      | $$  | $$| $$| $$      | $$_____/| $$_____/\n"<<
		   "\t\t     | $$$$$$$/| $$| $$  | $$|  $$$$$$$| $$      |  $$$$$$$| $$| $$      |  $$$$$$$|  $$$$$$$\n"<<
		   "\t\t     |_______/ |__/|__/  |__/ \\_______/|__/       \\____  $$|__/|__/       \\_______/ \\_______/\n"<<
		   "\t\t                                                  /$$  | $$                                  \n"<<
		   "\t\t                                                 |  $$$$$$/                                  \n"<<
		   "\t\t               [+] Coded By H.S [+]               \\______/        [+] ID:973613035 [+]        \n"<< endl;
	cout << endl << endl;
}
/* The End */
#endif // PRINT_H
