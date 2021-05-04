#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

void report();

/*
Due Date: Tuesday, May 4 @ 10AM
Construct graph from file. Have graph constructor read data file and build it. 

TODO: 
Put in a few more cities (8)
Put in a bunch of flights
Get more data in so we have something to work with, so we can create extra algorithms
- Cheapest flight to somewhere
- Cheapest flight with fewest number of hops

Eight cities might need a couple dozen flights if you want to make a bunch of connections

TODO: 
Data.txt (Can also hardcode Data.txt)
Open file and readin
If you see first line is a city, you know next string is a cityname and make city for it (one string and nake Node for city)

If first line is a flight, you know there will be two strings and both are node names. Find nodes in graphNodes list

Not too easy to add this and make a graph
Might have to write find function (here is name, go through whole list of nodes, see if you can find node that goes with this name) -> not conceptually hard but does take code
*/


int main() {
  Graph* newGraph = new Graph();
  newGraph-> report();
};

