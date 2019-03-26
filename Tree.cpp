#include <iostream>
using namespace std;

#include "Tree.hpp"
#include "Node.cpp"
using namespace ariel;

Tree :: Tree()
{
	head=NULL;
	count=0;
}

Node* Tree::getRoot()
{
	return this -> head;
}

void Tree:: remove(int x)
{
/*
	Node * n= search(x,getRoot());

	if(n==NULL)
	{
		 throw std::out_of_range("The number not in the tree");
	}
	else
	{

		if(n->getLeft()==NULL&&n->getRight()==NULL)
		{
			n->getParent()->left=NULL;
			n->getParent()->right=NULL;
		}

		else if(n->getLeft()==NULL)
		{
			Node * temp= n->getRight();
			temp->setParent(n->getParent());
			n->getParent()->right=temp;
		}

		else if(n->getRight()==NULL)
		{
			Node * temp= n->getLeft();
			temp->setParent(n->getParent());
                        n->getParent()->left=temp;
		}

		else
		{
			Node * temp= findSon(n->getLeft());

			temp->getParent()->right=NULL;
			temp->setParent(n->getParent());
			if(n->getParent()->getNum()>n->getNum())
			{
				
				n->getParent()->left=temp;
			}
			if(n->getParent()->getNum()< n->getNum())
                        {
                                n->getParent()->right=temp;
                        }
		}
		count--;
		
	}*/
}

Node * Tree:: findSon(Node * n)
{
	if(n->getRight()==NULL)
	{
		return n;
	}
	else
	{
		return findSon(n->getRight());
	}
}

void Tree :: insert(int x)
{
	count++;
	if(getRoot()== NULL)
	{
		head=new Node(x);
	}
	else
	{
		Node *  newNode =insert (x,getRoot(), getRoot());
		
		if(newNode->getNum()>x)
		{
			
			newNode->left=new Node(x);
			newNode->left->setParent(newNode);
		}
		else
		{
			
			newNode->right=new Node(x);
			newNode->right->setParent(newNode);
		}
	}
}

Node * Tree :: insert(int x, Node * n, Node * p)
{

	if(n==NULL)
	{
		 
		return p;
			
	}

	else if(p->getNum()==x)
	{
		count--;
		throw std::out_of_range("The number is already exsit");
	}
	else if(p->getNum()>x) 
	{

		return  insert(x,p->getLeft(),n);
	}
	 else
	{
		
		 return insert(x,p->getRight(),n);
		
	}
}

void Tree :: print()	
{
	printInorder(getRoot());
	cout<<"\n"<< count;
}

void Tree :: printInorder( Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->getLeft()); 
  
    /* then print the data of node */
    cout << node->getNum() << "."; 
  
    /* now recur on right child */
    printInorder(node-> getRight()); 
}

int Tree::size()
{
	return count;
}

int Tree:: root()
{
	if(getRoot()==NULL)
	{
		throw std::out_of_range("The tree is empty");	
	}
	return getRoot()->getNum();
}

int Tree :: parent(int x)
{
	Node * n=search(x,getRoot());
	if(n==NULL || n->getParent()==NULL)
	{
		throw std::out_of_range("No parent");

	}
	
	return n->getParent()->getNum();
	
}

bool Tree:: contains(int x)
{
	Node * n= search(x,getRoot());
	if(n==NULL)
	{
		return false;
	}
	return true;
}

int Tree :: left(int x)
{
	
	Node * n= search(x,getRoot());
	
	if (n==NULL)
	{
		throw std::out_of_range("Not exsit");
	}
	if(n->getLeft()==NULL)
	{
		 throw std::out_of_range("No left son");
	}
	return n->getLeft()->getNum();
}

int Tree :: right(int x)
{
        Node * n= search(x,getRoot());
        if (n==NULL)
	{
		throw std::out_of_range("Not exsit");
	}
        if(n->getRight()==NULL)
	{
		throw std::out_of_range("No right son");
	}
        return n->getRight()->getNum();
}

Node * Tree::search(int x, Node* n)
{
	if(n==NULL)
	{
		return n;
	}
	if (n->getNum()==x)
	{
		return n;
	}
	if(n->getNum()>x)
	{
		return search(x,n->getLeft());
	}
 	else
	{
		return search(x,n->getRight());
	}
}
