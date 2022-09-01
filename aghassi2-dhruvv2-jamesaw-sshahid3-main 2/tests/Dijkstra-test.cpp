#include "../catch/catch.hpp"
#include <vector>

#include "../AirportGraph.h"
#include "../Dijkstra.h"


using namespace std;

TEST_CASE("Dijkstra's finds the shortest path between nodes") {

    AirportGraph test = AirportGraph("data/test_airport_sara2", "data/test_route_sara");

    vector<AirportNode> airports = test.getAllNodes();

    // between GKA and HGU in km
    Dijkstra a = Dijkstra();
    pair<vector<AirportNode>, double> answer = a.runAlgorithm(test, airports[0], airports[2]);

    REQUIRE( answer.second == 106.71 );
}
