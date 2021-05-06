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

  std::string getName() { return name; }

  std::vector<Edge*> getEdges() { return edges; }

  bool getIsMarked() { return isMarked; }

  void setIsMarked(bool markBoolean) { isMarked = markBoolean; }

  // nodes have to be able to add edges
  // add edge to list of edges
  void addEdge(Edge* edgePointer) { edges.push_back(edgePointer);}

  void report();

  void reportThreeConnections();

  void connectionMap();

private:
  // node has a list of edges
  std::vector<Edge*> edges;

  bool isMarked;

  // name of city
  std::string name;
};
