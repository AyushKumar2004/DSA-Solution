#include<bits/stdc++.h>
using namespace std;

vector<int> binarySearch(int arr[],int n, int x){
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        vector<int> v;
        while(start<=end){
            
            if(arr[mid]==x){
                start=mid-1;
                end=mid+1;
                
                while(arr[start]==x&&start>=0){
                    start--;
                }
                
                while(arr[end]==x&&end<=n-1){
                    end++;
                }
                
                v.push_back(start+1);
                v.push_back(end-1);
                return v;
            }
            
            else if(arr[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            
            mid=start+(end-start)/2;
        }
        
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
    
    
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans=binarySearch(arr,n,x);
        return ans;
    }




int main(){
    
	int arr[9]={1,3,5,5,5,5,23,123,125};
    int n=9;
    int x=5;

    vector<int> ans=find(arr,n,x);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}