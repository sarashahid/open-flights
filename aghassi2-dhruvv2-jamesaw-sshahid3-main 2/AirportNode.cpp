#include "AirportNode.h"

AirportNode::AirportNode(int ID, vector<string> airportInfo) {
    airportID = ID;

    name = airportInfo[0];

    char buffer[airportInfo[3].length() + 1];
    std::strcpy(buffer, airportInfo[3].c_str());
    latitude = atof(buffer);

    char buffer2[airportInfo[4].length() + 1];
    std::strcpy(buffer2, airportInfo[4].c_str());
    longitude = atof(buffer2);

    city = airportInfo[1];
    country = airportInfo[2];

    char buffer3[airportInfo[5].length() + 1];
    std::strcpy(buffer3, airportInfo[5].c_str());
    altitude = atof(buffer3);

    timezone = airportInfo[6];
}

bool AirportNode::operator<(const AirportNode ob) const {
    return airportID < ob.airportID;
}

bool AirportNode::operator==(const AirportNode other) const {
    if (this->airportID != other.airportID) {
        return false;
    }
    if (this->name != other.name) {
        return false;
    }
    if (this->latitude != other.latitude) {
        return false;
    }
    if (this->longitude != other.longitude) {
        return false;
    }
    return true;
}