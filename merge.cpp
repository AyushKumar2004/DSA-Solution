#include<bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
             int i=n-1;
             int j=0;
             while(i>=0&&j<m){
                 if(arr1[i]>arr2[j]){
                     swap(arr1[i],arr2[j]);
                 }
                 i--;
                 j++;
             }
             sort(arr1,arr1+n);
             sort(arr2,arr2+m);
        } 



int main(){

    long long arr1[5]={1,2,3,4,5};
    int n=5;
    long long arr2[6]={3,4,5,6,7,8};
    int m=6;
    merge(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }

    for(int j=0;j<m;j++){
        cout<<arr2[j]<<" ";
    }
    return 0;
}