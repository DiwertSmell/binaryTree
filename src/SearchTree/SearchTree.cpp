#include "SearchTree.h"

//------------------------------------------------------------------------------

bintree* SearchTree::CreateNode(const int data)
{
	bintree* tmp = new bintree;

	tmp->data = data;

	tmp->left = nullptr;
	tmp->right = nullptr;

	return tmp;
}

//------------------------------------------------------------------------------

bool IsUniqueValueInsert(bintree* proot, const int value)
{
	if (proot == nullptr)
	{
		return true;
	}
	if (value == proot->data)
	{
		return false;
	}

	if (value < proot->data)
	{
		return IsUniqueValueInsert(proot->left, value);
	}
	else
	{
		return IsUniqueValueInsert(proot->right, value);
	}
}

bool SearchTree::SearchNodeByKey(bintree* proot, const int input_key)
{
	if (proot == nullptr)
	{
		return false;
	}

	if (proot->data == input_key)
	{
		return true;
	}

	if (input_key < proot->data)
	{
		return (SearchNodeByKey(proot->left, input_key));
	}
	else 
	{
		return (SearchNodeByKey(proot->right, input_key));
	}
}

//------------------------------------------------------------------------------

void SearchTree::Insert(bintree** proot, int insert_element)
{
	if (*proot == nullptr)
	{
		*proot = CreateNode(insert_element);
	}
	else
	{
		while (IsUniqueValueInsert(*proot, insert_element) == false)
		{
			Error(UNABLE_TO_ADD_A_VALUE);

			cout << "| Enter the element of your tree: ";
			cin >> insert_element;
		}

		if (insert_element < (*proot)->data)
		{
			Insert(&((*proot)->left), insert_element);
		}
		else 
		{
			Insert(&((*proot)->right), insert_element);
		}
	}

}

void SearchTree::RemoveBinaryTree(bintree** proot)
{
	if (*proot != nullptr)
	{
		RemoveBinaryTree(&((*proot)->left));
		RemoveBinaryTree(&((*proot)->right));

		delete* proot;
		*proot = nullptr;
	}
}

void SearchTree::MakeBinaryTree(bintree** proot, const int size_of_tree)
{
	if (*proot != nullptr)
	{
		RemoveBinaryTree(proot);
	}

	int element;
	for (int i = 0; i < size_of_tree; i++)
	{
		cout << "| Enter the element of your tree: ";
		cin >> element;

		while (IsUniqueValueInsert(*proot, element) == false)
		{
			Error(UNABLE_TO_ADD_A_VALUE);

			cout << "| Enter the element of your tree: ";
			cin >> element;
		}

		Insert(proot, element);
	}
}


void SearchTree::LKP(bintree* proot)
{
	if (proot != nullptr)
	{
		LKP(proot->left);
		cout << "  " << proot->data;
		LKP(proot->right);
	}
}

void SearchTree::KLP(bintree* proot)
{
	if (proot != nullptr)
	{
		cout << "  " << proot->data;
		LKP(proot->left);
		LKP(proot->right);
	}
}

void SearchTree::LPK(bintree* proot)
{
	if (proot != nullptr)
	{
		LKP(proot->left);
		LKP(proot->right);
		cout << "  " << proot->data;
	}
}

//------------------------------------------------------------------------------

int SearchTree::GetCountNodes(bintree* proot)
{
	if (proot == nullptr)
	{
		return 0;
	}
	else
	{
		return GetCountNodes(proot->left) + GetCountNodes(proot->right) + 1;
	}
}