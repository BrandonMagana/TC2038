/*
    Autores:
    - Brandon Josué Magaña Mendoza a01640162
    - Santiago González de Cosío Romero A01640329

    El presenet código contiene la implementación del algoritmo graph coloring haciendo uso de la estrategía de backtracking,
    dicho algoritmo permite etiquetar a los nodos de un grafo con  "colores" de manera tal que ningún vértive adyacente 
    comparta la misma etiqueta.
    
    m = number of colors
    v = number of vertices in the graph

    Time Complexity: O(m^v)
*/

#include <iostream>
#include <vector>

using namespace std;
#define COLORS 4 // Maximun nummber of colors on a bidimensional plane


bool isColorAssignable(vector<vector<bool>> graph, vector<int> &color){
    int n = graph.size();
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(graph[i][j] && color[j] == color[i])
                return false;
    return true;
}

bool graphColoring(vector<vector<bool>> graph, int nColors, int index, vector<int> &color){
    if(index == graph.size())
        return isColorAssignable(graph, color);
    
    for(int j = 0; j < nColors; j++){
        color[index] = j;
        
        if(graphColoring(graph, nColors, index + 1, color))
            return true;

        color[index] = -1;
    }
    return false;
}

void printColors(vector<int> color){
	for (int i = 0; i < color.size(); i++)
		cout << "Node: " << i << ", Assigned Color: " << color[i] << endl;
}


int main(){
    int nNodes = 0;
    cin >> nNodes;

    vector<vector<bool>> graph(nNodes, vector<bool>(nNodes, 0));
    vector<int> color(nNodes, -1);

    int nodeVal = 0;
    for(int i = 0; i < nNodes; i++){
        for(int j = 0; j < nNodes; j++){
            cin >> nodeVal;
            graph[i][j] = nodeVal;
        }
    }

    if (!graphColoring(graph, COLORS, 0, color))
		cout << "No es posible asignar colores a los nodos" << endl;
    else
        printColors(color);

    return 0;
}