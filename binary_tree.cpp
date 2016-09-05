// binary_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class node
{
public:
	int data;
	node *left, *right;
	node() {
		data = 0;
		left = right = NULL;
	}
};
class binary {
public:
	node *root;
	int count;
	void calculate(node *temp);
	void make_tree(int element, binary *left, binary *right);
	binary()
	{
		root = NULL;
		count = 0;
	}
};
void binary::make_tree(int element, binary *left, binary *right)
{
	root = new node;
	if (left != NULL && right != NULL) {
		root->data = element;
		root->left = left->root;
		root->right = right->root;
	}
	else
	{
		root->data = element;
		root->left = NULL;
		root->right = NULL;
	}
}
void binary::calculate(node *temp)
{
	if (temp != NULL)
	{
		if (temp->left == NULL && temp->right == NULL) //remove this if and count++ and add cout<<temp->data to grt print function
			count++;
		calculate(temp->left);
		calculate(temp->right);
	}
}
int main()
{
	binary *a1, *a2, *a3,*a4,*a5;
	a1 = new binary;
	a2 = new binary;
	a3 = new binary;
	a4 = new binary;
	a5 = new binary;
	a1->make_tree(1, NULL, NULL);
	a2->make_tree(2, NULL, NULL);
	a3->make_tree(3,a1,a2);
	a4->make_tree(3, a1, a2);
	a5->make_tree(5, a3, a4);
	a5->calculate(a5->root);
	cout << a5->count;
    return 0;
}

