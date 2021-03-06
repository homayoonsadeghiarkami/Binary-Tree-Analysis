#include <windows.h>
#include "tree.h"
#include "consoletable.h"
using namespace std;
// Driver code
int main()
{
	// This 6 Lines is to set Your Console Size The Right One
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1150, 700, TRUE);
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	// The End

	Tree tree;
	tree.make();
	string IsBST , IsAVL, IsMaxHeap, IsMinHeap ;
	if(tree.isBST(tree.root,nullptr,nullptr))
	{
		IsBST = "True";
		if(tree.isAVL(tree.root))
		{
			IsAVL = "True";
		}
		else
		{
			IsAVL = "False";
		}
	}
	else
	{
		IsBST = "False";
		IsAVL = "False";
	}
	if(tree.isMaxHeap(tree.root))
	{
		IsMaxHeap = "True";
	}
	else
	{
		IsMaxHeap = "False";
	}
	if(tree.isMinHeap(tree.root))
	{
		IsMinHeap = "True";
	}
	else
	{
		IsMinHeap = "False";
	}
	cout << "\t\n\n\tThe Result:"<<endl << endl ;
	ConsoleTable table{"Depth", "BST", "AVL", "Max Heap", "Min Heap"};
	table.setPadding(2);
	table.setStyle(0);
	table += {std::to_string(tree.maxDepth(tree.root) - 1), IsBST, IsAVL, IsMaxHeap, IsMinHeap};
	std::cout << table;
}
