#include <iostream>
using namespace std;
//Problem 1: Detect Cycle in Directed Graph (Using BFS - Kahn's Algorithm)
//A cycle exists in a directed graph if we cannot include all vertices in the topological sort
bool DetectCycleDAG(int V,vector<vector<int>>& adj){
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto neighbor:adj[i]){
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(auto neighbor:adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    if(count==V){
        return false; // No cycle
    }
    else{
        return true; // Cycle exists
    }
} // TC=O(V+E) SC=O(V) for indegree + O(V) for queue
//Problem 2: Course Schedule I and II
//Given the number of courses and a list of prerequisite pairs, determine if it's possible to finish all courses (Course Schedule I) and provide an order to finish them (Course Schedule II).
//For Optimal Approach, we can use Kahn's Algorithm for Topological Sort to solve both problems.
bool isPossible(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for(auto pre:prerequisites){
        adj[pre[1]].push_back(pre[0]);
    }
    return !DetectCycleDAG(numCourses,adj);
} // TC=O(V+E) SC=O(V) for indegree + O(V) for queue + O(V+E) for adjacency list
int main(){
    int V=4;
    vector<vector<int>> adj(V);;
    adj[0]={1};
    adj[1]={2};
    adj[2]={0};
    adj[3]={2};
    if(DetectCycleDAG(V,adj)){
        cout<<"Graph contains a cycle."<<endl;
    }
    else{
        cout<<"Graph does not contain a cycle."<<endl;
    }
    vector<vector<int>> prerequisites={{1,0},{2,1},{3,2}};
    if(isPossible(4,prerequisites)){
        cout<<"All courses can be finished."<<endl;
    }
    else{
        cout<<"All courses cannot be finished."<<endl;
    }
    return 0;
}