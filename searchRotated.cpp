#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& nums,int target){
        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
        while(start<end){
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=start+(end-start)/2;
        }

        return start;
    }

    int binarySearch(vector<int>& nums,int s,int e,int target){
        int start=s;
        int end=e;
        int mid=start+(end-start)/2;

        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot=getPivot(nums,target);
        if(target>=nums[pivot]&&target<=nums[nums.size()-1]){
            return binarySearch(nums,pivot,nums.size()-1,target);
        }
        else{
            return binarySearch(nums,0,pivot-1,target);
        }
    }



int main(){
    
	vector<int> nums={5,6,7,1,2};
    int n=5;
    int x=1;

    int ans=search(nums,x);

    cout<<ans<<endl;

    return 0;
}