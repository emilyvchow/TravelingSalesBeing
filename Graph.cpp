#include "Graph.h"
#include <iostream>   // basic file operations
#include <fstream>    // basic file operations
#include <sstream>    // stringstream
#include <vector>

// readIn() opens Data.txt or whicheveer file for readIn input and names object fileInput. readIn() will read in the input and start making city nodes for the graph
void Graph::readIn() {
  std::ifstream fileInput;
  // allow user to input their own file name
  std::cout<< "Enter Data Filename: ";
  std::string filename;
  std::cin >> filename;

  fileInput.open(filename);

  if (fileInput.is_open()) {
    // looping
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

        // Debugging purpose
        // std::cout<< "About to Add " <<city << std::endl;
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

// find() tries to find a node that goes through a whole list of nodes to find a node that matches the  std::string name
Node* Graph::find(const std::string& selectedCity) {
  // searching through entire graphNodes() list for the particular city passed in
  for (Node* searchedCity : graphNodes) {
    // if that city is found
    if (searchedCity-> getName() == selectedCity) {
      return searchedCity;
    }
  }
  // else, return null pointer for no city found
  return nullptr;
}

// report() goes through a list of nodes and a list of edges to do their reports
void Graph::report() {
  // go through all nodes and do their reports
  for (Node* singleNode : graphNodes) {
    singleNode-> report();
  }

  // go through all edges and do their reports
  for (Edge* singleEdge : graphEdges) {
    singleEdge-> report();
  }

}

// lowestPrice() will compare Edge pointers in the graph to find the lowest cost, then storing the flight with the lowest cost as a pointer
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