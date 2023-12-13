#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr,int c,int x){
        int low=0;
        int high=c-1;
        int ans=c;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }

    int countSmallEqual(vector<vector<int>> &matrix,int r,int c, int x){
        int count=0;
        for(int i=0;i<r;i++){
            count+=upperBound(matrix[i],c,x);
        }
        return count;
    }


    int median(vector<vector<int>> &matrix, int R, int C){
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        
        int required=(R*C)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int smallEqual=countSmallEqual(matrix,R,C,mid);
            if(smallEqual<=required){
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return low;
    }


int main(){

    vector<vector<int>> arr={{1,2,3,4},
							  {5,6,7,8},
							  {9,10,11,12},
							   {13,14,15,16}};
    int z=median(arr,4,4);
    
	cout<<z<<endl;

    return 0;
}