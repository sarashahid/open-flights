#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>
#include "BFS.h"
#include <queue>

BFS::BFS(AirportGraph g, AirportNode start) {

    queue.push(start);
    visited.push_back(start);

    while (!queue.empty()) {
        AirportNode curr = queue.front();
        queue.pop();

        vector<AirportNode> neighbors = g.getAdjacentNodes(curr);
        for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
            for (auto a = visited.begin(); a != visited.end(); a++) {
                if (neighbor != a) {
                    queue.push(*neighbor);
                    visited.push_back(*neighbor);
                }
            }
        }
    }
}

// BFS::BFS(AirportGraph graph, int start) {  
//   visited.resize(verticies);

//   for(int i = 0; i < verticies; i++){
//       visited[i] = false;
//   }
//   visited[start] = true;
//   queue.push(start);

//   list<int>:: iterator it;

//   while(!queue.empty()){
//       int curr = queue.front();
//       queue.pop();

//       for(it = adjacencyList[curr].begin(); it != adjacencyList[curr].end(); ++it){
//           int adjvertex = *it;
//           if(!visited[adjvertex]){
//               visited[adjvertex] = true;
//               queue.push(adjvertex);
//           }
//       }
//   }
// }


// BFS::~BFS(){
  
// };


// //Adds a Point for the traversal to visit at some point in the future.
 
// void BFS::add(const AirportNode & vertex) {
//  // @todo [Part 1] 
//   queue.push(vertex.airportID);
// }


// //Removes and returns the current Point in the traversal.

// int BFS::pop() {
//   //@todo [Part 1]
//   int front = queue.front();
//   queue.pop();
//   return front;
// }


// //Returns the current Point in the traversal.

// int BFS::peek() const {
//   //@todo [Part 1]
//   return queue.front();
// }


// //Returns true if the traversal is empty.

// bool BFS::empty() const {
//  //@todo [Part 1] 
//   return queue.empty();
// }


// bool BFS::getVisited(AirportNode vertex){
//   return visited[vertex.visited]; // Vertex will have a bool visited value
// }

// void BFS::setVisited(AirportNode vertex){
//   visited[vertex.visited] = true;
// }
