#include<bits/stdc++.h>
using namespace std;

int  doUnion(int a[],int b[],int n,int m){
    
    unordered_set<int> s;

    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }

    for(int j=0;j<m;j++){
        s.insert(b[j]);
    }

    return s.size();
}

int main(){

    int arr[6]={85, 25, 1, 32, 54, 6};
    int n=6;

    int brr[2]={85,2};
    int m=2;

    cout<<doUnion(arr,brr,n,m);
    return 0;
}