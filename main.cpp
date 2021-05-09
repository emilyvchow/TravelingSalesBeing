#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

void report();

int main() {
  // create new Graph object to complete menu options
  Graph* newGraph = new Graph();

  // read in Data.txt file
  newGraph-> readIn();

  std::string userCity;

  std::cout << "Welcome to the Traveling Sales Being problem!" << std::endl;

  int choice = -1;

  // menu options
  while (choice != 0) {
    std::cout << std::endl;
    // ask user to input choice
    std::cout << "MENU:\n1 = List of Cities\n2 = City Connections\n3 = Cheapest Flight\n4 = City Graph\n5 = At Least 3 Flights\n6 = Fewest Number of Hops\n7 = Traveling Sales Being\n0 = Quit\nEnter your choice: ";

    std::cin >> choice;
    std::cout << std::endl;

    // list of cities
    if (choice == 1) {
      std::cout << "OPTION 1: LIST OF CITIES" << std::endl;
      // list cities
      std::cout<<"Number of Cities: " 
           <<newGraph->getGraphNodes().size() <<std::endl;

      // loop through each city and print
      for (Node* eachCity : newGraph-> getGraphNodes()) {
        std::cout << "City: " << eachCity-> getName() << std::endl;
      }
    }

    // city connections
    // prompt user for city name and see all places you can get to from that city
    else if (choice == 2) {
      std::cout << "OPTION 2: CITY CONNECTIONS" << std::endl;
      // prompt user for city name and see all places you can get to from that city
      std::cout << "Enter city name: ";
      std::cin >> userCity;
      std::cout << std::endl;

      // find userCity, then report all cities that the user can get to
      Node* cityNode = newGraph-> find(userCity);
      cityNode-> report();
    }
    
    // cheapest flight
    else if (choice == 3) {
      Edge* flight = newGraph-> lowestPrice();

      // keep track of lowest cost one as you go through
      std::cout << "The lowest price flight is: " << std::endl;
      flight-> report();
    }

    // Connectivity (see how everything is connected): list all cities can get to from chicago, start marking process
    else if (choice == 4) {
      // restting the graph to no cities marked
      for (Node* newNode : newGraph-> getGraphNodes()) {
        newNode-> setIsMarked(false);
      }

      // get user input for whichever city they want to go to
      std::cout << "Enter city name: ";
      std::cin >> userCity;

      std::cout << std::endl;

      // find city, then call recursive function
      Node* cityNode = newGraph-> find(userCity);
      cityNode-> connectionMap();

      // loop through graph nodes
      for (Node* newNode : newGraph-> getGraphNodes()) {
        // print out marked nodes' names
        if (newNode-> getIsMarked()) {
          std::cout << newNode-> getName() << std::endl;
        }
      }
    }

    // find city with at least 3 flights
    else if (choice == 5) {
      // loop through graph nodes
      for (Node* newNode : newGraph-> getGraphNodes()) {
        // getting nodes with at least three edges
        if (newNode-> getEdges().size() >= 3) {
          // report() nodes with at least three edges
          newNode-> report();
        }
        std::cout << std::endl;
      }

    }

    // shortest path/fewest number of hops
    else if (choice == 6) {
      // initalize values for each node in the graph
      for (Node* newNode : newGraph-> getGraphNodes()) {
        newNode-> setIsMarked(false);
        newNode-> setPriceToTarget(1000000.00);
        newNode-> setEdgeToTarget(nullptr);
      }

      // get userCity
      std::cout << "Enter destination city: ";
      std::cin >> userCity;
      std::cout << std::endl;

      // to city: find your city
      Node* cityNode = newGraph-> find(userCity);
      cityNode-> setPriceToTarget(0.00);
      cityNode-> setEdgeToTarget(nullptr);

      // flying from/departure city
      std::string fromCity;
      std::cout << "Enter departure city: ";
      std::cin >> fromCity;
      std::cout << std::endl;

      // find departure city
      Node* departureCity = newGraph-> find(fromCity);

      // double nested loop 
      for (int i = 0; i < newGraph-> getGraphNodes().size(); i++) {
        for (Node* newNode : newGraph-> getGraphNodes()) {
          // label nodes with:
          // how much it costs to get to destination
          newNode-> updateNode();
        }
      }
      departureCity-> printPath();
      // which direction to get here: Edge* to that flight
    }

    // traveling sales being problem: finding shortest but most efficient route for someone to take to destinations
    // recursive lookaround, one node asked the next node and stuff gets done
    else if (choice == 7) {
      std::vector<Edge*>* edgePointers;
      // leave all cities unmarked
      for (Node* newNode : newGraph-> getGraphNodes()) {
        newNode-> setIsMarked(false);
        newNode-> setPriceToTarget(1000000.00);
        newNode-> setEdgeToTarget(nullptr);
      }

      // user can type a city or the computer can pick a random city (does all cities anyway)
      // prompt user for city name and see all places you can get to from that city
      std::cout << "Enter city name: ";
      std::cin >> userCity;

      std::cout << std::endl;

      // one argument for traveling sales being problem
      int numFlightsLeft = newGraph-> getGraphNodes().size();

      // find city: starting point
      Node* cityNode = newGraph-> find(userCity);

      // resetting prices and edges in the cityNodes
      cityNode-> setPriceToTarget(0.00);
      cityNode-> setEdgeToTarget(nullptr);

      // travelingSalesBeing is recursive function that finds path that gets you to last city node: the argument
      edgePointers = cityNode-> travelingSalesBeing(cityNode, numFlightsLeft);

      std::cout<<"\nSolution:\n";
      // catching nullptr to prevent any segmentation errors
      if ( edgePointers == nullptr ) { std::cout<<" no sol\n";}
      else
      {
        // print out edge pointers
        for (Edge* newEdge : *edgePointers) {
          newEdge-> report();
        }
      }
    }

    // Quit option
    else if (choice == 0) {
      std::cout << "Thanks for using this program. Goodbye!" << std::endl;
    }

    // error check
    else {
      std::cout << "Invalid input. Please try again. " << std::endl;
    }

  }
};
