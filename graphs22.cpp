#include <iostream>
using namespace std;
//Problem 1: Accounts Merge
//Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//Now, two accounts definitely belong to the same person if there is some common email to both accounts. Merge the accounts and return the result.
//For Optimal Approach, we will use Disjoint Set (Union-Find) data structure to group emails belonging to the same person.
class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n=accounts.size();
    DisjointSet ds(n);
    unordered_map<string,int> emailToNode;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string email=accounts[i][j];
            if(emailToNode.find(email)==emailToNode.end()){
                emailToNode[email]=i;
            }
            else{
                ds.unionBySize(i,emailToNode[email]);
            }
        }
    }
    vector<vector<string>> mergedEmails(n);
    for(auto it:emailToNode){
        string email=it.first;
        int node=it.second;
        int parentNode=ds.findUPar(node);
        mergedEmails[parentNode].push_back(email);  
    }
    vector<vector<string>> result;
    for(int i=0;i<n;i++){
        if(mergedEmails[i].size()==0){
            continue;
        }
        sort(mergedEmails[i].begin(),mergedEmails[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto email:mergedEmails[i]){
            temp.push_back(email);  
        }
        result.push_back(temp);
    }
    return result;
}
int main(){
    vector<vector<string>> accounts={
        {"John","J1@gmail.com","J2@gmail.com"},
        {"John","J4@gmail.com"},
        {"John","J1@gmail.com","J5@gmail.com"},
        {"Mary","M1@gmail.com"}
    };
    vector<vector<string>> mergedAccounts=accountsMerge(accounts);
    for(auto account:mergedAccounts){
        for(auto email:account){
            cout<<email<<" ";
        }
        cout<<endl;
    }
    return 0;
}