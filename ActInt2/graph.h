#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  
#include <limits.h>

#define INF 10000

using namespace std;
typedef pair<int, int> pd;

class Graph{
    private:
        vector<vector<int>> matrizAdj;
        int vertices;

        //struct utilizado para definir el min priotiy queue
        struct myComp {
            constexpr bool operator()(
                pair<int, int> const& a,
                pair<int, int> const& b)
                const noexcept{
                return a.second > b.second;
            }
        };
        
        // imprime la solución del algoritmo de Dijkstra
        // Comlejidad temporal: O(V)
        void printSolution(vector<int> results, int root){
            for (int i = 0; i < this->vertices; i++){
                cout << "node "<< root <<" to node "<<i<<": ";
                if(results[i] == INF){
                    cout<<"INF"<< endl;
                }else{
                    cout<<results[i]<< endl;
                }
            }
        }

        bool bfs(vector<vector<int>> &residualGraph, int start, int end, vector<int> &parent){
            vector<bool> visited(this->vertices, false);
            queue<int> q;
            q.push(start);
            visited[start] = true;
            parent[start] = -1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int i=0; i < this->vertices; i++){
                    if(!visited[i] && residualGraph[node][i] > 0){
                        if(i == end){
                            parent[end] = node;
                            return true;
                        }
                        q.push(i); 
                        parent[i] = node;
                        visited[i] = true;
                    }
                }
            }

            return false;
        }
        
        
    public:
        Graph(vector<vector<int>> matrizAdj){
            this->matrizAdj = matrizAdj;
            this->vertices = matrizAdj.size();
        }

        // Función que calcula la ruta más corta entre el nodo raiz y los demás nodos
        // Complejidad temporal: O(E log V) E siendo las aristas y V los vertices
        // Complejidad espacial: O(V)
        void dijkstra(int root){
            vector<int> results(this->matrizAdj.size(),INF);
            vector<bool> visited(this->matrizAdj.size(),false);
            results[root] = 0;
            priority_queue<pd,vector<pd>,myComp> pq;
            
            pq.push(make_pair(root,0));

            while(pq.size() != 0){
                
                int index = pq.top().first;
                int minVal = pq.top().second;
                pq.pop();
                visited[index] = true;

                for(int i = 0; i < this->vertices; i++){
                    if(this->matrizAdj[index][i] != -1){
                        if(visited[i] == false && this->matrizAdj[index][i] != INF){
                            int newDist = results[index] + this->matrizAdj[index][i]; 

                            if(newDist < results[i]){
                                results[i] = newDist;
                                pq.push(make_pair(i,newDist));
                            } 
                        }
                    }
                }
            }

            printSolution(results,root);

        }

        //O(n!)
        void travellingSalesman(int root){
            vector<int> vertex;
            for(int i = 0; i < this->vertices; i++){
                if(i != root)
                vertex.push_back(i);
            }

            int min_path = INF;
            vector<int> route(this->vertices,0);
            route[0] = root;
            
            do{
                
                int current_weight = 0;
                int k = root;
                for(int i = 0; i < vertex.size(); i++){
                    current_weight += this->matrizAdj[k][vertex[i]];
                    k = vertex[i];
                }

                current_weight += this->matrizAdj[k][root];

                min_path = min(min_path, current_weight);
                if(min_path == current_weight){
                    
                    for(int i = 1; i < this->vertices; i++){
                        route[i] = vertex[i-1];
                    }
                }

            }while(next_permutation(vertex.begin(),vertex.end()));

            for(int i = 0; i < this->vertices; i++){
                cout<<route[i]<<"->";
            }
            cout<<"0"<<endl;
        }

        int maximunFlow(int start, int end){
            int graphSize = this->vertices;
            vector<vector<int>> residualGraph(graphSize, vector<int>(graphSize,0));
            
            for(int i=0; i < graphSize; i++){
              residualGraph[i] = this->matrizAdj[i];
            }
            vector<int> parent(graphSize, 0);
 
            int maxFlow = 0;

            while(bfs(residualGraph, start, end, parent)){
                int currentFlow = INT_MAX;
                int node;
                for (int v = end; v != start; v = parent[v]) {
                    node = parent[v];
                    currentFlow = min(currentFlow, residualGraph[node][v]);
                }
                for (int v = end; v != start; v = parent[v]) {
                    node = parent[v];
                    residualGraph[node][v] -= currentFlow;
                    residualGraph[v][node] += currentFlow;
                }
                
                maxFlow += currentFlow;
            }

            return maxFlow;
        }
};
