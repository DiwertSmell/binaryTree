#pragma once

#include<iostream>

#define UNABLE_TO_CREATE_TREE 0
#define UNABLE_TO_ADD_A_VALUE 1

using namespace std;

//------------------------------------------------------------------------------

struct bintree 
{
	int data;
//*	int count_num;

	bintree* left;
	bintree* right;
};

int SetSizeOfTree();

//------------------------------------------------------------------------------

void Error(int fault_code);

void PrintMore(const string& symbol, int size);