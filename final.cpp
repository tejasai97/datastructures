#include<iostream>
using namespace std;
class node
{
public:
	float coeff;
	int exp;
	char var;
	node *next;
};
class poly:public node{
public:
	node *p;
	poly();
	void insert();
	void add(poly &a, poly &b);
	void display();
	void simplify();
	~poly();
};
poly::poly()
{
p = NULL;
}

void poly::insert()
{
	node *temp= p;
	if (temp == NULL)
	{
		temp = new node;
		p = temp;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new node;
		temp = temp->next;
	}
	cout<<"coefficient";
	cin >> temp->coeff;
	cout<<"power";
	cin >> temp->exp;
	if(temp->exp==0)
        temp->var='x';
	else{
        cout<<"variable";
        cin>>temp->var;
        }
	temp->next = NULL;
}
void poly::display()
{
	node *temp = p;
	int count = 0;
	while (temp != NULL)
	{
		if (count != 0)
		{
			if (temp->coeff > 0)
				cout << "+";
			else
				cout << " ";
		}
		if (temp->exp != 0)
			cout << temp->coeff << temp->var<<"^" << temp->exp;
		else
			cout << temp->coeff;
		temp = temp->next;
		count = 1;
	}
}
void poly::add(poly &first, poly &second)
{
	node *temp = NULL;
	node *a1, *a2;
	a1 = first.p;
	a2 = second.p;
	p=a1;
	temp=p;
	while(temp->next !=NULL)
        temp=temp->next;
    temp->next=a2;
}
poly :: ~poly()
{
	node *q;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
}
void poly::simplify()
{
    node *temp1,*temp2,*temp3;
temp1=p;
while(temp1->next != NULL)
{
temp2=temp1;
temp3=temp2->next;
while(temp3 != NULL)
{
if(temp3->exp==temp1->exp &&(temp3->var==temp1->var))
{
temp1->coeff=temp1->coeff+temp3->coeff;
temp2->next=temp3->next;
node *k;
k=temp3;
temp3=temp3->next;
delete k;
}
else
{
temp2=temp2->next;
temp3=temp2->next;
}
}
temp1=temp1->next;
}
}
int main()
{
	poly a, b,result;
	int count1, count2;
	cout<< "enter the degree of first polynomial" << endl;
	cin >> count1;
	for (int i = 0; i <= count1; i++)
		a.insert();
	cout << "enter the degree of second polynomial" << endl;
	cin >> count2;
	for (int i = 0; i <= count2; i++)
		b.insert();
	cout << "first polynomial" << endl;
	a.display();
	cout <<endl<< "second polynomial" << endl;
	b.display();
	cout << endl<<"result:" << endl;
	result.add(a,b);
	result.simplify();
	result.display();
    return 0;
}
