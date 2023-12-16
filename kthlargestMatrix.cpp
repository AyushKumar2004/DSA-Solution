#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> &mat, int n, int k)
{
    priority_queue<int> pq;
    int low=mat[0][0];
    int high=mat[n-1][n-1];
    
    while(low<high){
        int mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        if(cnt<k){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return low;
}


int main(){
    vector<vector<int>> Mat={{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }};
    int n=4;
    int m=3;
    int z=kthSmallest(Mat,n,m);
    cout<<z<<endl;

    return 0;
}