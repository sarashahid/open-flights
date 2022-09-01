Final Project Results

## Project Setup:
For our project, we wanted to find the shortest path between two airports, and find the flight with the shortest distance between 2 selected airports, while returning airports that have the most number of shortest routes passing through them.. 
### Goals:
We planned to use Dijkstra’s algorithm to iterate through vertices and highlight the shortest path between airport a and airport b. To find the airport with the most air traffic we planned to use betweenness centrality. 
### Datasets:
In order to accomplish this, we used the airports.dat and the routes.dat datasets. The airports.dat file included information such as the name of the airport, the city, and the latitude and longitude coordinates of the airport. 
### Timeline:
We checked the timeline nearing the end of our project and realized that we were mostly on track based on the order of which we had to get the items on the agenda done. However, we were a few days behind because as we were coding our project we would find errors that we didn't take into account. If we were to do this project over again with more knowledge of the programming constraints, we would have tried to be more strict with our enforcing of some of the dates on the timeline to make sure that we were accomplishing the tasks in time to work on other ones. 

## Graph Implementation:
When creating the graph structure, we created an AirportEdge class, an AirportNode Class, an AirportGraph class, and an AirportGraph.cpp file which sorted through all of the data and passed the data on to the edge and node classes to make the graph structure. We used inheritance to get this information passed down through all the graph related classes. 


## Algorithms:
### Dijkstra: 
In the case of this project, we wanted to find the shortest path from one airport to another, and we chose to use Dijkstra’s algorithm to compute all nearby nodes and their distances. To summarize our code for this part, we iterate through all the adjacent vertices, putting them in a min priority queue (which essentially stores data from least to greatest values). While we store the values in the min priority queue, we also store the edge weights in a different queue so we can print the final distance travelled. We also create another vector variable that stores the visited n
and we make sure that it does not equal the neighbor so that we can ensure that the program is always moving forward.
#### Discoveries and Issues: 
A discovery we made as we were writing the program was that we also needed to make sure that we knew which vertices were part of the visited and which ones were part of the specified path we were on. This was a problem that we realized would arise later. Another issue was that when setting the distances of all edges from the source to infinity, it wasn't getting used later on in the actual traversal algorithm. We then implemented some changes by adding an if statement inside the nested for loop to account for the infintily weighted edges.

### BFS:
For the project, we had to use a traversal algorithm to find all the vertices. We chose Breadth First Search (BFS). We implemented it by adding nodes to a neighbor vector and traversing through our graph, which we used as an input along with a starting node.

### Betweenness Centrality:
This representation helps see which airports are more travelled to than others, which alligns with our goal to display the airports with the most air traffic. We used a ShortestPaths class as a helper class. Unfortuantely Dijkstra's didn't provide us with multiple shortest paths so it didn't end up working in the end.

## Conclusion
### Overview:
In conclusion, our project was to get a client from one airport to another across the world. Using the datasets (routes.dat and airlines.dat), we wanted to get the data, create a graph and essentially connect two points on the graph using Dijkstra’s algorithm. We also wanted to use Betwenness Centrality to display the results in a more visual way, but unfortunately it didn't end up working out in the end.
