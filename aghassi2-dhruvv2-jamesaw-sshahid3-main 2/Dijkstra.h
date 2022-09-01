#pragma once

#include "AirportGraph.h"

using namespace std;

class Dijkstra {
    public:
        pair<vector<AirportNode>, double> runAlgorithm(AirportGraph g, AirportNode s, AirportNode d);

};

/* Dijkstra's .h file */
/*
#include "AirportGraph.h"

#pragma once
using namespace std;

class Dijkstra : public AirportGraph{
    public:
    double minDistance (int dist[], bool set[]);

    private:
    int vertices;
    //void dijkstra(int graph[V][V], int src);
    Dijkstra::Dijkstra(int vertices);
    Dijkstra::Dijkstra(AirportGraph g, AirportNode s, AirportNode d);

};
*/
