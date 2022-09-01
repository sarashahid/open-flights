#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctype.h>
#include "AirportGraph.h"

#include "AirportGraph.h"
#include "Dijkstra.h"
#include "ShortestPaths.cpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main () {
	AirportGraph graph = AirportGraph("data/airports.dat", "data/routes.dat");

	string source, dest, bestPath;

	size_t srcIdx, destIdx;

	vector<AirportNode> airports = graph.getAllNodes();

	while(1) {
		cout<<"Enter the name of the source airport: ";
		cin>>source;
		for(size_t i = 0; i < airports.size(); i++) {
			if(airports[i].name == dest) {
				srcIdx = i;
				break;
			} else {
				cout<<"That name is an invalid input or not included in this dataset"<<endl;
			}
		}
	}
	cout<<endl;

	while(1) {
		cout<<"Enter the name of the destination airport: ";
		cin>>dest;
		for(size_t i = 0; i < airports.size(); i++) {
			if(airports[i].name == dest) {
				destIdx = i;
				break;
			} else {
				cout<<"That name is an invalid input or not included in this dataset"<<endl;
			}
		}
	}
	cout<<endl;

	Dijkstra dijkstra(graph, airports[srcIdx], airports[destIdx]);
	int dist = 0;

	vector<vector<AirportNode> > bestPathNodes = getShortestPaths();

	bestPath = bestPathNodes[0][0].name;

	for(size_t i = 1; i < bestPathNodes[0].size(); i++) {
		bestPath = bestPath + " ==> " + bestPathNodes[0][i].name;
	}

	ofstream out("results/output.txt");
	out<<"Starting airport: "<<source<<"	Ending airport:"<<dest<<endl;
	out<<"Best path: "<<bestPath<<"	  Distance: "<<dist<<endl;
	out.close();


	cout<<"The shortest route between "<<source<<" and "<<dest<<" is via "<<bestPath<<endl;
	return 0;
}