#include <bits/stdc++.h>
using namespace std;

bool solveMem(int index,int N,int arr[],vector<vector<int>>& dp,int target){
        if(index>=N){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        int incl=solveMem(index+1,N,arr,dp,target-arr[index]);
        int excl=solveMem(index+1,N,arr,dp,target-0);
        
        return dp[index][target]=incl||excl;
}

int equalPartition(int N, int arr[]){   
        int totalSum=0;
        int target=0;
        for(int i=0;i<N;i++){
            totalSum+=arr[i];
        }
        if(totalSum&1){
            return 0;
        }
        if(totalSum%2==0){
            target=totalSum/2;
        }
        int index=0;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return solveMem(index,N,arr,dp,target);
}

int main(){

    int arr[4]={1,5,11,5};
    int N=4;
    cout<<equalPartition(N,arr)<<endl;

	return 0;
}