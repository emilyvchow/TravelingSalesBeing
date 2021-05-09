#pragma once
#include <vector>
#include "Edge.h"
#include "Node.h"
class Edge;
class Node;

class Graph 
{
public:
  Graph() {
    // default constructor
  }

  // readIn the data for the graph
  void readIn();

  std::vector<Node*> getGraphNodes() { return graphNodes; }

  Node* find(const std::string& selectedCity);

  void report();

  Edge* lowestPrice();

private:
  std::vector<Node*> graphNodes;
  std::vector<Edge*> graphEdges;

  std::string matchingCity;
};
