#include "Edge.h"
#include <iostream>

void Edge::report() {
  std::cout << connection1-> getName() << " to/from " << connection2-> getName() << " is the cheapest flight and costs $" << cost << "." << std::endl;


} 
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