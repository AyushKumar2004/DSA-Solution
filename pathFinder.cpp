#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

void solve(int i,int j,int mat[R][C],vector<int> curr,vector<vector<int>> &ans){
    if(i==R-1 && j==C-1){
        curr.push_back(mat[i][j]);
        ans.push_back(curr);
        curr.pop_back();
        return;
    }
    if(i<0 && i>R && j<0 && j>C) return;

    curr.push_back(mat[i][j]);
    if(j+1<C)
        solve(i,j+1,mat,curr,ans);
    if(i+1<R)
        solve(i+1,j,mat,curr,ans);
    curr.pop_back();
}

vector<vector<int>> pathFinder(int mat[R][C]){
    vector<vector<int>> ans;
    vector<int> curr;
    solve(0,0,mat,curr,ans);
    return ans;
}


int main()
{   

    int mat[R][C]={{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }} ;

    vector<vector<int>> ans=pathFinder(mat);

    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }cout<<endl;
    }

	return 0;
}