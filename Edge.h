#pragma once
#include "Node.h"
class Node;

// edge is connection between 2 nodes, basically a flight
class Edge 
{
public:
  Edge(Node* c1, Node* c2, double price) {
    connection1 = c1;
    connection2 = c2;
    cost = price;
  }

  void report();

private:
  // node that connects - node pointer because edge is pointing to real node
  // connections have 2 ends
  Node* connection1;
  Node* connection2;

  // how much a flight costs
  double cost;

  // check both directions

  // how long a flight takes

};