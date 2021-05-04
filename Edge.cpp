#include "Edge.h"
#include <iostream>

void Edge::report() {
  std::cout << "Flight: "<< connection1-> getName() << " and " << connection2-> getName() << " costs: $" << cost << std::endl;
}