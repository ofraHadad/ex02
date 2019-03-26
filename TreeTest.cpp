/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  
  mytree.insert(9);
  mytree.insert(19);
  mytree.insert(8);
  mytree.insert(6);
  mytree.insert(30);
  mytree.insert(7);
  mytree.insert(14);
  mytree.insert(15);

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_THROWS (emptytree.parent(9))//
  .CHECK_THROWS (emptytree.root())//		
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .CHECK_EQUAL (mytree.root(),9)//
  .CHECK_OK (mytree.root())//
  .CHECK_THROWS (mytree.parent(9))//
  .CHECK_OK (mytree.parent(8))//
  .CHECK_EQUAL (mytree.parent(14),19)//
  .CHECK_THROWS (mytree.right(20))// not found
  .CHECK_THROWS (mytree.right(15))//no right
  .CHECK_OK(mytree.right(14))//have a right son
  .CHECK_EQUAL (mytree.right(6),7)//
   .CHECK_THROWS (mytree.left(20))// not found
  .CHECK_THROWS (mytree.left(15))//no left
  .CHECK_OK(mytree.left(8))//have a left son
  .CHECK_EQUAL (mytree.left(8),6)//
  .CHECK_EQUAL (mytree.contains(5),false)//no 5 in the tree
  .CHECK_EQUAL (mytree.contains(9),true)//9 in the tree
  .CHECK_EQUAL (mytree.size(),8)//the size of the tree is 8
  .CHECK_THROWS (mytree.insert(9))//there is 9 in the tree
  .CHECK_OK (mytree.insert(35))//there is no 35 in the tree
  .CHECK_EQUAL (mytree.size(),9)//the tree grow with 1
  .CHECK_EQUAL (mytree.contains(35),true)//35 was add to the tree
  .CHECK_EQUAL (mytree.parent(35),30)// check if 35 is in the right place
  .CHECK_EQUAL (mytree.right(30),35) //check if 35 is in the right place
  .CHECK_THROWS (mytree.remove(22))//there is no 22 in the tree
  .CHECK_OK(mytree.remove(9))//there is 9 in the tree
  .CHECK_EQUAL (mytree.contains(9),false)//check if 9 was remove
  .CHECK_EQUAL (mytree.size(),8)// check if size reduse by 1
  .CHECK_EQUAL (mytree.root(),8)//check if the tree change corectly after the remove
  .CHECK_THROWS (mytree.parent(8))//check if the tree change corectly after the remove
  .CHECK_EQUAL (mytree.right(8),19)//check if the tree change corectly after the remove
  .CHECK_EQUAL (mytree.left(8),6)//check if the tree change corectly after the remove
  .CHECK_EQUAL (mytree.parent(19),8)//check if the tree change corectly after the remove
  .CHECK_EQUAL (mytree.parent(6),8)//check if the tree change corectly after the remove

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;

}
