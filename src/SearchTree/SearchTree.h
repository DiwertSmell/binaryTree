#pragma once

#include "../src/bintree/bintree.h"
#include "../ui/UI.h"

//------------------------------------------------------------------------------

class SearchTree
{
public:

	bintree* CreateNode(const int data);

//------------------------------------------------------------------------------

	void MakeBinaryTree(bintree** proot, const int size_of_tree);
	void Insert(bintree** proot, const int insert_element);
	void RemoveBinaryTree(bintree** proot);

	void LKP(bintree* proot);
	void KLP(bintree* proot);
	void LPK(bintree* proot);

//------------------------------------------------------------------------------

	bool SearchNodeByKey(bintree* proot, const int input_key);

//------------------------------------------------------------------------------

	static int GetCountNodes(bintree* proot);
};
