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
    isMarked = false;
  }

  // getters in regard to cities being flown to
  Node* getConnection1() { return connection1; }

  Node* getConnection2() { return connection2; }

  // getters for the flight characteristics like cost and isMarked
  double getCost() { return cost; }

  bool getIsMarked() { return isMarked; }

  void report();

  // otherEnd takes in the node on one end as an argument, and otherEnd will give you the node on the other end
  // otherEnd should be considered a getter
  Node* otherEnd(Node* end1);

private:
  // node that connects - node pointer because edge is pointing to real node
  // connections have 2 ends
  Node* connection1;
  Node* connection2;

  // how much a flight costs
  double cost;

  // array of flight edges, stored as Edge*
  std::vector<Edge*> edges;

  // marked edges
  bool isMarked;

};