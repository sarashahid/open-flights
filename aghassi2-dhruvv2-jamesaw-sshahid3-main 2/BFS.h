#pragma once
#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include "AirportGraph.h"

//#include "graph.h" what we will instantiate


class BFS : public AirportGraph {
  public:
    BFS(AirportGraph graph, AirportNode start);
    std::vector<AirportNode> visited;
    std::queue<AirportNode> queue;
  private:
};


// using namespace std;

// class BFS : AirportGraph{
// public:
//   int verticies; // total number of vertices
//   list <int> *adjacencyList;

//   BFS(AirportGraph graph, int start);
//   ~BFS();

//   void add(const AirportNode & point);
//   AirportNode pop();
//   AirportNode peek() const;
//   bool empty() const;

//   bool getVisited(AirportNode point);
//   void setVisited(AirportNode point);

// private:

//   std::queue<int> queue;
//   std::vector<bool> visited;
  
// };
