#pragma once

#include "AirportEdge.h"
#include "AirportNode.h"

#include <cmath>
#include <vector>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;


class AirportGraph {

    public:
        /* 
            Default constructor, does nothing;
        */
        AirportGraph();

        /*
            AirportGraph constructor -> reads in airport and route files & creates AirportGraph object, Nodes, and Edges
        */
        AirportGraph(const std::string & my_airports, const std::string & my_routes);

        std::vector<AirportNode> nodes;
        std::vector<AirportEdge> edges;
        std::map<int, int> ID_to_index;
        std::map<int, std::vector<AirportEdge> > NodeToEdge; //maps airportID to list of edges where that ID is the source

        /*
            Takes in sourceID and destinationID as ints
            returns double that is equal to weight of the edge aka
            distance between the two airports
        */
        double havsinDist(int source, int dest);
        static double havsin(double theta);

        /*
            takes in airport ID and returns pointer to corresponding node
        */
        AirportNode* getNode(int ID);
        /*
            getAllNodes returns vector of all AirportNodes in the graph
        */
        vector<AirportNode> getAllNodes();

        /*
            getAdjacentEdge returns vector of all edges where curr is source
            if there are none, it will return EMPTY vector
        */
        vector<AirportEdge> getAdjacentEdges(AirportNode curr);

        /*
            getAdjacentNode returns vector of all nodes where curr is source
            if there are none, it will return EMPTY vector
        */
        vector<AirportNode> getAdjacentNodes(AirportNode curr);

        /*
            getEdge returns node that is between first and second nodes
            return a Edge with weight of -1 if an edge does not exist
        */
        AirportEdge getEdge(AirportNode first, AirportNode second);
        

    private:
        double r = 6371.07103; /* in kilometers */ 
        std::vector<std::vector<std::string> > all_airports; //Index: Airport ID.... Vector: Name, City, Country, Latitude, Longitude, Altitude, Timezone
        std::vector<std::vector<std::string> > all_routes; //Index: N/A.... Vector: Airline, Airline ID, Source airport	3-letter (IATA), Source airport ID, Destination airport	3-letter (IATA), Destination airport ID
};

//move parsing back into airport graph
//when i call airport graph, it automatically parses the data
//then it enters the data into the Node and Edge constructors Node(vector<> info)

