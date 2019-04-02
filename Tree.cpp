#include <iostream>
using namespace std;

#include "Tree.hpp"
#include "Node.cpp"
using namespace ariel;


///////////////////////////////////////////////////constructors /////////////////////////////////////////////////////////////////////////
Tree :: Tree()
{
	head=NULL;
	count=0;
}

Tree :: ~Tree()
{
	DestroyRecursive(head);
	head=NULL;
}

///////////////////////////////////////////////////////methods ///////////////////////////////////////////////////////////////////////////
void Tree :: insert(int x)
{
	count++;
	if(getRoot()== NULL)//empty tree
	{
		head=new Node(x);
	}
	else
	{
		Node *  newNode =insert (x,getRoot(), getRoot());//the parent

		if(newNode->getNum()>x)//x lef son
		{
			newNode->setLeft(new Node(x));
			newNode->getLeft()->setParent(newNode);
		}
		else//x right son
		{
			newNode->setRight(new Node(x));
			newNode->getRight()->setParent(newNode);
		}
	}
}

void Tree:: remove(int x)
{

	Node * n= search(x,getRoot());

	if(n==NULL)//x not in the tree
	{
		 throw std::out_of_range("The number not in the tree");
	}
	else
	{
		//////////x in a leaf
		if(n->getLeft()==NULL&&n->getRight()==NULL)
		{
			if(root()==n->getNum())//x root
			{
				head=NULL;
			}
			else if(n->getParent()->getNum()>n->getNum())//x left son
			{
				n->getParent()->setLeft(NULL);
			}
			else//x right son
			{
				n->getParent()->setRight(NULL);
			}
		}

		////////////x dont have left son
		else if(n->getLeft()==NULL)
		{
			Node * temp= n->getRight();
			 if(root()==n->getNum())//x root
			{
				temp->setParent(NULL);
				head=temp;
			}
			else
			{
				temp->setParent(n->getParent());
				if(n->getParent()->getNum()>n->getNum())//x left son
                        	{
                                	n->getParent()->setLeft(temp);
                        	}
                        	else//x right son
                        	{
                                n->getParent()->setRight(temp);
                        	}
			}
		}
		
		///// x dont have right son
		else if(n->getRight()==NULL)
		{
			Node * temp= n->getLeft();
			if(root()==n->getNum())//x root
                        {
                                temp->setParent(NULL);
                                head=temp;
                        }
                        else
                        {
				temp->setParent(n->getParent());
                         	if(n->getParent()->getNum()>n->getNum())//x left son
                        	{
                                	n->getParent()->setLeft(temp);
                        	}
                        	else//x right son
                        	{
                                	n->getParent()->setRight(temp);
                        	}
			}
		}
		
		/////x have 2 son
		else
		{
			Node * temp= findSon(n->getLeft());
			if(temp!=n->getLeft())//the previous number is not a son
			{////
				temp->getParent()->setRight(temp->getLeft());
				if(temp->getLeft()!=NULL)//if have son set has parent
				{
					temp->getLeft()->setParent(temp->getParent());
				}

				temp->setLeft(n->getLeft());
				temp->setRight(n->getRight());
				temp->getLeft()->setParent(temp);
				temp->getRight()->setParent(temp);
			}
			else
			{
				temp->setRight(n->getRight());
				temp->getRight()->setParent(temp);
			}

			if(root()==n->getNum())//x is root
                        {
                                head=temp;
                        }
			else if(n->getParent()->getNum()>n->getNum())//x left son
                       	{
                             	n->getParent()->setLeft(temp);
                       	}
                        else//x right son
                        {
                                n->getParent()->setRight(temp);
                        }
			temp->setParent(n->getParent());
		}

		count--;//reduce the size
		delete n;
	}
}

int Tree::size()
{
	return count;
}

bool Tree:: contains(int x)
{
	Node * n= search(x,getRoot());
	if(n==NULL)//x not in the tree
	{
		return false;
	}
	return true;
}

int Tree:: root()
{
	if(getRoot()==NULL)//if the tree is empty trows exeption
	{
		throw std::out_of_range("The tree is empty");	
	}
	return getRoot()->getNum();
}

int Tree :: parent(int x)
{
	Node * n=search(x,getRoot());
	if(n==NULL || n->getParent()==NULL)// x not found or root
	{
		throw std::out_of_range("No parent");

	}
	return n->getParent()->getNum();
}

int Tree :: left(int x)
{
	Node * n= search(x,getRoot());
	if (n==NULL)//not found
	{
		throw std::out_of_range("Not exsit");
	}
	if(n->getLeft()==NULL)//no left son
	{
		 throw std::out_of_range("No left son");
	}
	return n->getLeft()->getNum();
}

int Tree :: right(int x)
{
        Node * n= search(x,getRoot());
        if (n==NULL)// not found
	{
		throw std::out_of_range("Not exsit");
	}
        if(n->getRight()==NULL)// no right son
	{
		throw std::out_of_range("No right son");
	}
        return n->getRight()->getNum();
}

void Tree :: print()
{
	printInorder(getRoot());
	cout<<"\n size:"<< count<<endl;
}

////////////////////////////////////////////////////Getters and Setters /////////////////////////////////////////////////////////////
Node* Tree::getRoot()
{
	return this -> head;
}


//////////////////////////////////////////////////////////private /////////////////////////////////////////////////////////////////////
Node * Tree:: findSon(Node * n)
{
	if(n->getRight()==NULL)//n the previous number
	{
		return n;
	}
	else
	{
		return findSon(n->getRight());
	}
}

Node * Tree :: insert(int x, Node * n, Node * p)
{

	if(n==NULL)//end of tree
	{
		return p;

	}

	else if(p->getNum()==x)// x already in the tree
	{
		count--;//we increase the count befor
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


void Tree :: printInorder( Node* node) //we took the code from geekforgeek site
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



Node * Tree::search(int x, Node* n)
{
	if(n==NULL)//not found
	{
		return n;
	}
	if (n->getNum()==x)//found x
	{
		return n;
	}
	if(n->getNum()>x)//x shold be in the left side
	{
		return search(x,n->getLeft());
	}
 	else//x should be at the right side
	{
		return search(x,n->getRight());
	}
}

//we took the code from :https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
void Tree::DestroyRecursive(Node * node)
{
    if (node)
    {
        DestroyRecursive(node->getLeft());
        DestroyRecursive(node->getRight());
        delete node;
    }
}

