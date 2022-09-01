#pragma once

#include "ShortestPaths.h"
#include "AirportGraph.h"

class BetweennessCentrality {
    public:
        AirportGraph g;

        BetweennessCentrality(AirportGraph graph);

        double getBetweennesscentrality(AirportNode v);

        int getNumOfSPwVertex(vector<vector<AirportNode> > paths, AirportNode v);
};
