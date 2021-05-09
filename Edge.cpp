#include "Edge.h"
#include <iostream>

// report() prints a description of each flight nicely and cleanly
void Edge::report() {
  std::cout << connection1-> getName() << " to/from " << connection2-> getName() << " costs $" << cost << "." << std::endl;
} 

// otherEnd() will look at the Edge and get the other city (Node) you would like to head to
Node* Edge::otherEnd(Node* end1) {
  Node* nodeptr = end1;

  // if nodePtr points to self, get the other one
  if (end1 == getConnection1()) {
    nodeptr = getConnection2();
  }
  else {
    nodeptr = getConnection1();
  }
  return nodeptr;
  
}