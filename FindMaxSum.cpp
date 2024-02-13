#include<bits/stdc++.h>
using namespace std;

int dp[100001];
    
    int helper(int arr[],int n,int index){
        if(index>=n){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        
        return dp[index]=max(arr[index]+helper(arr,n,index+2),helper(arr,n,index+1));
        
    }
    
    
    int FindMaxSum(int arr[], int n)
    {   
        memset(dp,-1,sizeof(dp));
        return helper(arr,n,0);
    }

int main(){
    
	int arr[5]={0,0,2,1,1};
    int n=5;
    cout<<FindMaxSum(arr,n)<<endl;

    return 0;
}