#include "Graph.h"
#include <iostream>   // basic file operations
#include <fstream>    // basic file operations
#include <sstream>    // stringstream
#include <vector>

void Graph::readIn() {
  // open Data.txt for readIn input, name obj fileInput
  std::ifstream fileInput;
  // hardcode "Data.txt" file name
  fileInput.open("Data.txt");

  if (fileInput.is_open()) {
    // looping
    // read outside the loop
    std::string city;

    std::string city1;
    std::string city2;
    std::string keyword;
    double price;
    
    // input line
    std::string line;
    std::getline(fileInput, line);

    // while x is good: check to see if you hit the end of file
    while (fileInput.eof() != true) {
      // do stuff with line
      // input with line
      std::stringstream ss(line);
      ss >> keyword;  // either city or flight
      if (keyword == "city") {
        // variable city now has name of the city in it
        ss >> city;

        // Make node and push_back onto list of nodes
        Node* newCity = new Node(city);
        graphNodes.push_back(newCity);
      }
      else if (keyword == "flight") {
        ss >> price;
        ss >> city1;
        ss >> city2;
        
        // Find node and push_back onto list of nodes
        Node* newCity1 = find(city1);
        Node* newCity2 = find(city2);

        if (newCity1 != nullptr && newCity2 != nullptr) {
          Edge* newFlight = new Edge(newCity1, newCity2, price);
          graphEdges.push_back(newFlight);

          // add flights for each city
          newCity1-> addEdge(newFlight);
          newCity2-> addEdge(newFlight);
        }
        else {
          std::cout << "Cannot find city " << city1 << " and " << city2 << std::endl;
        }
      }

      // read again at the bottom of the loop
      std::getline(fileInput, line);
    }
  }
}

// Find function (here is std::string name, go through whole list of nodes, see if you can find node that goes with this name) -> not conceptually hard but does take code
Node* Graph::find(const std::string& selectedCity) {
  for (Node* searchedCity : graphNodes) {
    if (searchedCity-> getName() == selectedCity) {
      return searchedCity;
    }
  }
  return nullptr;
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

Edge* Graph::lowestPrice() {
  double lowestPrice = 5000.00;
  Edge* flightPtr = nullptr;

  for (Edge* newEdge : graphEdges) {
    double flightCost = newEdge-> getCost();
    if (flightCost < lowestPrice) {
      // assigning lowest price to flightCost
      lowestPrice = flightCost;
      flightPtr = newEdge;
    }
  }

  return flightPtr;
}