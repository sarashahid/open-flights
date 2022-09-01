#include "AirportEdge.h"

#include <stdlib.h>
#include <stdio.h>
#include <cstring>

AirportEdge::AirportEdge(double weight_, std::vector<std::string> airlineInfo) {
    char buffer[airlineInfo[1].length() + 1];
    std::strcpy(buffer, airlineInfo[1].c_str());
    airlineID = atoi(buffer);

    char buffer3[airlineInfo[3].length() + 1];
    std::strcpy(buffer3, airlineInfo[3].c_str());
    sourceID = atoi(buffer3);

    char buffer5[airlineInfo[5].length() + 1];
    std::strcpy(buffer5, airlineInfo[5].c_str());
    destID = atoi(buffer5);


    airline = airlineInfo[0];
    sourceIATA = airlineInfo[2];
    destIATA = airlineInfo[4];
    weight = weight_;
}


