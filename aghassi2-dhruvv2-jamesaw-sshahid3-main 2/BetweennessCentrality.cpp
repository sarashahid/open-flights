#include "BetweennessCentrality.h"

BetweennessCentrality::BetweennessCentrality(AirportGraph graph) {
    g = graph;
}

double BetweennessCentrality::getBetweennesscentrality(AirportNode v) {
    double betweennessCentrality = 0;

    vector<AirportNode> nodes_ = g.nodes;
    for (vector<AirportNode>::iterator it = nodes_.begin(); it != nodes_.end(); ++it) {
        vector<AirportNode> nodes2 = nodes_.erase(it);
        for (AirportNode node2: nodes2) {
            /* need to constuct getShortestPaths, probably in Dijkstra's algorithm*/
            ShortestPaths shortestPaths(g, *it, node2);
            vector<vector<AirportNode>> shortestPaths_ = shortestPaths.getShortestPaths();
            int spAmount = shortestPaths_.size();
            int spWVertex = getNumOfSPwVetrtex(shortestPaths_, v);
            betweennesscentrality +=  spWVertex/spAmount;
        }
    }

    betweennessCentrality /= 2;
    return betweenessCentrality;
}

int BetweennessCentrality::getNumOfSPwVertex(vector<vector<AirportNode> > paths, AirportNode v) {
    int sum = 0;
    for (vector<AirportNode> path : paths) {
        for (AirportNode node : path) {
            if (node.airportID == v.airportID) {
                sum++;
            }
        }
    }

    return sum;
}
