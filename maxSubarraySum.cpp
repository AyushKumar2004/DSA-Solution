#include<bits/stdc++.h>
using namespace std;

int  maxSubarraysSum(int arr[],int n){
    int max=INT_MIN;
    int max2=0;
    for(int i=0;i<n;i++){
        max2=max2+arr[i];
        if(max<max2){
            max=max2;
        }
        if(max2<0){
            max2=0;
        }
    }
    return max;
}

int main(){

    int arr[5]={1,2,3,4,5};
    int n=5;
    int z=maxSubarraysSum(arr,n);
    cout<<z<<endl;

    return 0;
}