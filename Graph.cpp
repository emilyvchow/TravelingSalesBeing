#include "Graph.h"
#include <iostream>   // basic file operations
#include <fstream>    // basic file operations

void Graph::readIn(const std::string& inputLocation, std::vector<std::string>& data) {
  // open Data.txt for input, name obj fileInput
  std::ifstream fileInput;
  fileInput.open("Data.txt");

  if (fileInput.is_open()) {
    // looping
    while (fileInput.eof() != true) {
      // write to file with line
      std::string line;
      std::getline(fileInput, line);
      data.push_back(line);
    }
  }
}

// Might have to write find function (here is name, go through whole list of nodes, see if you can find node that goes with this name) -> not conceptually hard but does take code
bool Graph::find(std::string selectedCity) {

}


void Graph::report() {
  // list of nodes, list of edges
  // go through all nodes and do their reports

  // go through all nodes and do their reports
  for (Node* singleNode : graphNodes) {
    singleNode-> report();
  }

  // go through all edges and do their reports
  for (Edge* singleEdge : graphEdges) {
    singleEdge-> report();
  }

}