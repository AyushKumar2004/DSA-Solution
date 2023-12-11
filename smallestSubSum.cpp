#include<bits/stdc++.h>
using namespace std;

int smallestSubWithSum(int arr[], int n, int x)
    {
        int start=0;
        int end=0;
        int minLen=n+1;
        int currSum=0;
        
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        
        if(totalSum<x){
            return 0;    
        }
        
        while(end<n){
            while(currSum<=x&&end<n){
                currSum+=arr[end];
                end++;
            }
            
            while(currSum>x&&start<n){
                if(end-start<minLen){
                    minLen=end-start;
                }
                
                currSum-=arr[start];
                start++;
            }
        }
        
        
        
        return minLen;
    }


int main(){

    int arr[6]={1, 4, 45, 6, 0, 19};
	int n=6;
    int x=51;
    int z=smallestSubWithSum(arr,n,x);
    cout<<z<<endl;
	

    return 0;
}