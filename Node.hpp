//#ifndef __NODE_HPP

//#define __NODE_HPP
#pragma once
namespace ariel{
class Node
{

public:	
	Node *right, *left, *parent;
	int num;	
	Node(int x);
	Node();
	int getNum();
	Node* getLeft();
	Node* getRight();
	Node* getParent();
	void print();
	void setParent(Node * n);
};}
//#endif
