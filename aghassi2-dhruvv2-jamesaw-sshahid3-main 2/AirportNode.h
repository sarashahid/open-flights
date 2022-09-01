#include <cmath>
#include <vector>
#include <map>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;


class AirportNode {
    public:
        int airportID;
        string name;
        string city;
        string country;
        double latitude;
        double longitude;
        double altitude;
        string timezone;

        AirportNode(int ID, vector<string> airportInfo);
        bool operator<(const AirportNode ob) const;
        bool operator==(const AirportNode other) const;
};
