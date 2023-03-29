#include "bintree.h"

//------------------------------------------------------------------------------

int SetSizeOfTree()
{
	cout << endl << endl;

	int input_size;

	cout << "Enter the size of your binary tree search: ";
	cin >> input_size;

	if (input_size <= 0) 
	{
		Error(UNABLE_TO_CREATE_TREE);
	}

	cout << endl;

	return input_size;
}

//------------------------------------------------------------------------------

void Error(int fault_code)
{
	PrintMore("=", 42);
	cout << endl << "! ERROR" << endl;

	if (fault_code == 0)
	{
		cout << "# Unable to create a tree" << endl;
		cout << "& Please, restart program" << endl;
		PrintMore("=", 42);

		exit(0);
	}
	if (fault_code == 1)
	{
		cout << "# Unable to add a value in tree" << endl;
		cout << "* This value is already present" << endl;
		PrintMore("=", 42);
	}

	cout << endl;
	
} 

void PrintMore(const string& symbol, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

