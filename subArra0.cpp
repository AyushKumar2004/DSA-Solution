#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,int> m;
        int sum=0;
        int ans=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(m.find(sum)!=m.end()){
                ans+=m[sum];
                return true;
            }
            m[sum]++;
        }
        return false;
    }



int main(){

    int arr[10]={-5,-1,5,2,4,7,1,8,0,-8};
    int n=10;
    
    bool x=subArrayExists(arr,n);
    cout<<x<<endl;
    return 0;
}