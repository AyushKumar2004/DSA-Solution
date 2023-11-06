#include<bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0;i<N;i++){
            if(A[i]>maxi){
                maxi=A[i];
            }
    
            if(A[i]<mini){
                mini=A[i];
            }
        }
    
        return maxi+mini;
    }

};
