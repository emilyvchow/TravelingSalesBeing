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
  }

  std::string getName() { return name; }

  // nodes have to be able to add edges
  // add edge to list of edges
  void addEdge(Edge* edgePointer) { edges.push_back(edgePointer);}

  void report();

private:
  // node has a list of edges
  std::vector<Edge*> edges;

  // name of city
  std::string name;
};
