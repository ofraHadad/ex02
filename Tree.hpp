//#ifndef __TREE_HPP
//#define __TREE_HPP
#pragma once
namespace ariel{
class Node;

class Tree
{
	public:
	
	Tree();
	void insert(int x);
	void remove(int x);
	int size();
	bool contains(int x);
	int parent (int x);
	int left(int x);
	int right(int x);
	void print();
	Node* getRoot();
	int root();

	private:
	Node* head;
	int count;
	Node * insert(int x,Node* n,Node* p);
	void printInorder(Node * n);
	Node * findSon(Node * n);
	Node* search(int x,Node *n);
};
}

//#endif
