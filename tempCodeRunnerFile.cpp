int robSpaceOpt(vector<int>& nums){
    int n=nums.size();
    if(n==0){
        return 0;
    }
    int a=nums[0];
    int b=max(nums[0],nums[1]);
    int c;
    for(int i=2;i<n;i++){
        c=max(nums[i]+a,b);
        a=b;
        b=c;
    }
    return c;
}