//#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "../catch/catch.hpp"

#include "../BFS.h"

using namespace std;


// use smaller sample of data [testAirport.dat] to check validity of BFS
TEST_CASE("BFS finds all nodes in graph") {

    AirportGraph test = AirportGraph("data/testAirport.dat", "data/testRoute.dat");

    vector<AirportNode> airports = test.getAllNodes();
    vector<string> airportInfo = {"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA","-6.081689834590001","145.391998291","5282","10","U","Pacific/Port_Moresby","airport","OurAirports"};

    AirportNode start(1, airportInfo);

    BFS bfs(test, start); 

    // run through a subset of nodes and check if visited and doesn't loop
    REQUIRE( bfs.visited[0] == start );

    int totalVisited = 0;
    for(size_t i = 1; i < airports.size(); i++) {
        if(bfs.visited[i] == start) break;
        else totalVisited++;
    }
    REQUIRE( totalVisited == airports.size()-1 );
}
