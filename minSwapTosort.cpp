#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums)
	{   
	    int n=nums.size();
	    vector<pair<int,int>> V(n);
	    for(int i=0;i<n;i++){
	        V[i]={nums[i],i};
	    }
	    sort(V.begin(),V.end());
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(V[i].second==i) continue;
	        else{
	            swap(V[i],V[V[i].second]);
	            count++;
	            i--;
	        }
	    }
	    return count;
	}

int main(){
    
	vector<int> nums={1,5,3,7,2,8};
    int n=6;
    int x= minSwaps(nums);
    cout<<x<<endl;

    return 0;
}