#include "../AirportGraph.h"

#include "../catch/catch.hpp"

TEST_CASE("AirportGraph loads in data correctly for AIRPORTS", "[weight=1]") {
    // Create a AirportGraph object
    AirportGraph g = AirportGraph("data/test_airport_sara2", "data/test_route_sara");

    AirportNode result = g.nodes[0];
    AirportEdge result_edges = g.edges[0];

    //2965,"Sochi International Airport","Sochi","Russia","AER","URSS",43.449902,39.9566,89,3,"N","Europe/Moscow","airport","OurAirports"
    //2B,410,AER,2965,KZN,2990,,0,CR2

    REQUIRE( result.airportID == 2965 );
    REQUIRE( result.latitude == 43.449902 );
    REQUIRE( result_edges.sourceID == 2965 );
    REQUIRE( result_edges.destID == 2990 );
}

TEST_CASE("getAllNodes returns vector of correct size", "[weight=1]") {
    // Create a AirportGraph object
    AirportGraph g = AirportGraph("data/test_airport_sara", "data/test_route_sara");

    //see if size = 6
    REQUIRE( g.getAllNodes().size() == 6 );
}

TEST_CASE("getAllNodes returns vector of correct nodes", "[weight=1]") {
    // Create a AirportGraph object
    AirportGraph g = AirportGraph("data/test_airport_sara2", "data/test_route_sara");

    // create a vector that has first 2 nodes 
    vector<AirportNode> sol;
    vector<string> info1 { "Sochi International Airport","Sochi","Russia","43.449902,39.9566","89","3","2965" };
    vector<string> info2 { "Kazan International Airport","Kazan","Russia","55.606201171875,49.278701782227","411","3","2990" };
    AirportNode n1 = AirportNode(2965, info1);
    AirportNode n2 = AirportNode(2990, info2);

    //test that nodes match up
    vector<AirportNode> result = g.getAllNodes();
    REQUIRE( result[0].airportID == n1.airportID );
    REQUIRE( result[1].airportID == n2.airportID );
}

TEST_CASE("getAdjacentNodes & getNode returns vector of correct Nodes (size & data)", "[weight=1]") {
    // Create a AirportGraph object
    AirportGraph g = AirportGraph("data/test_airport_sara", "data/test_route_sara");
    // 2B,410,AER,2965,KZN,2990,,0,CR2
    // 7J,9531,AER,2965,DYU,2979,,0,735
    //node to use as curr
    AirportNode* curr = g.getNode(2965);
    REQUIRE( curr->city == "\"Sochi\"" );
    REQUIRE( curr->airportID == 2965 );
    vector<int> correct {2990, 2979};

    vector<AirportNode> result = g.getAdjacentNodes(*curr); //adj should be 2990 and 2979
    // cout << result.size() << endl;

    // for (unsigned i = 0; i < result.size(); i++) {
    //     cout<< result[i].airportID << endl;
    // }

    //check if adj Nodes have correct info
    REQUIRE( result.size() == 2 );
    for (unsigned i = 0; i < result.size(); i++) {
        REQUIRE( result[i].airportID == correct[i] );
    }
}

TEST_CASE("getEdge returns correct Edge with correct weight", "[weight=1]") {
    // Create a AirportGraph object
    AirportGraph g = AirportGraph("data/test_airport_sara2", "data/test_route_sara");

    AirportEdge edge = g.edges[0];
    int s = edge.sourceID;
    int d = edge.destID;
    AirportNode* n = g.getNode(s);
    AirportNode* v = g.getNode(d);
    AirportEdge result_edge = g.getEdge(*n, *v);
    double w = g.havsinDist(s, d);

    //2B,410,AER,2965,KZN,2990,,0,CR2

    REQUIRE( result_edge.weight == w );
    REQUIRE( result_edge.destID == 2990 );
    REQUIRE( result_edge.airlineID == 410 );
    REQUIRE( result_edge.sourceID == 2965 );
}

