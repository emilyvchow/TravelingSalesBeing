#include "Node.h"
#include <iostream>

bool bug = false;

// report() prints out each edge in the edges vector
void Node::report() {
  std::cout << name << " connects to: " << std::endl;

  // list all the edges here and report
  for (Edge* newEdge : edges) {
    newEdge->report();
  }
}

// printPath() will print the price of edge and the price to target for each flight
void Node::printPath() {
  // if edge to target
  // recursion: prints one and tells the one you're going to to finish
  if (getEdgeToTarget() != nullptr) {
    // say fly to other end
    std::cout << getEdgeToTarget()-> otherEnd(this)-> getName();

    // printing the prices of each edge/flight
    std::cout << ": Price of flight is " << getEdgeToTarget()-> getCost() << std::endl;
    std::cout << "Total price to target is: " << priceToTarget << std::endl;

    std::cout << std::endl;

    // call printPath on other end
    getEdgeToTarget()-> otherEnd(this)-> printPath();

  }  
}

// connectionMap() starts with blank graph: if not marked, mark yourself and where you are at and call neighbors to do the same
void Node::connectionMap() {
  // Function goes thru all edges and they are marked and go through other city and mark those until graph is as marked as possible
  if (!isMarked) {
    isMarked = true;
    // mark all neighbors
    for (Edge* newEdge : edges) {
      // this is the node I am in and getting the other city of the flight
      Node* otherEnd = newEdge-> otherEnd(this);
      otherEnd-> connectionMap();
    }
  }
  // if not marked, avoid getting stuck in a loop
}

// updateNode() will compare the prices of each edge and will store the lowest price and edge for the user. used to print nodes nicely in main.cpp too
void Node::updateNode() {
  double totalPrice = 0.00;

  for (Edge* eachEdge: edges) {
    // computer total price (add prices to totalPrice)
    totalPrice = eachEdge-> getCost() + eachEdge-> otherEnd(this)-> getPriceToTarget();

    // comparison: if edge gives better price than one i've got
    if (totalPrice < priceToTarget) {
      priceToTarget = totalPrice;
      edgeToTarget = eachEdge;
    }
  } 
}

// costOfTrip() holds length of vector (bunch of flights, how much does it cost) and calculates the totalPrice of trips
double Node::costOfTrip(std::vector<Edge*>* trips) {
  if (trips == nullptr) {
    return 0;
  }
  // initalize total price and start at 0
  double totalPrice = 0.00;
  // go through all edges and add up
  for (Edge* newEdge : *trips) { // BEK a bug, was going through this node's edges instead of the trips
    if (bug) { 
      std::cout<< " Doing cost ... ";
    }
    totalPrice += newEdge-> getCost();
  }

  return totalPrice;
}

// space() is a debugging function
void space(int x)
{
  for ( int i = 0; i<x; i++ )
  { std::cout<<"  "; }
}

// for debugging and prints stuff about this path
void Node::say(int s, std::vector<Edge*>* es)
{  space(s); std::cout<<"size of list: " <<es->size() <<"\n";
  space(s);
   if ( es!=nullptr )
   { std::cout<<"path (" <<costOfTrip(es) <<") ";
    for ( Edge* e : *es)
    {
      std::cout <<"[";
      std::cout <<e->getConnection1()->getName() <<" ";
      std::cout <<e->getConnection2()->getName() <<" ";
      std::cout <<"] ";
    }
    std::cout <<std::endl;
  }
  else
  { space(s); std::cout<<"null list\n";}
}

// travelingSalesBeing() finishes the graph from here: go through all remaining cities cheaply and comes back home through graphs, comparing nodes, and marking each city until the graph is complete
std::vector<Edge*>* Node::travelingSalesBeing(Node* destination, int flightCounter) {
  if(bug){ 
    space(flightCounter); 
    std::cout <<"go: " << getName() << std::endl;
  }

  // best path right now
  std::vector<Edge*>* path = nullptr;
  double bestCost = 10000000;

  // 1 means have to go home
  if (!isMarked) {
    // base case
    if (flightCounter == 1) {
      // go home
      if(bug){ space(flightCounter); std::cout<<"last leg\n";}
      // destination, flightCounter = 0;
      for (Edge* newEdge : edges) { //BEK a bug , was going through path ???
        // look through list of edges to see if any go where you want to go
        if (newEdge->otherEnd(this) == destination) {
          // path with just one flight on it that goes home
          path = new std::vector<Edge*>();

          // this goes where you want to go
          path->push_back(newEdge);
          break;
        }
      }
    }
    else {
      isMarked = true;
      double totalPrice = 10000000.00;

      // mark all neighbors and go through all remaining edges
      for (Edge* newEdge : edges) {
        // this is the node I am in - call yourself
        Node* otherEnd = newEdge-> otherEnd(this);
        if ( otherEnd->isMarked ) { continue; } // BEK shortcut
        // repeat the process and go out/connect until all edges are covered (recursive function/call)
        // decrement counter
        std::vector<Edge*>* possibilities = otherEnd-> travelingSalesBeing(destination, flightCounter-1);

        if (possibilities != nullptr) {
            // skip if nullptr
          possibilities-> push_back(newEdge);

          // compare possibilities to paths we have, comparison based on length of path      
          totalPrice = costOfTrip(possibilities);

          // ask friends which one has the best one to finish trip and that's where we go with
          // computer totals the price and sees how much it costs(add prices to totalPrice)

          // if edge gives better price than one i've got
          if (totalPrice < bestCost) {
            // come back home for the cheapest
            bestCost = totalPrice;

            // delete old path if not null to prevent memory leak
            if (path != nullptr) {
              delete path;
            }

            // replace path for best path
            path = possibilities;
          }
          else {
            // delete possibilities that is a memory leak
            if (possibilities != nullptr) {
              delete possibilities;
            }
          }
          // call your friends to see how much it costs to travel to cities and come back until nothing is left: recursive solution
        }
      }

      // mark other cities you know and tell them to mark where you are at
      // mark all neighbors and mark those
      // etc

      // set all cities to false
      isMarked = false;
    }
  }
  if(bug)
  {
    say( flightCounter, path );
  }
  return path;
}
