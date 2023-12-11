#include<bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n){
        int left=0;
        int right=n-1;
        long long leftMax=0;
        long long rightMax=0;
        long long res=0;
        while(left<right){
            if(arr[left]<=arr[right]){
                if(arr[left]>=leftMax){
                    leftMax=arr[left];
                }
                else{
                    res+=leftMax-arr[left];
                }
                left++;
            }
            else{
                if(arr[right]>=rightMax){
                    rightMax=arr[right];
                }
                else{
                    res+=rightMax-arr[right];
                }
                right--;
            }
        }
        
        return res;
    }


int main(){

    int arr[6]={3,0,0,2,0,4};
	int n=6;
    long long z=trappingWater(arr,n);
    cout<<z<<endl;
	

    return 0;
}