#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int n,int s,int mid,int e){
    int start2=mid+1;
    if(arr[mid]<=arr[start2]){
        return;
    }
    else{
        while(s<=mid && start2<=e){
            if(arr[s]<=arr[start2]){
                s++;
            }
            else{
                int val=arr[start2];
                int ind=start2;
                while(ind!=s){
                    arr[ind]=arr[ind-1];
                    ind--;
                }
                arr[s]=val;
                s++;
                start2++;
                mid++;
            }
        } 
    }
}

void mergeSort(int arr [],int n,int s,int e){
    if(s<e){
    int mid=s+(e-s)/2;
    mergeSort(arr,n,s,mid);
    mergeSort(arr,n,mid+1,e);
    merge(arr,n,s,mid,e);
    }
}

int main(){

	int arr[5]={2,4,1,3,5};
    int N=5;
    cout<<"this is in pace mergeSort:"<<endl;
    mergeSort(arr,N,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    
	return 0;
}