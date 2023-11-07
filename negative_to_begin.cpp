#include<bits/stdc++.h>
using namespace std;

void arrangeNega(int arr[],int N){
    int i=0;
    int j=N-1;

    while(i<j){
        if(arr[i]>0 && arr[j]<0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

        if(arr[i]<0 && arr[j]>0){
            i++;
            j--;
        }

        if(arr[i]<0 && arr[j]<0){
            i++;
        }

        if(arr[i]>0 && arr[j]>0){
            j--;
        }
    }

}

int main(){

    int arr[9]={-1, 2, 3, 4, 5, 6, 7, -8, -9 };
    int n=9;

    arrangeNega(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    

    return 0;
}