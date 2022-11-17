#include <iostream>
#include <sstream>
#include <string>

#include "graph.h"
#include "poli.h"

using namespace std;

vector<vector<int>> getAdjacencyMatrix(int n){
    vector<vector<int>> matrix;

    for (int i = 0; i < n; i++){
        vector<int> row(n, 0);
        for (int j = 0; j < n; j++){
            int num = 0;
            cin >> num;
            row[j] = num;
        }
        matrix.push_back(row);
    }
    return matrix;
}

vector<int> stringToCoordinates(string numsString) {
    string formatedString = numsString.substr(1, numsString.size() -2);
    string coordinate;
    stringstream ss(formatedString);
    vector<int> coordinates;

    while(getline(ss, coordinate, ',')){
        coordinates.push_back(stoi(coordinate));
    }
    
    return coordinates;
}

vector<Point> getPointVectorFromInput(int nPoints){
    vector<Point> points;
    for (int i = 0; i < nPoints; i++) {
        string numsS;
        getline(cin >> std::ws, numsS);
        vector<int> coordinates = stringToCoordinates(numsS);

        points.push_back({coordinates[0], coordinates[1]});
    }
    return points;
} 

void optimalWireUp(Graph city, int startNode, int destNode){
    city.dijkstra(startNode, destNode);  
}

void shortestRoundTrip(Graph city, int startingNode){
    city.travellingSalesman(startingNode);
}

void maxInfoFlow(Graph flowGraph, int startingNode, int endNode){
    int maxInfo = flowGraph.maximunFlow(startingNode, endNode);

    cout << "Maximo flujo de informacion de nodo " << startingNode <<
    " a nodo "<< endNode <<" es de: "<< maxInfo << endl;
}





int main(){
    int n;
    cin >> n;

    // 1. Shortest Path 
    vector<vector<int>> graph = getAdjacencyMatrix(n);
    Graph routeGraph(graph);
    optimalWireUp(routeGraph, 0, 4);
    //0 7 6 5 4

/*
    // 2. Travelling Salesman
    cout << "La ruta a seguir es: "<< endl;
    shortestRoundTrip(routeGraph, 0);

    //3. MaximunFLow
    vector<vector<int>> flowMatrix = getAdjacencyMatrix(n);
    Graph flowGraph(flowMatrix);

    maxInfoFlow(flowGraph, 0, n-1);
    
    //4. Poligonos convexos
    vector<Point> points = getPointVectorFromInput(n);
    grahamScan(points, n);*/

    return 0;
}


