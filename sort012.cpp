#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[],int N){
   int k=0;
   int count=0;
   int count1=0;
   int count2=0;

   for(int i=0;i<N;i++){
        if(arr[i]==0){
            count++;
        }

        if(arr[i]==1){
            count1++;
        }

        if(arr[i]==2){
            count2++;
        }
   }

   while(count>0){
        arr[k]=0;
        k++;
        count--;
   }

   while(count1>0){
        arr[k]=1;
        k++;
        count1--;
   }

   while(count2>0){
        arr[k]=2;
        k++;
        count2--;
   }
}

int main(){

    int arr[6]={1,2,2,1,0,0};
    int n=6;

    sort012(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    

    return 0;
}