#include "Edge.h"
#include <iostream>

void Edge::report() {
  std::cout << "Flight: "<< connection1-> getName() << " and " << connection2-> getName() << " costs: $" << cost << std::endl;


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