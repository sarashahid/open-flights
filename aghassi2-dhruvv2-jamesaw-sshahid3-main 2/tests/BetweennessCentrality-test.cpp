#include "../catch/catch.hpp"
#include <vector>

#include "../AirportGraph.h"
#include "../BetweennessCentrality.h"

using namespace std;

//checks a small subset of the data
TEST_CASE("Betweenness centrality works on the dataset") {

    AirportGraph test = AirportGraph("data/testAirport.dat", "data/testRoute.dat");;

    vector<AirportNode> airports = test.getAllNodes();

    BetweennessCentrality b = BetweennessCentrality(test);
    
    double val = b.getBetweennesscentrality(airports[0]);

    REQUIRE( val == 8.0);
}
