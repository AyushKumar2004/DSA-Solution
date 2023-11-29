#include<bits/stdc++.h>
using namespace std;

int minJump(int arr[],int n) {
        int pos=0;
        int dest=0;
        int jump=0;

        for(int i=0;i<n-1;i++){

            if(i==pos&&arr[pos]==0&&pos==dest){
                return -1;
            }

            dest=max(dest,arr[i]+i);
            if(pos==i){
                pos=dest;
                jump++;
            }
        }

        return jump;
    }



int main(){

    int arr[5]={1,2,3,4,5};
    int n=5;
    int z=minJump(arr,n);
    cout<<z<<endl;
    return 0;
}