
#include <iostream>
using namespace std;


#include "Node.hpp"
using namespace ariel;

///////////////////////////////constructors//////////////////////////////////
Node::Node(int x)
{
	num=x;
	right=NULL;
	left=NULL;
	parent=NULL;

}

/////////////////////////////////////Getters and Setters/////////////////////////////////////
int Node::getNum(){return num;}
Node* Node::getLeft(){return left;}
Node* Node::getRight(){return right;}
Node* Node ::getParent(){return parent;}
void Node :: setRight(Node * n){right=n;}
void Node :: setLeft(Node * n){left=n;}
void Node :: setParent(Node * n){parent=n;}

////////////////////////////methods/////////////////////////////////////
void  Node::print()
{
	cout<< num;
}

