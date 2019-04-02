//#ifndef __TREE_HPP
//#define __TREE_HPP
#pragma once
namespace ariel{
class Node;
/**
*binary search tree, each left son smaller than the parent and each right son bigger
*/
class Tree
{
	public:
	
	Tree();//defalt constructors head point to NULL
	void insert(int x);//add to the tree the x number ,throws exeption if x already in the tree.
	void remove(int x);//delete x from the tree, throws exeption if x not in the tree.
	int size();//return the size of the tree
	bool contains(int x);//return true if x is in the tree, false- if not.
	int parent (int x);//return the parent of x, throws exeption if x not in the tree or x is the head of the tree
	int left(int x);//return the left son of x, throws exeption if x not in the tree or x dont have a left son
	int right(int x);//return the right son of x, throws exeption if x not in the tree or x dont have a right son.
	void print();// print the tree inorder
	Node* getRoot();//return head pointer
	int root();//return the tree root

	private:
	Node* head;//root
	int count;//size
	Node * insert(int x,Node* n,Node* p);//find where to insert x
	void printInorder(Node * n);//print
	Node * findSon(Node * n);//return a pointer to the previous node of n inorder
	Node* search(int x,Node *n);//return pointer to x in the tree, return NULL if x is not in the tree
};
}

//#endif
