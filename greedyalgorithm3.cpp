#include <iostream>
using namespace std;
//Problem 1: Shortest Job First (SJF) Scheduling
//Scheduling policy that selects the waiting process with the smallest execution time to execute next
//For Optimal Approach, we will sort the array and calculate the average waiting time
void SJFScheduling(vector<int> arr){
    int n=arr.size();
    int avg=0,sum=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        avg+=sum;
        sum+=arr[i];
    }
    cout<<"Average waiting time: "<<avg/n<<endl;
} // TC=O(nlogn) SC=O(1) Here, we tamper the input array by sorting it which is not a good practice
//Problem 2: Job Sequencing Problem
//Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline
//We need to find the maximum profit and the number of jobs done
//For Optimal Approach, we will delay the jobs to end days and use a boolean array to keep track of free days
struct Job{
    int id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b){
    return a.profit>b.profit;
}
void JobSequencing(vector<Job> arr){
    int n=arr.size();
    sort(arr.begin(),arr.end(),compare);
    int totalProfit=0,countJobs=0;
    int maxDeadline=-1;
    for(int i=0;i<n;i++){
        maxDeadline=max(maxDeadline,arr[i].deadline);
    }
    vector<int> hash(maxDeadline+1,-1);
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline;j>0;j--){
            if(hash[j]==-1){
                hash[j]=i;
                totalProfit+=arr[i].profit;
                countJobs++;
                break;
            }
        }
    }
    cout<<"Total profit: "<<totalProfit<<endl;
    cout<<"Number of jobs done: "<<countJobs<<endl;
} // TC=O(n^2+nlogn) SC=O(n)
// Note: We can optimize the time complexity to O(nlogn) using Disjoint Set Union (DSU) but it is a topic of Graphs so we will study it later
//Problem 3: N meetings in one room 
//Given start and end times of N meetings in one room, we need to find the maximum number of meetings that can be accommodated in the room
//For Optimal Approach, we will sort the meetings by their end times and select the meetings which start after the end of the last selected meeting
struct Meeting{
    int start;
    int end;
    int pos;
};
bool Compare(Meeting a, Meeting b){
    if(a.end==b.end){
        return a.pos<b.pos;
    }
    return a.end<b.end;
}
void NMeetingsInOneRoom(vector<Meeting> arr){
    int n=arr.size();
    sort(arr.begin(),arr.end(),Compare);
    vector<int> ans;
    ans.push_back(arr[0].pos);
    int limit=arr[0].end;
    for(int i=1;i<n;i++){
        if(arr[i].start>limit){
            ans.push_back(arr[i].pos);
            limit=arr[i].end;
        }
    }
    cout<<"Maximum number of meetings: "<<ans.size()<<endl;
    cout<<"Meetings are: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
} // TC=O(nlogn+2n) SC=O(2n)
int main(){
    /*
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SJFScheduling(arr);
    int m;
    cout<<"Enter the number of jobs: ";
    cin>>m;
    vector<Job> arr(m);
    cout<<"Enter the job id, deadline and profit: ";
    for(int i=0;i<m;i++){
        cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
    }
    JobSequencing(arr);
    */
    int k;
    cout<<"Enter the number of meetings: ";
    cin>>k;
    vector<Meeting> arr(k);
    cout<<"Enter the start and end times of the meetings: ";
    for(int i=0;i<k;i++){
        cin>>arr[i].start>>arr[i].end;
        arr[i].pos=i+1;
    }
    NMeetingsInOneRoom(arr);
    return 0;
}