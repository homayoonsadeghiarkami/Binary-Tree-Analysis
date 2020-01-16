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
	tree.build_tree();
	tree.depth = tree.maxDepth(tree.root);
	cout << "\n\n\tDepth: " << tree.depth - 1 ;
	bool result = tree.isBST(tree.root,nullptr,nullptr);
	cout <<"\n\tBSD : ";
	if(result)
	{
		cout<<"True";
		if(tree.isAVL(tree.root))
		{
			cout << "\n\tAVL : True"<<endl;
		}
		else
		{
			cout << "\n\tAVL : False"<<endl;
		}
	}
	else
	{
		cout<<"False";
		cout<<"\n\tAVL : False"<<endl;
	}
	if(tree.isMaxHeap(tree.root))
	{
		cout <<"\tMax Heap : True\n";
	}
	else
	{
		cout <<"\tMax Heap : False\n";
	}
	if(tree.isMinHeap(tree.root))
	{
		cout <<"\tMin Heap : True\n";
	}
	else
	{
		cout <<"\tMin Heap : False\n";
	}

	ConsoleTable table{"Depth", "BST", "AVL", "Max Heap", "Min Heap"};
	table.setPadding(2);
	table.setStyle(0);
	table += {std::to_string(125), "Flase", "True", "Flase", "Flase"};

	std::cout << table;

	while (true) {}
}

//#include <iostream>
//using namespace std;
//bool is_digits(const std::string &str)
//{
//	return str.find_first_not_of("0123456789") == std::string::npos;
//}
//int main(void)
//{
//	std::string name;

//	std::getline(std::cin, name);
//	while(name.empty())
//	{
//		cout << "Ridiiiiiiiiiiiiiiiiiiiii" << endl;
//		std::getline(std::cin, name);
//	}
//	if(is_digits(name))
//	{
//		cout << "The String You Enter is digit" << endl;
//	}
//	else {
//		cout << "Fuck Offffff" << endl;
//	}
//	cout << name << endl;
//}

