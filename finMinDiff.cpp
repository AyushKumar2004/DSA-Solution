#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
        long long i=0;
        long long j=m-1;
        sort(a.begin(),a.end());
        long long diff=INT_MAX;
        while(j<n){
            if(a[j]-a[i]<diff){
                diff=a[j]-a[i];
            }
            
            i++;
            j++;
        }
        
        return diff;
    }


int main(){

    vector<long long> a1={11, 7, 1, 13, 21, 3, 7, 3};
	long long n=8;
    long long x=5;
    long long z=findMinDiff(a1,n,x);
    cout<<z<<endl;
	

    return 0;
}