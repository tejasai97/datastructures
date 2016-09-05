
#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *left,*right;
	node();
};
node::node()
{
	data=NULL;
	left=right=NULL;
}
class bstree:public node
{
	public:
		node *root;
		bstree();
		void insert(int value);
		void inorder(node *rt);
		void insert_values();
		void display();
		void postorder( node *rt );
		void  preorder( node *rt );
		
};
bstree::bstree()
{
	root=NULL;
}
void bstree::insert(int value)
{
	//root=new node;
	node *temp1=new node;
	if(root==NULL)
	{
		temp1->data=value;
		temp1->left=NULL;
		temp1->right=NULL;
		root=temp1;
	}
	else
	{
		node *temp=root;
		if(temp->data<value)
		{
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			node *new_right=new node;
			new_right->data=value;
			new_right->left=NULL;
			new_right->right=NULL;
			temp->right=new_right;
		}
		else
		{
		
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		node *new_left=new node;
		new_left->data=value;
		new_left->left=NULL;
		new_left->right=NULL;
		temp->left=new_left;
	}}
}
void bstree::insert_values()
{
	int value;
	char option;
	cout<<"enter the values "<<endl;
	cout<<"to exit press 0"<<endl;
	while(1)
	{
		cin>>value;
		if(value==0)
		{
			cout<<"do u want to endl"<<endl;
			cout<<"y-yes n-n0"<<endl;
			cin>>option;
			if(option=='y')
			 break;
			else
			  insert(value);
		}
		else
		{
			insert(value);
		}
	}
}
void bstree :: display()
{
/*	if( root == NULL )
	{
		cout<<"\n\nBinary tree is empty !!";
		return;
	}
*/
	cout<<"\n\n\nInorder display is..\n\n";
	inorder( root );

	cout<<"\n\n\npreorder display is..\n\n";
	preorder( root );
	cout<<"\n\n\npostorder display is..\n\n";
postorder( root );

}

void bstree::inorder(node *rt)
{
	if( rt!=NULL )
	{
		inorder( rt->left );
		cout<<rt->data<<"  ";
		inorder( rt->right );
	}
}

void bstree :: postorder( node *rt )
{
	if( rt!=NULL )
	{
		postorder( rt->left );
		postorder( rt->right );
		cout<<rt->data<<"  ";

	}
}
void bstree :: preorder( node *rt )
{
	if( rt!=NULL )
	{
		cout<<rt->data<<"  ";
		preorder( rt->left );
		preorder( rt->right );
	}
}

int main(void)
{
	bstree T1;
	T1.insert_values();
	T1.display();
	return 0;
}

