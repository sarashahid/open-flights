#include <cmath>
#include <vector>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;


class AirportEdge {
    public:
        int airlineID;
        int sourceID;
        int destID;
        string airline;
        string sourceIATA;
        string destIATA;
        double weight;
        string timezone;
        
        AirportEdge(double weight_, std::vector<std::string> airlineInfo);
};