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
} // TC = O(N * K log K) SC=O(N * K) where N is the number of accounts and K is the maximum number of emails in an account.
//Problem 2: Number of Islands II 
//You are given a 2D grid of size m x n initially filled with water. The grid represents a map where 0's represent water and 1's represent land. Initially, all the cells of grid are water cells (i.e., all the cells are 0's).
//We are given a list of positions where land should be added to the grid. After each addition of land, we need to count the number of islands present in the grid. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//For Optimal Approach, we will use Disjoint Set (Union-Find) data structure to dynamically manage the connected components as we add land to the grid.
vector<int> numIslands2(int m,int n,vector<pair<int,int>>& positions){
    DisjointSet ds(m*n);
    vector<vector<int>> grid(m,vector<int>(n,0));
    vector<int> ans;
    int count=0;
    vector<int> delRow={-1,0,1,0};
    vector<int> delCol={0,1,0,-1};  
    for(auto pos:positions){
        int row=pos.first;
        int col=pos.second;
        if(grid[row][col]==1){
            ans.push_back(count);
            continue;
        }
        grid[row][col]=1;
        count++;
        int node=row*n+col;
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]==1){
                int adjNode=nRow*n+nCol;
                if(ds.findUPar(node)!=ds.findUPar(adjNode)){
                    ds.unionBySize(node,adjNode);
                    count--;
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
} // TC=O(K * alpha(N)) SC=O(M*N) where K is the number of positions and M*N is the total number of cells.
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
    int m=3,n=3;
    vector<pair<int,int>> positions={{0,0},{0,1},{1,2},{2,1},{1,1}};
    vector<int> islandCounts=numIslands2(m,n,positions);
    for(auto count:islandCounts){
        cout<<count<<" ";
    }
    cout<<endl;
    return 0;
}