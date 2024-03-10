#include <bits/stdc++.h>
using namespace std;

#define N 9

bool isSafe(int grid[N][N],int row,int col,int key){
        
        for(int i=0;i<N;i++){
            //row check
            if(grid[row][i]==key){
                return false;
            }
            if(grid[i][col]==key){
                return false;
            }
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==key){
                return false;
            }
        }
        
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(grid,i,j,val)){
                        grid[i][j]=val;
                    bool aageSolutionPossible=SolveSudoku(grid);
                    if(aageSolutionPossible){
                        return true;
                    }
                    else{
                        grid[i][j]=0;
                    }
                  }
                }
                return false;
            }
        }
    }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N])
    {

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        } 
    }

int main(){

    int grid[N][N] = 
{{3,0,6,5,0,8,4,0,0},
{5,2,0,0,0,0,0,0,0},
{0,8,7,0,0,0,0,3,1},
{0,0,3,0,1,0,0,8,0},
{9,0,0,8,6,3,0,0,5},
{0,5,0,0,9,0,6,0,0},
{1,3,0,0,0,0,2,5,0},
{0,0,0,0,0,0,0,7,4},
{0,0,5,2,0,6,3,0,0}};

    if(SolveSudoku(grid)==true){
        printGrid(grid);
    }else{
        cout<<"no solution possible!"<<endl;
    }

	return 0;
}