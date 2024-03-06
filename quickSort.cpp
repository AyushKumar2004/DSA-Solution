#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
    {
       int pivot=arr[low];
       int i=low;
       int j=high;
       while(i<j){
           while(arr[i]<=pivot && i<=high-1){
               i++;
           }
           while(arr[j]>pivot && j>=low+1){
               j--;
           }
           if(i<j){
               swap(arr[i],arr[j]);
           }
       }
       swap(arr[j],arr[low]);
       return j;
    }


    void quickSort(int arr[], int low, int high)
    {
       if(low<high){
           int par=partition(arr,low,high);
           quickSort(arr,low,par-1);
           quickSort(arr,par+1,high);
       }
    }

int main(){

	int arr[5]={2,4,1,3,5};
    int N=5;
    cout<<"this is quickSort:"<<endl;
    quickSort(arr,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    
	return 0;
}