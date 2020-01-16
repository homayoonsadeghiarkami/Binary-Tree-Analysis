#ifndef TRUNK_H
#define TRUNK_H
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
/* This Class And The Two Founction Is For The Beutifull Output Of Tree*/
class Trunk
{
public:
	Trunk *prev;
	string str;
	Trunk(Trunk *prev, string str);
	void showTrunks(Trunk *p);
	void printTree(TreeNode *root, Trunk *prev, bool isLeft);
};

#endif // TRUNK_H
