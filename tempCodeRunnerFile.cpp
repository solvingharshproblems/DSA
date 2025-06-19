void MovingZeros(int n,int arr[]){
    int count=0,i=0;
    while(i<n-1 && arr[i]==0){
        swap(arr[i],arr[i+1]);
        i++;
    }
    
}