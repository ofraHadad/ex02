#pragma once

namespace ariel{
/**
*this class represents a Node, a leafe in the tree
*/
class Node
{

public:	
//	Node *right, *left, *parent;
//	int num;
	Node(int x);//constructor
	Node();
	int getNum();//return the num
	Node* getLeft();//return the left pointer
	Node* getRight();//return the right pointer 
	Node* getParent();//retun the parent pointer
	void print();

	void setParent(Node * n);
	void setLeft(Node * n);
	void setRight(Node * n);

private:
	 Node *right, *left, *parent;
	int num;
};}
