#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 10

int longestPathUtil(int mat[R][C],int i,int j, int x, int y,int curr=0,int ans=-1){

    if(i==x && j==y){
        if(curr>ans){
            ans=curr;
        }
        return ans;
    }

    if(mat[i][j]==0 || mat[x][y]==0) return 0;

    mat[i][j]=0;
    if(j!=0 && mat[i][j-1]>0){
        ans=longestPathUtil(mat,i,j-1,x,y,curr+1,ans);
    }
    if(j!=C-1 && mat[i][j+1]>0){
        ans=longestPathUtil(mat,i,j+1,x,y,curr+1,ans);
    }
    if(i!=0 && mat[i-1][j]>0){
        ans=longestPathUtil(mat,i-1,j,x,y,curr+1,ans);
    }
    if(i!=R-1 && mat[i+1][j]>0){
        ans=longestPathUtil(mat,i+1,j,x,y,curr+1,ans);
    }

    mat[i][j]=1;

    return ans;           
}

void longestPath(int mat[R][C]){
    int ans=longestPathUtil(mat,0,0,1,7);
    if(ans!=-1){
    cout<<"the longest path of the matrix to reach the dest:"<<ans<<endl;
    }
    else{
        cout<<"there is no path the reach the destination"<<endl;
    }
}


int main()
{   

    int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

    longestPath(mat);

	return 0;
}