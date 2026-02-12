int DFS(vector<int>& weights,vector<int>& values,int W,int n,int i){
    if(i>=n || W<=0){
        return 0;
    }
    int exclude=DFS(weights,values,W,n,i+1);
    int include=0;
    if(weights[i]<=W){
        include=values[i]+DFS(weights,values,W-weights[i],n,i); 
    }
    return max(include,exclude);
} 
int knapsackBruteForce(vector<int>& weights,vector<int>& values,int W){
    int n=weights.size();
    return DFS(weights,values,W,n,0);
} // TC=O(2^W) SC=O(W)