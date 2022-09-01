CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

main:  main.o AirportGraph.o AirportEdge.o AirportNode.o
	$(CXX) -o main main.o AirportGraph.o AirportEdge.o AirportNode.o $(CXXFLAGS)

main.o: main.cpp
	$(CXX) -c -o main.o main.cpp $(CXXFLAGS)

main.cpp:
	@echo "Making main..."

catchmain: catchmain.o
	$(CXX) -o catch/catchmain catch/catchmain.o $(CXXFLAGS)

catchmain.o: catchmain.cpp
	$(CXX) -c -o catch/catchmain.o catch/catchmain.cpp $(CXXFLAGS)

catchmain.cpp:
	@echo "making catch"


#Graph structures

AirportGraph: AirportGraph.o AirportEdge.o AirportNode.o
	$(CXX) -o AirportGraph AirportGraph.o AirportEdge.o AirportNode.o $(CXXFLAGS)

AirportGraph.o: AirportGraph.cpp
	$(CXX) -c -o AirportGraph.o AirportGraph.cpp $(CXXFLAGS)

AirportGraph.cpp:
	@echo "Making airport graph"

AirportEdge: AirportEdge.o
	$(CXX) -o AirportEdge AirportEdge.o $(CXXFLAGS)

AirportEdge.o: AirportEdge.cpp
	$(CXX) -c -o AirportEdge.o AirportEdge.cpp $(CXXFLAGS)

AirportEdge.cpp:
	@echo "Making airport edge"

AirportNode: AirportNode.o
	$(CXX) -o AirportNode AirportNode.o $(CXXFLAGS)

AirportNode.o: AirportNode.cpp
	$(CXX) -c -o AirportNode.o AirportNode.cpp $(CXXFLAGS)

AirportNode.cpp:
	@echo "Making airport node"


#algorithms

BFS: AirportGraph.o AirportEdge.o AirportNode.o BFS.o
	$(CXX) -o BFS BFS.o AirportGraph.o AirportEdge.o AirportNode.o $(CXXFLAGS)

BFS.o: BFS.cpp
	$(CXX) -c -o BFS.o BFS.cpp $(CXXFLAGS)

BFS.cpp:
	@echo "Making BFS"

BetweennessCentrality: AirportGraph.o AirportEdge.o AirportNode.o BetweennessCentrality.o ShortestPaths.o
	$(CXX) -o BetweennessCentrality BetweennessCentrality.o AirportGraph.o AirportEdge.o AirportNode.o ShortestPaths.o $(CXXFLAGS)

BetweennessCentrality.o: BetweennessCentrality.cpp
	$(CXX)  -c -o BetweennessCentrality.o BetweennessCentrality.cpp $(CXXFLAGS)

BetweennessCentrality.cpp:
	@echo "Making BetweennessCentrality"

ShortestPaths: AirportGraph.o AirportEdge.o AirportNode.o ShortestPaths.o Dijkstra.o
	$(CXX) -o ShortestPaths ShortestPaths.o AirportGraph.o AirportEdge.o AirportNode.o Dijkstra.o $(CXXFLAGS)

ShortestPaths.o: ShortestPaths.cpp
	$(CXX)  -c -o ShortestPaths.o ShortestPaths.cpp $(CXXFLAGS)

ShortestPaths.cpp:
	@echo "Making ShortestPaths"

Dijkstra: AirportGraph.o AirportEdge.o AirportNode.o Dijkstra.o
	$(CXX) -o Dijkstra Dijkstra.o AirportGraph.o AirportEdge.o AirportNode.o $(CXXFLAGS)

Dijkstra.o: Dijkstra.cpp
	$(CXX)  -c -o Dijkstra.o Dijkstra.cpp $(CXXFLAGS)

Dijkstra.cpp:
	@echo "Making Dijkstra"




#tests

AirportGraph-test: AirportGraph-test.o AirportGraph.o AirportNode.o AirportEdge.o catchmain.o
	$(CXX) -o tests/AirportGraph-test tests/AirportGraph-test.o AirportGraph.o AirportNode.o AirportEdge.o catch/catchmain.o $(CXXFLAGS)

AirportGraph-test.o: AirportGraph-test.cpp
	$(CXX) -c -o tests/AirportGraph-test.o tests/AirportGraph-test.cpp $(CXXFLAGS)

AirportGraph-test.cpp:
	@echo "Making airport graph tests"

BFS-test:  BFS-test.o AirportGraph.o AirportNode.o AirportEdge.o catchmain.o BFS.o
	$(CXX) -o tests/BFS-test tests/BFS-test.o AirportGraph.o AirportNode.o AirportEdge.o catch/catchmain.o BFS.o $(CXXFLAGS)

BFS-test.o: BFS-test.cpp
	$(CXX) -c -o tests/BFS-test.o tests/BFS-test.cpp $(CXXFLAGS)

BFS-test.cpp:
	@echo "Making BFS-test..."

Dijkstra-test:  Dijkstra-test.o AirportGraph.o AirportNode.o AirportEdge.o catchmain.o Dijkstra.o
	$(CXX) -o tests/Dijkstra-test tests/Dijkstra-test.o AirportGraph.o AirportNode.o AirportEdge.o catch/catchmain.o Dijkstra.o $(CXXFLAGS)

Dijkstra-test.o: Dijkstra-test.cpp
	$(CXX) -c -o tests/Dijkstra-test.o tests/Dijkstra-test.cpp $(CXXFLAGS)

Dijkstra-test.cpp:
	@echo "Making Dijkstra-test..."

BetweennessCentrality-test:  BetweennessCentrality-test.o AirportGraph.o AirportNode.o AirportEdge.o catchmain.o BetweennessCentrality.o ShortestPaths.o
	$(CXX) -o tests/BetweennessCentrality-test tests/BetweennessCentrality-test.o AirportGraph.o AirportNode.o AirportEdge.o BetweennessCentrality.o ShortestPaths.o catch/catchmain.o $(CXXFLAGS)

BetweennessCentrality-test.o: BetweennessCentrality-test.cpp
	$(CXX) -c -o tests/BetweennessCentrality-test.o tests/BetweennessCentrality-test.cpp $(CXXFLAGS)

BetweennessCentrality-test.cpp:
	@echo "Making BetweennessCentrality-test..."

tests: AirportGraph-test.o BFS-test.o Dijkstra-test.o BetweennessCentrality-test.o AirportGraph.o AirportNode.o AirportEdge.o catchmain.o
	$(CXX) -c tests/BFS-test.o tests/Dijkstra-test.o tests/BetweennessCentrality-test.o tests/AirportGraph-test.o AirportGraph.o AirportNode.o AirportEdge.o catch/catchmain.o -o tests/tests

clean:
	@rm -f main main.o 
	@rm -f BFS BFS.o 
	@rm -f tests/BFS-test tests/BFS-test.o tests/Dijkstra-test tests/Dijkstra-test.o tests/BetweennessCentrality-test tests/BetweennessCentrality-test.o
	@rm -f AirportGraph AirportGraph.o AirportEdge AirportEdge.o AirportNode AirportNode.o
	@rm -f tests/AirportGraph-test tests/AirportGraph-test.o catch/catchmain.o catch/catchmain