#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])<=k&&arr[i]==x){
            return i;
        }
    }
    if(arr[0]==x)   return 0;
    if(arr[n-1]==x) return n-1;
    
    return -1;
}

int main(){
    
	int arr[5]={4,5,6,7,6};
    int n=5;
    int x=6;
    int k=1;
    cout<<search(arr,n,x,k)<<endl;

    return 0;
}