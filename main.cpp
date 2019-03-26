

#include "Tree.cpp"
#include <iostream> 
using namespace std;
using namespace ariel;
int main()
{
int x;
Node n (5);
cout << n.getNum() <<"\n";
Tree t;
t.insert(4);
t.insert(2);
t.insert(5);
t.insert(1);
t.insert(9);
t.insert(100);
t.insert(99);
t.insert(88);
t.insert(33);
t.insert(0);
t.insert(3);
t.insert(6);
//cout<<t.root()<<"\n";
//cout<<t.left(4)<<"qqqq\n";
//cout<<t.right(5)<<"33333\n";
//cout<<t.parent(100)<<"4444\n";
//t.remove(9);
//t.remove(100);
//t.remove(5);
//t.remove(3);
//cout<<t.getRoot()->getLeft()->getLeft()->getRight()->getNum()<<"shira<3\n";
//cout<<t.getRoot()->getRight()->getNum()<<"gggfgdsfsss\n";

t.print();

return 0;
}

