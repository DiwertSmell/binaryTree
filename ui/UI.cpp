#include <stdlib.h>
#include "UI.h"

//------------------------------------------------------------------------------

UI::UI()
{
	_binary_tree = nullptr;
}

UI::~UI()
{
	delete _binary_tree;
}

//------------------------------------------------------------------------------

void UI::Start()
{
	cout << "|\t b i n a r y \t t r e e \t |";
	PrintMore("-", 42);

	cout << "Let's start..." << endl;
}

void UI::Launcher()
{
	SearchTree search_tree;
	int start_size_tree = SetSizeOfTree();

	search_tree.MakeBinaryTree(&_binary_tree, start_size_tree);

	cout << endl << "Well..."; PrintMore("-", 84);
	cout << endl << "--> ";

	string command;
	cin >> command;

	while (command != EXIT)
	{
		if (command == MAKE_BINARY_TREE)
		{
			int start_size_tree = SetSizeOfTree();
			search_tree.MakeBinaryTree(&_binary_tree, start_size_tree);

			PrintMore("-", 84);
		}
		if (command == UI_LKP)
		{
			PrintMore("-", 84);
			cout << "Your binary tree search: " << endl;

			search_tree.LKP(_binary_tree);
			PrintMore("-", 84);
		}
		if (command == UI_LPK)
		{
			PrintMore("-", 84);
			cout << "Your binary tree search: " << endl;

			search_tree.LPK(_binary_tree);
			PrintMore("-", 84);
		}
		if (command == UI_KLP)
		{
			PrintMore("-", 84);
			cout << "Your binary tree search: " << endl;

			search_tree.KLP(_binary_tree);
			PrintMore("-", 84);
		}
		if (command == INSERT)
		{
			PrintMore("-", 84);
			cout << "| Enter the insert element: ";

			int insert_element;
			cin >> insert_element;

			search_tree.Insert(&_binary_tree, insert_element);
			PrintMore("-", 84);
		}
		if (command == SEARCH)
		{
			PrintMore("-", 84);
			cout << "Enter the searching element: ";

			int element;
			cin >> element;

			if (search_tree.SearchNodeByKey(_binary_tree, element) == true)
			{
				cout << "*YES*" << endl;
				cout << "There is such an element in the tree";
				PrintMore("-", 84);
			}
			else
			{
				cout << "*NO*" << endl;
				cout << "There is no such element in the tree";
				PrintMore("-", 84);
			}
		}
		if (command == COUNT)
		{
			PrintMore("-", 84);
			cout << "The number of nodes in your search tree: ";
			cout << search_tree.GetCountNodes(_binary_tree);
			PrintMore("-", 84);
		}
		if (command == CLEAR)
		{
			system("cls");
			UI::Start();
		}

		cout << endl << "--> ";
		cin >> command;
	}
}

void UI::Exit() 
{
	UI::~UI();
	exit(0);
}