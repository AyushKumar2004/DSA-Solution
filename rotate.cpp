#include<bits/stdc++.h>
using namespace std;

void rotate(int arr2[],int n){
    int* temp=new int[n];
    for(int i=0;i<n;i++){   
        temp[(i+1)%n]=arr2[i];
    }

    for(int i=0;i<n;i++){
        arr2[i]=temp[i];
    }
    delete []temp;
    
}

int main(){

    int arr2[5]={1,2,3,4,5};
    rotate(arr2,n);
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}