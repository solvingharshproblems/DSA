vector<vector<int>> dist(n,vector<int>(n,1e9));
    for(auto edge:edges){
        dist[edge[0]][edge[1]]=edge[2];
        dist[edge[1]][edge[0]]=edge[2]; 
    }
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){   
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }   
        }
    }
    int minCount=n;
    int resultCity=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold){
                count++;
            }
        }
        if(count<=minCount){
            minCount=count; 
            resultCity=i;
        }
    }
    return resultCity;