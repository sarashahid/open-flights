#include "ShortestPaths.h"

ShortestPaths::ShortestPaths(AirportGraph graph, AirportNode start, AirportNode end) {
    start_ = start;
    end_ = end;
    g = graph;
    startPath.push(start_);
    paths.push(startPath);
    allPaths(NULL, start_, end_);
}


void ShortestPaths::allPaths(AirportNode* previous, AirportNode start, AirportNode end) {
    if (start == end) {
        return;
    }

    vector<AirportNode> neighbors = g.getAdjacentNodes(start));
    vector<AirportNode>::iterator used;
    for (auto path = paths.begin(); path != paths.end(); path++) {

        for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
            for (auto a = path->begin(); a != path->end(); a++) {
                if (previous != NULL) {
                    if (neighbor == a && path->back().airportID != previous->airportID) {
                        continue;
                    }
                    vector<AirportNode> newPath = *path;
                    newPath.push(*neighbor);
                    paths.push(newPath);
                    allPaths(&start, *neighbor, end);      
                    used = path;      
                }
            }
        }

        if (used == path) {
            paths.erase(used);
        }

    }
}

vector<vector<AirportNodes>> ShortestPaths::getShortestPaths() {
    vector<vector<AirportNode>> shortestPaths;

    for (vector<AirportNode> path : paths) {
        double dist;
        for (vector<AirportNode>::iterator it = path.begin(); it != path.end() - 1; ++it) {
            AirPortEdge* edge = g.getEdge(*it, *(it + 1));
            dist += edge->weight;
        }
        Dijkstra dijkstra_ = Dijkstra(g, start_, end_);
        if (dist == dijkstra_.minDist) {
            shortestPaths.push(path);
        }
    }

    return shortestPaths;
}
