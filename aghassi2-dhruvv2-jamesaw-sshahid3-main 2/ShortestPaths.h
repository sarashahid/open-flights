#pragma once

#include <vector>
#include "AirportGraph.h"
#include "AirportNode.h"
#include "AirportEdge.h"
#include "Dijkstra.h"

using namespace std;

class ShortestPaths {
    AirportNode start_;
    AirportNode end_;
    AirportGraph g;
    vector<vector<AirportNode>> paths;
    vector<AirportNode> startPath;
    
    ShortestPaths(AirportGraph graph, AirportNode start, AirportNode end);

    void allPaths(AirportNode previous, AirportNode start, AirportNode end);

    vector<vector<AirportNode>> getShortestPaths();
};
