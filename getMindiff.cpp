#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int diff=arr[n-1]-arr[0];
        int mini,maxi;
        for(int i=1;i<n;i++){
            mini=min(arr[0]+k,arr[i]-k);
            maxi=max(arr[n-1]-k,arr[i-1]+k);
            if(mini<0){
                continue;
            }
            diff=min(diff,maxi-mini);
        }
        
        
        return diff;
    }



int main(){

    int arr[5]={1,2,3,4,5};
    int n=5;
    int z=getMinDiff(arr,n,2);
    cout<<z<<endl;
    return 0;
}