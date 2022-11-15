#include <iostream>
#include <sstream>
#include <string>

#include "graph.h"
#include "poli.h"

using namespace std;

vector<vector<int>> getMatrix(int n){
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


int main(){
    int n;
    cin >> n;

    cout<<"\n";
    vector<vector<int>> graph = getMatrix(n);
    Graph routeGraph(graph);
    routeGraph.dijkstra(0);

    //3. MaximunFLow
    vector<vector<int>> flowMatrix = getMatrix(n);
    Graph flowGraph(flowMatrix);
    cout << flowGraph.maximunFlow(0, n-1)<<endl;
    

    /*
    //4. Poligonos convexos
    vector<Point> points;
    vector<int> aux;
    for (int i = 0; i < n; i++) {
        string numsS;
        getline(cin >> std::ws, numsS);
        
        vector<int> aux = createNumsVector(numsS);

        points.push_back({aux[0], aux[1]});
        aux.clear();
    }

    grahamScan(points, n);
    */
    return 0;
}


