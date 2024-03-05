#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int n,int s,int mid,int e){
    int mx=max(arr[mid],arr[e])+1;
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e && k<=e){
        int e1=arr[i]%mx;
        int e2=arr[j]%mx;
        if(e1<e2){
            arr[k]+=e1*mx;
            k++;
            i++;
        }
        else{
            arr[k]+=e2*mx;
            k++;
            j++;
        }
    }
    while(i<=mid && k<=e){
        int el=arr[i]%mx;
        arr[k]+=el*mx;
        k++;
        i++;
    }
    while(j<=e && k<=e){
        int el=arr[j]%mx;
        arr[k]+=el*mx;
        k++;
        j++;
    }

    for(int i=s;i<=e;i++){
        arr[i]/=mx;
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
    cout<<"this is mergeSort2:"<<endl;
    mergeSort(arr,N,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    
	return 0;
}