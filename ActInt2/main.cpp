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

void optimalWireUp(Graph city, int startingNode){
    city.dijkstra(startingNode);
}

int main(){
    int n;
    cin >> n;

    // 1. Shortest Path 
    vector<vector<int>> graph = getAdjacencyMatrix(n);
    Graph routeGraph(graph);
    optimalWireUp(routeGraph, 0);

    // 2. Travelling Salesman
    routeGraph.travellingSalesman(0);

    //3. MaximunFLow
    vector<vector<int>> flowMatrix = getAdjacencyMatrix(n);
    Graph flowGraph(flowMatrix);
    cout << flowGraph.maximunFlow(0, n-1)<<endl;
    
    //4. Poligonos convexos
    vector<Point> points = getPointVectorFromInput(n);
    grahamScan(points, n);

    return 0;
}


