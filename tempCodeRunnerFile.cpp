void UpperBound(int n,int arr[],int key){
    int low=0,mid,high=n-1;
    int ans=n;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<key){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    if(ans==n){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<"Upper bound of "<<key<<" is at index: "<<ans<<endl;
    }
}