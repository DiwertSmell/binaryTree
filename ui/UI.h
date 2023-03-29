#pragma once

#include "C:/Users/darti/Desktop/Programming/binaryTree/src/SearchTree/SearchTree.h"

#define CLEAR "clear"
#define EXIT "exit"

#define UI_LKP "lkp"
#define UI_KLP "klp"
#define UI_LPK "lpk"

#define MAKE_BINARY_TREE "make"
#define INSERT "insert"
#define SEARCH "search"
#define COUNT "count"

//------------------------------------------------------------------------------

class UI 
{
private:

	bintree* _binary_tree;

public:
	
	UI();
	~UI();

//------------------------------------------------------------------------------

	void Start();

	void Launcher();

	void Exit();
};
