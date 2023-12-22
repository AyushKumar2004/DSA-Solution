#include<bits/stdc++.h>
using namespace std;

int dp[505][2005];
    int rec(int i,vector<int>&nums,int rem,int k){
        if(i==nums.size()){
            return 0;
        }
        int ans;
        if(rem>=0&&dp[i][rem]!=-1){
            return dp[i][rem];
        }
        else if(nums[i]>rem){
            ans=(rem+1)*(rem+1)+rec(i+1,nums,k-nums[i]-1,k);
        }
        else{
            int choice1=(rem+1)*(rem+1)+rec(i+1,nums,k-nums[i]-1,k);
            int choice2=rec(i+1,nums,rem-nums[i]-1,k);
            ans=min(choice1,choice2);
        }
        if(rem>=0){
            return dp[i][rem]=ans;
        }
        
        return ans;
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return rec(0,nums,k,k);
    }

int main(){
    
	vector<int> nums={3,2,2,5};
    int k=6;
    int x=solveWordWrap(nums,k);

    cout<<x<<endl;

    return 0;
}