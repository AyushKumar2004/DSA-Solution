#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& array,int a, int b)
    {
        int left=0;
        int mid=0;
        int right=array.size()-1;
        
        while(mid<=right){
            if(array[mid]<a){
                swap(array[mid],array[left]);
                left++;
                mid++;
            }
            else if(array[mid]>=a&&array[mid]<=b){
                mid++;
            }
            else{
                swap(array[mid],array[right]);
                right--;
            }
        }
    }


int main(){

    vector<int> arr={1,4,3,6,2,1};
	int n=1;
    int x=3;
    threeWayPartition(arr,n,x);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
	

    return 0;
}