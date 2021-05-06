#include "Node.h"
#include <iostream>

void Node::report() {
  Node* nodeptr;

  std::cout << "City: " << name << " connects to: " << std::endl;

  // list all the edges here
  for (Edge* newEdge : edges) {
    // if connection 1 is the one I am in, use connection 2
    nodeptr = newEdge-> getConnection1();
    // if nodePtr points to self, get the other one
    if (nodeptr == this) {
      nodeptr = newEdge-> getConnection2();
    }
    // print out the node pointers
    std::cout << nodeptr-> name << std::endl;
  }

}

void Node::reportThreeConnections() {
  Node* nodeptr;
  
  // connections (edges) of 3+
  if (edges.size() > 2) {
    std::cout << "City: " << name << " connects to: " << std::endl;
    // list all the edges here
    for (Edge* newEdge : edges) {
      // if connection 1 is the one I am in, use connection 2
      nodeptr = newEdge-> getConnection1();
      // if nodePtr points to self, get the other one
      if (nodeptr == this) {
        nodeptr = newEdge-> getConnection2();
      }
      // print out the node pointers
      std::cout << nodeptr-> name << std::endl;
    }
  }
}

// if not marked, mark yourself and where you are at and call neighbors to do the same
void Node::connectionMap() {
  // start with blank graph and mark nodes you are in/have been to
  // the if-statement will call the function over and over again and spread all nodes
  
  // if not marked, do this so you are not stuck in a loop
  // Function goes thru all edges and they are marked and go through other city and mark those until graph is as marked as possible
  if (!isMarked) {
    isMarked = true;
    // mark all neighbors
    for (Edge* newEdge : edges) {
      // this is the node I am in
      Node* otherEnd = newEdge-> otherEnd(this);

      otherEnd-> connectionMap();
    }

    // mark other cities you know and tell them to mark where you are at
    // mark all neighbors and mark those
    // etc

  }
  // make function stop (typical with recursive function)
}