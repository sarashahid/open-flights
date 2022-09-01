/* Dijkstra's algorithm */
#include "Dijkstra.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream> 
#include <queue>
#include <vector>
#include <limits>
#include <set>
#include <utility>
#include <functional>

#define INF 0x3f3f3f3f

using namespace std;

pair<vector<AirportNode>, double> Dijkstra::runAlgorithm(AirportGraph g, AirportNode s, AirportNode d) {
    std::set<AirportNode> visited;
    // start at s
    // add all neighbors to priority queue
    // get neighbors from getAdjacentNodes
    // pop off queue and repeat
    std::priority_queue<std::pair<int, AirportNode> > pq;
    pq.push(std::make_pair(0, s));
    std::map<AirportNode, double> dist;

    std::map<int, int> neighborIDToCurrent;
    
    // init distances
    vector<AirportNode> allNodes = g.getAllNodes();
    for (unsigned i = 0; i < allNodes.size(); i++) {
        dist[allNodes[i]] = INF;
        vector<AirportNode> neighborNodes = g.getAdjacentNodes(allNodes[i]);
        for (unsigned j = 0; j < neighborNodes.size(); j++) {
            neighborIDToCurrent[neighborNodes[j].airportID] = allNodes[i].airportID;
        }
    }
    dist[s] = 0;

    while (!pq.empty() && pq.top().second.airportID != d.airportID) {
        double weight = pq.top().first;
        AirportNode current_node = pq.top().second;
        
        vector<AirportEdge> neighbors = g.getAdjacentEdges(current_node);
        for (unsigned i = 0; 0 < neighbors.size(); i++) {
            AirportEdge neighbor = neighbors[i];
            AirportNode* node = g.getNode(neighbor.destID);
            if (node == NULL)
                continue;
            
            if (visited.find(*node) == visited.end()) {
                if (abs(weight) + neighbor.weight < dist[*node])
                dist[*node] = abs(weight) + neighbor.weight;
            
                pq.push(std::make_pair((-1 * dist[*node]), (*node)));
                neighborIDToCurrent[node->airportID] = current_node.airportID;
            }
        }

        visited.insert(current_node);
        pq.pop();
    }

    double shortest_path_distance = dist[d];
    AirportNode iter_node = d;
    vector<AirportNode> shortest_path;
    
    while(neighborIDToCurrent[iter_node.airportID] != s.airportID) {
        shortest_path.push_back(iter_node);
        iter_node = *g.getNode(neighborIDToCurrent[iter_node.airportID]);
    }
    shortest_path.push_back(s);

    return make_pair(shortest_path, shortest_path_distance);
}
