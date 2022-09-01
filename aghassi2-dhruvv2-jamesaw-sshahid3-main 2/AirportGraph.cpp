#include "AirportGraph.h"

AirportGraph::AirportGraph()
{
    // do nothing
}

AirportGraph::AirportGraph(const std::string & my_airports, const std::string & my_routes) {
    /* 
		Airport ID, Name, City, Country, IATA, ICAO, Latitude, Longitude, Altitude, Timezone, DST, Type, Source

		Sample: 324,"All Nippon Airways","ANA All Nippon Airways","NH","ANA","ALL NIPPON","Japan","Y"
	*/
    std::ifstream text2(my_airports); //std::ifstream text2(filename)
	//text2.open("data/testAirport.dat");
	std::string dat2;

	if (text2.is_open()) {
		while (getline(text2, dat2)) {
            vector<string> a;
            std::stringstream s(dat2);
            int count = 0;
            string airport_id;
            while (s.good() && count < 10) {
                string sub;
                getline(s, sub, ',');
                if (count == 0) {
                    airport_id = sub;
                }
                if (count != 0 && count != 4 && count!= 5) {
                    a.push_back(sub);
                }
                count++;
            }
            a.push_back(airport_id);
			all_airports.push_back(a);
		}
	}
    text2.close();
    //std::cout << "Reached line " << __LINE__ << " all_airports size: " << all_airports.size() << std::endl;

    //go through each all_airports and create a AirportNode from the vector at all_airports[i]
    //add all those nodes to nodes vector
    //return nodes
    for (unsigned i = 0; i < all_airports.size(); i++) {
        string id = all_airports[i][all_airports[i].size() - 1];
        char buffer[id.length() + 1];
        std::strcpy(buffer, id.c_str());

        AirportNode n = AirportNode(atoi(buffer), all_airports[i]); // = new AirportNode
        ID_to_index[atoi(buffer)] = i;
        nodes.push_back(n);
    }

    /*
		Airline, Airline ID, Source airport	3-letter (IATA), Source airport ID, Destination airport	3-letter (IATA), Destination airport ID,
		Codeshare, Stops, Equipment
        1, 3, 5
		Sample: BA,1355,SIN,3316,LHR,507,,0,744 777
	*/
    std::ifstream text(my_routes);
	//text.open("data/testRoute.dat");
	std::string dat;

	if (text.is_open()) {
		while (getline(text, dat)) {
            vector<string> r;
            std::stringstream s_(dat);
            int count_ = 0;
            while (s_.good() && count_ < 6) {
                string sub_;
                getline(s_, sub_, ',');
                r.push_back(sub_);
                count_++;
            }
			all_routes.push_back(r);
		}
	}
    text.close();

    for (unsigned j = 0; j < all_routes.size(); j++) {
        char buffer[all_routes[j][3].length() + 1];
        std::strcpy(buffer, all_routes[j][3].c_str());

        char buffer2[all_routes[j][5].length() + 1];
        std::strcpy(buffer2, all_routes[j][5].c_str());

        //std::cout << "Reached line " << __LINE__ << "buffer val " << atoi(buffer) << " buffer2 val: " << atoi(buffer2) << std::endl;
        double d = havsinDist(atoi(buffer), atoi(buffer2));
        AirportEdge e = AirportEdge(d, all_routes[j]);
        edges.push_back(e);
        //AirportNode* e_node = getNode(ID_to_index[e.sourceID]);
        NodeToEdge[e.sourceID].push_back(e);
    }
}

vector<AirportNode> AirportGraph::getAllNodes() {
    return this->nodes;
}

/*
    takes in airport ID and returns pointer to corresponding node
*/
AirportNode* AirportGraph::getNode(int ID) {
    int idx = ID_to_index[ID];
    return &nodes[idx];
}


vector<AirportEdge> AirportGraph::getAdjacentEdges(AirportNode curr) {
    std::map<int, std::vector<AirportEdge> >::iterator search = NodeToEdge.find(curr.airportID);
    if (search != NodeToEdge.end()) {
        return search->second;
    }
    vector<AirportEdge> ret;
    return ret;
}

vector<AirportNode> AirportGraph::getAdjacentNodes(AirportNode curr) {
    vector<AirportEdge> edges = getAdjacentEdges(curr);
    vector<AirportNode> ret;
    if (edges.empty()) {
        return ret;
    }
    for (unsigned i = 0; i < edges.size(); i++) {
        AirportEdge e = edges[i];
        int adj_ID = e.destID;
        ret.push_back(*getNode(adj_ID));
    }
    return ret;
}


// double AirportGraph::getEdgeWeight(AirportNode first, AirportNode second) {
//     AirportEdge* temp = getEdge(first, second);
//     if (temp != NULL) {
//         return temp->weight;
//     }
//     else {
//         return -1;
//     }
// }


AirportEdge AirportGraph::getEdge(AirportNode first, AirportNode second_n) {
    std::map<int, std::vector<AirportEdge> >::iterator search = NodeToEdge.find(first.airportID);
    if (search != NodeToEdge.end()) { //first exists
        vector<AirportEdge> edges = search->second;
        for (unsigned i = 0; i < edges.size(); i++) {
            //cout << "Second_n airport id: " << second_n.airportID << endl;
            if (edges[i].destID == second_n.airportID) {
                return edges[i];
            }
        }
    }
    vector<string> emp;
    return AirportEdge(-1, emp);
}

double AirportGraph::havsin(double theta) {
    return 0.5*(1 - cos(theta));
}

double AirportGraph::havsinDist(int source, int dest) {
    vector<double> sourceCoor; //0 = lat, 1 = long
    vector<double> destCoor;
    AirportNode* s = getNode(source);
    AirportNode* d = getNode(dest);
    sourceCoor.push_back(s->latitude);
    sourceCoor.push_back(s->longitude);
    
    destCoor.push_back(d->latitude);
    destCoor.push_back(d->longitude);
    
    double latDist = destCoor[0] - sourceCoor[0];
    double longDist = destCoor[1] - sourceCoor[1];
    double h = havsin(latDist) + (1 - havsin(-1 * latDist) - havsin(destCoor[0] + sourceCoor[0])) * havsin(longDist);
    return 2*r*asin(sqrt(h));
}