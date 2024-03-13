#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &A,int B,vector<vector<int>> &ans,vector<int> &curr,int index){
        if(B==0){
            ans.push_back(curr);
            return;
        }
        if(B<0){
            return;
        }
        for(int i=index;i<A.size();i++){
            if(i!=index&&A[i]==A[i-1]) continue;
            curr.push_back(A[i]);
            solve(A,B-A[i],ans,curr,i);
            curr.pop_back();
        }
    }
    
vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(A.begin(),A.end());
        solve(A,B,ans,curr,0);
        return ans;
}


int main(){

    
    vector<int> A={7,2,6,5};
    int B=16;

    vector<vector<int>> ans=combinationSum(A,B);

    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }cout<<endl;
    }

	return 0;
}