#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx,int newy,vector<vector<int>> &visited,vector<vector<int>> &m,int n){
        if((newx>=0&&newx<n) && (newy>=0&&newy<n) && visited[newx][newy]==0 && m[newx][newy]==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m,int n,int srcx,int srcy,vector<vector<int>> &visited,string path,vector<string> &ans){
        if(srcx==n-1 && srcy==n-1){
            ans.push_back(path);
        }
        visited[srcx][srcy]=1;
        //down
        int newx=srcx+1;
        int newy=srcy;
        if(isSafe(newx,newy,visited,m,n)){
            path.push_back('D');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        //left
        newx=srcx;
        newy=srcy-1;
        if(isSafe(newx,newy,visited,m,n)){
            path.push_back('L');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        //right
        newx=srcx;
        newy=srcy+1;
        if(isSafe(newx,newy,visited,m,n)){
            path.push_back('R');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        //up
        newx=srcx-1;
        newy=srcy;
        if(isSafe(newx,newy,visited,m,n)){
            path.push_back('U');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        visited[srcx][srcy]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0) return ans;
        int srcx=0;
        int srcy=0;
        vector<vector<int>> visited(n,vector<int>(n,0));
        string path="";
        solve(m,n,srcx,srcy,visited,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }

int main(){

	vector<vector<int>> m={{1, 0, 0, 0},
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    int N=4;
    vector<string> ans=findPath(m,N);
    for(int i=0;i<N;i++){
        cout<<ans[i]<<" ";
    }
    
	return 0;
}