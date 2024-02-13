#include<bits/stdc++.h>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<long long int,int> m;
        long long int sum=0;
        long long int ans=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(m.find(sum)!=m.end()){
                ans+=m[sum];
            }
            m[sum]++;
        }
        return ans;
    }

int main(){
    
	vector<long long int> arr={0,0,5,5,0,0};
    int n=6;
    cout<<findSubarray(arr,n)<<endl;

    return 0;
}