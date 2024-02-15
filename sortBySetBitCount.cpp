#include<bits/stdc++.h>
using namespace std;

int countBit(int x){
        int count=0;
        while(x){
            if(x%2==1){
                count++;
            }
            x=x/2;
        }
        return count;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        unordered_map<int,vector<int>> m;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int x=countBit(arr[i]);
            m[x].push_back(arr[i]);
            maxi=max(x,maxi);
            mini=min(x,mini);
        }
        int index=0;
        for(int i=maxi;i>=mini;i--){
            if(m.count(i)){
                for(auto it:m[i]){
                    arr[index]=it;
                    index++;
                }
            }
        }
        return;
    }

int main(){
    
	int arr[]={1,5,3,7,2,8};
    int n=6;
    sortBySetBitCount(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}