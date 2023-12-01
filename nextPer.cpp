#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }

        if(index==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
        for(int i=n-1;i>index;i--){
            if(nums[index]<nums[i]){
                swap(nums[index],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }

        
    }



int main(){

    vector<int> nums={1,2,3};

    nextPermutation(nums);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}