#include<bits/stdc++.h>
using namespace std;

void rotateRight(int arr[],int n,int outOfPlace,int curr){
    int temp=arr[curr];
    for(int i=curr;i>outOfPlace;i--){
        arr[i]=arr[i-1];
        
    }
    arr[outOfPlace]=temp;
}

void rearrange(int arr[],int n){
    int outOfPlace=-1;
    for(int i=0;i<n;i++){
        if(outOfPlace>=0){
            if((arr[i]>=0&&arr[outOfPlace]<0)||(arr[i]<0&&arr[outOfPlace]>=0)){
                rotateRight(arr,n,outOfPlace,i);
                if(i-outOfPlace>=2){
                    outOfPlace=outOfPlace+2;
                }
                else{
                    outOfPlace=-1;
                }
            }
        }
        if(outOfPlace==-1){
            if(((arr[i]>=0)&& (i%2==0))||((arr[i]<0)&& (i%2!=0))){
                outOfPlace=i;
            }
        }
    }
}



int main(){

    int arr[10]={-5,-1,5,2,4,7,1,8,0,-8};
    int n=10;
    rearrange(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}