#include <iostream>
using namespace std;
//Graph is a non-linear data structure consisting of nodes(vertices) and edges
//Types of Graphs:
//1. Directed and Undirected Graphs
//In a directed graph, edges have a direction, meaning they go from one vertex to another.
//In an undirected graph, edges do not have a direction, meaning the connection between vertices is bidirectional.
//Cycle in a graph: A cycle is a path of edges and vertices wherein a vertex is reachable from itself.
//Note: A binary tree is a special case of a directed graph with no cycles.
//2. Cyclic and Acyclic Graphs
//A cyclic graph contains at least one cycle, while an acyclic graph does not contain any cycles.
//Path in a graph: A path contains a lot of vertices and each of them are reachable from one another.
//Degree of a vertex: The degree of a vertex is the number of edges connected to it.
//In a graph, total degree = 2 * number of edges
//In a directed graph, we have in-degree (number of incoming edges) and out-degree (number of outgoing edges).
//3. Weighted and Unweighted Graphs
//In unweighted graphs, all edges are considered equal.
//In weighted graphs, each edge has an associated weight or cost known as edge weight.
//Graph Representation:
//1. Adjacency Matrix: A 2D array size of V x V where V is the number of vertices in a graph. 
//If there is an edge between vertex i and vertex j, then matrix[i][j] = 1, otherwise 0.
void AdjacencyMatrix(){
    int V=4;
    int graph[4][4]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
} // TC=O(v^2) SC=O(v^2)
//2. Adjacency List: An array of lists is used. The size of the array is equal to the number of vertices. 
//Each element of the array contains a list(vector) of vertices that are adjacent to the vertex.
void AdjacencyList(){
    int V=4;
    vector<int> graph[V];
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(0);
    graph[3].push_back(2);
    for(int i=0;i<V;i++){
        cout<<"Vertex "<<i<<": ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
} // TC=O(v+e) SC=O(2e)
//If its a directed graph, SC=O(e)
void AdjacencyList2(){
    int V=4;
    vector<int> graph[V];
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(2);
    graph[2].push_back(3);
    for(int i=0;i<V;i++){
        cout<<"Vertex "<<i<<": ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
} // TC=O(v+e) SC=O(e)
//If it is a weighted graph, we can use pair<int,int> to store the vertex and weight.
void AdjacencyListWeighted(){
    int V=4;
    vector<pair<int,int>> graph[V];
    graph[0].push_back({1,10});
    graph[0].push_back({3,15});
    graph[1].push_back({2,12});
    graph[2].push_back({3,5});
    for(int i=0;i<V;i++){
        cout<<"Vertex "<<i<<": ";
        for(int j=0;j<graph[i].size();j++){
            cout<<"(to: "<<graph[i][j].first<<", weight: "<<graph[i][j].second<<") ";
        }
        cout<<endl;
    }
} // TC=O(v+e) SC=O(e)
//Connected Components: A connected component is a subgraph in which any two vertices are connected to each other by paths, 
//and which is connected to no additional vertices in the supergraph.
//A graph is said to be connected if there is a path between every pair of vertices.
//If there is at least one pair of vertices without a path between them, the graph is said to be disconnected.
void ConnectedComponents(){
    int V=4;
    int visited[V];
    for(int i=0;i<V;i++){
        if(!visited[i]){
            cout<<"Connected component: ";
            //DFS(i, visited);
            cout<<endl;
        }
    }
} // TC=O(v+e) SC=O(v)
int main(){
    AdjacencyMatrix();
    AdjacencyList();
    AdjacencyList2();
    AdjacencyListWeighted();
    return 0;
}