#include<bits/stdc++.h>
using namespace std;

long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    long long count=0;
	    for(int i=0;i<n-2;i++){
	        int start=i+1;
	        int end=n-1;
	        while(start<end){
	            long long result=arr[start]+arr[end]+arr[i];
	            if(result<sum){
	                count+=end-start;
	                start++;
	            } 
	            else end--;
	        }
	    }
	    return count;
	}

int main(){
    
	long long arr[5]={0,0,2,1,1};
    int n=5;
    cout<<countTriplets(arr,n,3)<<endl;

    return 0;
}