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
//Problem 2: Alien Dictionary
//Given a sorted dictionary of an alien language, find the order of characters in the language.
//For Optimal Approach, we will use Kahn's Algorithm for Topological Sort to determine the order of characters.
string findOrder(int N, int K, vector<string>& dict) {
    vector<vector<int>> adj(K);
    for(int i=0;i<N-1;i++){
        string word1=dict[i];
        string word2=dict[i+1];
        int minLength=min(word1.length(),word2.length());
        for(int j=0;j<minLength;j++){
            if(word1[j]!=word2[j]){
                adj[word1[j]-'a'].push_back(word2[j]-'a');
                break;
            }
        }
    }
    vector<int> indegree(K,0);
    for(int i=0;i<K;i++){
        for(auto neighbor:adj[i]){
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    for(int i=0;i<K;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    string order="";
    while(!q.empty()){
        int node=q.front();
        q.pop();
        order+=char(node+'a');
        for(auto neighbor:adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    return order;
} // TC=O(N*L + K + E) SC=O(K) for indegree + O(K) for queue + O(K) for adjacency list
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
    vector<string> dict={"baa","abcd","abca","cab","cad"};
    int N=dict.size();
    int K=4; 
    string order=findOrder(N,K,dict);
    cout<<"The order of characters in the alien language is: "<<order<<endl;
    return 0;
}