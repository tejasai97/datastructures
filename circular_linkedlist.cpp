// list_linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class node
{
public:
	int element;
	node *next;
	node();
	~node() {
		delete next;
	};
};
node::node() {
	element = 0;
	next = NULL;
}
class list:public node
{
public:
	node *p;
	void input();
	void output();
	list() {
		p = new node;
	}
	~list() {
		delete p;
	}
	void reverse();
};
void list::input() {
	int count;
	cout << "enter the no. of elements" << endl;
	cin >> count;
	cout << endl;
	node *temp;
	temp = p;
	for (int i = 0; i < count; i++) {
		if(i<count-1)
			temp->next = new node;
		cin >> temp->element;
		temp = temp->next;
	}
	temp = p;
}
void list::output()
{
	node *temp1;
	temp1 = p;
	while (temp1 != NULL){
		cout << temp1->element<<endl;
		temp1 =temp1->next;
	}
}
void list::reverse() {
	node *pre=NULL, *cur=NULL, *aft=NULL;
	cur = p;
	aft = cur->next;
	while (aft != NULL)
	{
		if (cur == p) {
			pre = p;
			cur = pre->next;
			aft = cur->next;
			pre->next = NULL;
		}
		else {
			cur->next = pre;
			pre = cur;
			cur = aft;
			aft = aft->next;
		}
		cur->next = pre;
	}
	p = cur;
}

int main()
{
	list test;
	test.input();
	cout<<endl;
	test.output();
	test.reverse();
	cout << endl;
	test.output();
    return 0;
}
