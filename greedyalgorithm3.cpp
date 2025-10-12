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
    */
    int m;
    cout<<"Enter the number of jobs: ";
    cin>>m;
    vector<Job> arr(m);
    cout<<"Enter the job id, deadline and profit: ";
    for(int i=0;i<m;i++){
        cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
    }
    JobSequencing(arr);
    return 0;
}