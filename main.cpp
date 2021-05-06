#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

void report();

/*
- Cheapest flight to somewhere
- Cheapest flight with fewest number of hops

If you see first line is a city, you know next string is a cityname and make city for it (one string and nake Node for city)

If first line is a flight, you know there will be two strings and both are node names. Find nodes in graphNodes list
*/
enum Menu {
  LISTOFCITIES = 1,
  CITYCONNECTIONS = 2,
  CHEAPESTFLIGHT = 3,
  CITYGRAPH = 4,
  QUIT = 5
};

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
    std::cout << "MENU:\n1 = List of Cities\n2 = City Connections\n3 = Cheapest Flight\n4 = City Graph\n5 = At Least 3 Flights\n0 = Quit\nEnter your choice: ";

    std::cin >> choice;
    std::cout << std::endl;

    // list of city
    if (choice == 1) {
      std::cout << "OPTION 1: LIST OF CITIES" << std::endl;
      // list cities
      for (Node* eachCity : newGraph-> getGraphNodes()) {
        std::cout << "City: " << eachCity-> getName() << std::endl;
      }
    }

    // city connections
    else if (choice == 2) {
      std::cout << "OPTION 2: CITY CONNECTIONS" << std::endl;
      // prompt user for city name and see all places you can get to from that city
      std::cout << "Enter city name: ";
      std::cin >> userCity;
      std::cout << std::endl;

      Node* cityNode = newGraph-> find(userCity);
      cityNode-> report();
    }
    
    // cheapest flight
    else if (choice == 3) {
      Edge* flight = newGraph-> lowestPrice();

      // cheapest flight
      // keep track of lowest cost one as you go through
      std::cout << "The lowest price flight is: " << std::endl;
      flight-> report();
    }

    // Connectivity (see how everything is connected): list all cities can get to from chicago, start marking process
    else if (choice == 4) {
      for (Node* newNode : newGraph-> getGraphNodes()) {
        newNode-> setIsMarked(false);
      }

      std::cout << "Enter city name: " << std::endl;
      std::cin >> userCity;

      // find city , then call recursive function
      Node* cityNode = newGraph-> find(userCity);
      cityNode-> connectionMap();

      for (Node* newNode : newGraph-> getGraphNodes()) {
        if (newNode-> getIsMarked()) {
          newNode-> report();
  
        }
      }
    }

    // find city with at least 3 flights
    else if (choice == 5) {
      Node* cityNode = newGraph-> find(userCity);
      cityNode-> reportThreeConnections();
    }

    else if (choice == 0) {
      std::cout << "Thanks for using this program. Goodbye!" << std::endl;
    }

    // error check
    else {
      std::cout << "Invalid input. Please try again. " << std::endl;
    }

    // traveling sales being - recursive lookaround, one node asked the next node and stuff gets done
    // shortest path another one
  }

    /*
  Menu choice;
  switch(choice) {
    case LISTOFCITIES:
      // list cities
      for (Node* eachCity : newGraph-> getGraphNodes()) {
        std::cout << "City: " << eachCity-> getName() << std::endl;
      }
      break;

    case CITYCONNECTIONS:
      // prompt user for city name and see all places you can get to from that city
      std::cout << "Enter city name: " << std::endl;
      std::cin >> userCity;

      Node* cityNode = newGraph-> find(userCity);
      cityNode-> report();
      break;

    case CHEAPESTFLIGHT:
      break;

    case CITYGRAPH:
      break;

    case QUIT:
      break;
  }
  */
};
