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
    Node* n1 = new Node("San Francisco");
    Node* n2 = new Node("Los Angeles");
    double price = 85.00;

    Edge* e1 = new Edge(n1, n2, price);

    graphNodes.push_back(n1);
    graphNodes.push_back(n2);
    graphEdges.push_back(e1);
  }

  void readIn(const std::string& inputLocation, std::vector<std::string>& data);

  bool find(std::string selectedCity);

  void report();

private:
  std::vector<Node*> graphNodes;
  std::vector<Edge*> graphEdges;

  std::string matchingCity;
};
