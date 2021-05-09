#pragma once
#include <vector>
#include <string>
#include "Edge.h"

class Edge;

// nodes are like cities
class Node 
{
public:
  Node(std::string cityName) {
    name = cityName;
    isMarked = false;
  }

  void say(int, std::vector<Edge*>*);

  // getters for Node characteristics (name, edges, isMarked, etc)
  std::string getName() { return name; }

  std::vector<Edge*> getEdges() { return edges; }

  bool getIsMarked() { return isMarked; }

  double getPriceToTarget() { return priceToTarget; }

  Edge* getEdgeToTarget() { return edgeToTarget; }

  // setters to change characteristics for the Node (isMarked, price, edgeTarget)
  void setIsMarked(bool markBoolean) { isMarked = markBoolean; }

  void setPriceToTarget(double price) {priceToTarget = price; }

  void setEdgeToTarget(Edge* edgeTarget) {edgeToTarget = edgeTarget; }

  // nodes have to be able to add edges: add edge to list of edges
  void addEdge(Edge* edgePointer) { edges.push_back(edgePointer);}

  // various node functions
  void report();

  void printPath();

  void connectionMap();

  void updateNode();

  double costOfTrip(std::vector<Edge*>* trips);

  std::vector<Edge*>* travelingSalesBeing(Node* destination, int counter);

private:
  // node has a list of edges
  std::vector<Edge*> edges;

  // characteristic of the node to show exactly where user has been
  bool isMarked;

  // name of city
  std::string name;

  // price to get to destination
  double priceToTarget;

  // flight to get to target city
  Edge* edgeToTarget;
};
