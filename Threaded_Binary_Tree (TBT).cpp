//============================================================================
// Name        : Threaded_Binary_Tree.cpp
// Author      : Ashley.J.George
// Version     : Mera Wala Version
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int data;
	node *l,*r;
	int L_th,R_th;
};



class TBT
{
public:
		node *dummy,*nn,*root;

		TBT()
		{
		    dummy = new node;
		    dummy->data = -100;
		    dummy->l = dummy->r = NULL;
		    dummy->L_th = dummy->R_th = 0;
		    root = NULL;
		    nn = NULL;
		}
		void Create_TBT();
		void Inorder_TBT();
};



void TBT :: Create_TBT()
{
	nn = new node;
	cout<<"Enter Data\n";
	cin>>nn->data;
	nn->l = nn->r = NULL;
	nn->L_th = nn->R_th = 0;

	if(root==NULL)
	{
		root = nn;
		dummy->l = root;
		root->l = root->r = dummy;
	}

	else
	{
		node *temp,*parent;
		temp = root;
		while(temp!=NULL)
		{
			parent = temp;
			if(nn->data < temp->data)
			{
				if(temp->L_th == 1)
					temp = temp->l;
				else
					temp = NULL;
			}
			else
			{
				if(temp->R_th == 1)
					temp = temp->r;
				else
					temp = NULL;
			}
		}

		if(nn->data < parent->data)
		{
			nn->l = parent->l;
			nn->r = parent;
			parent->L_th = 1;
			parent->l = nn;
		}
		else
		{
			nn->r = parent->r;
			nn->l = parent;
			parent->R_th = 1;
			parent->r = nn;
		}
	}
}


void TBT :: Inorder_TBT()
{
	node *temp;
	temp = root;

	while(1)
	{
		while(temp->L_th == 1)
		{
			temp = temp->l;
		}
		cout<<temp->data<<"\t";

		while(temp->R_th == 0)
		{
			if(temp->r == dummy)
				return;
			else
			{
				temp = temp->r;
				cout<<temp->data<<"\t";
			}

		}

		temp = temp->r;
	}
}



int main()
{
	TBT t;
	int c;
	cout<<"\n================ ~ Threaded Binary Tree ~ ================\n\n";
	do
	{
		cout<<"\n1. Create\n2. Display\n3. Exit\nEnter Your Choice: ";
		cin>>c;
		switch(c)
		{
		    case 1: t.Create_TBT();
		    break;

		    case 2: t.Inorder_TBT();cout<<"\n";
		    break;

		    case 3: cout<<"~ You Have Exited Sucessfully!!! ~"<<endl;
		    break;

		    default: cout<<"~ Invalid Input!!! ~"<<endl;
		}

	}while(c!=3);

	return 0;
}
