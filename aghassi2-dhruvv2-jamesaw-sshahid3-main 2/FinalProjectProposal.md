# Final Project Proposal

## Leading Question 
The goal of our project is to find the flight with the shortest distance between 2 selected airports, while returning airports that have the most number of shortest routes passing through them. 

## Dataset Acquisition and Processing
The dataset our group will be using is from the OpenFlights airports and routes databases found here https://openflights.org/data.html. The exact files in question are airports.dat and routes.dat. The nodes of the graph will represent the airports, while the edges of the graph will represent airline routes. The edges will be weighted with the distance between the aiports (nodes). This weight is determined using the longitude and latitude corresponding to the unique OpenFlights aiport identifier value provided in the aiports.dat files. These latitudes and longitudes will be used to calculate the Haversine distance. Note: the Haversine distance is an approximation assuming that the Earth is a perfect sphere, however we are willing to use the approximated value for the purposes of our algorithm because we do not forsee needing a further exact value for distance. 

## Graph Algorithms
Our group intends to implement Dijkstra’s Algorithm for the shortest path, betweenness centrality, and a BFS traversal. Dijkstra's will take in 2 vertices as inputs and return the shortest path between them. For the runtime of Dijkstra's, if we use a min-priority queue we estimate the runtime to be O(V+E logV), where V is the number of vertices and E is the number of Edges. 

The BFS Traversal will have a runtime of O(V + E), where V is the number of vertices and E the number of edges. We will iterate through all points in the graph and mark visited points until all points are visited. 

The betweenness centrality algorithm will take in the entire graph and return the vertices with the most edges. For betweenness centrality, the goal is to reach a runtime of O(V^3), where V is the number of vertices. The reason for using betweenness centrality is to find airports that have the most number of flights that pass through it, which in turn will tell us the most frequently travelled to airports in the list of shortest routes.

## Timeline 
 * By 11/15: Data acquistion start graph building
 * By 11/22 Implement BFS and partially completed Dijkstra's 
 * By 11/29 Start betweenness centrality and finish Dijkstra's
 * By 12/6 Project finished
 * 12/13 Finish report/presentation
