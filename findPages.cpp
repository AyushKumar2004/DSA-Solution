#include <bits/stdc++.h>
using namespace std;

int countStd(int A[], int N, int M,int mid){
        int ans=0;
        int countStd=1;
        for(int i=0;i<N;i++){
            if(A[i]+ans<=mid){
                ans+=A[i];
            }
            else{
                countStd++;
                ans=A[i];
            }
        }
        return countStd;
    }
    
    
    int findPages(int A[], int N, int M) 
    {   
        if(M>N) return -1;
        int low=0;
        int high=0;
        for(int i=0;i<N;i++){
            low=max(low,A[i]);
            high+=A[i];
        }
        int mid=low+(high-low)/2;
        while(low<=high){
            int stdCount=countStd(A,N,M,mid);
            if(stdCount>M){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return low;
    }

int main(){

	int A[5]={34,24,56,78,100};
    int N=5;
    int M=2;
    cout<<findPages(A,N,M)<<endl;
	return 0;
}