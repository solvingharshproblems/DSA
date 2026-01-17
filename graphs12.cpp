#include <iostream>
using namespace std;
//Problem 1: Find Eventual Safe States (Using BFS - Kahn's Algorithm)
//Eventual Safe States are those nodes from which we cannot reach any cycle.
//For Optimal Approach, we can use Kahn's Algorithm for Topological Sort in reverse graph
void findSafeStatesBFS(int V,vector<vector<int>>& adj){
    vector<vector<int>> reverseAdj(V);
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto neighbor:adj[i]){
            reverseAdj[neighbor].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> safeStates;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        safeStates.push_back(node);
        for(auto neighbor:reverseAdj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    sort(safeStates.begin(),safeStates.end());
    for(auto state:safeStates){
        cout<<state<<" ";
    }
    cout<<endl;
} // TC=O(V+E) SC=O(V) for reverseAdj + O(V) for indegree + O(V) for queue + O(V) for safeStates
int main(){
    int V=7;
    vector<vector<int>> adj(V);;
    adj[0]={1,2};
    adj[1]={2,3};
    adj[2]={5};
    adj[3]={0};
    adj[4]={5};
    adj[5]={};
    adj[6]={4};
    findSafeStatesBFS(V,adj);
    return 0;
}