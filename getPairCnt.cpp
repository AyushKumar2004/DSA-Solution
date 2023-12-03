#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
        
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            m[arr[i]]--;
            
            if(m.find(k-arr[i])!=m.end()){
                ans+=m[k-arr[i]];
            }
        }
        return ans;
    }



int main(){

    int nums[3]={1,2,3};
    int n=3;
    int k=3;
    int x;
    x=getPairsCount(nums,n,k);

    cout<<x<<endl;

    return 0;
}