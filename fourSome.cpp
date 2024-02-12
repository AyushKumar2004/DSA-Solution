#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-3;i++){
            if(i>0&&arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&& arr[j]==arr[j-1]) continue;
                int start=j+1;
                int end=n-1;
                int result=k-arr[i]-arr[j];
                while(start<end){
                        if(arr[start]+arr[end]==result){
                            ans.push_back({arr[i],arr[j],arr[start],arr[end]});
                            
                            while(start<end&&arr[start]==arr[start+1]) start++;
                            while(start<end&&arr[end]==arr[end-1]) end--;
                            start++;
                            end--;
                        }
                        else if(arr[start]+arr[end]<result){
                            start++;
                        }
                        else end--;
                    }
                }
            }
             return ans;
        }

int main(){
    
	vector<int> arr={0,0,2,1,1};
    int k=3;

    vector<vector<int>> ans=fourSum(arr,k);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    

    return 0;
}