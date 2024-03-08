#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                temp.push_back(j+1);
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int col,int row,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
        int x=row;
        int y=col;
        //check from left side
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        
        return true;
    }

    void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
        if(col==n){
             addSolution(ans,board,n);
             return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(col,row,ans,board,n)){
                board[row][col]=1;
                solve(col+1,ans,board,n);
                board[row][col]=0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        int col=0;
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ans;
        solve(col,ans,board,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
int main(){

	int n=4;
    
    vector<vector<int> > solutions = nQueen(n);
 
     for (const auto &solution : solutions) {
        cout << "[";
        for (int i = 0; i < n; ++i) {
            cout << solution[i] << (i == n - 1 ? " " : ", ");
        }
        cout << "]" << endl;
    }
    
	return 0;
}