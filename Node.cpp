#include <iostream>
using namespace std;


#include "Node.hpp"
using namespace ariel;

Node::Node(int x)
{
	num=x;
	right=NULL;
	left=NULL;
	parent=NULL;

}

int Node::getNum(){return num;}
Node* Node::getLeft(){return left;}
Node* Node::getRight(){return right;}
Node* Node ::getParent(){return parent;}
void Node :: setParent(Node * n)
{
	parent=n;
}
void  Node::print()
{
	cout<< num;
}

