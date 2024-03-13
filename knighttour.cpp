#include <bits/stdc++.h>
using namespace std;
#define N 8

int isSafe(int new_x,int new_y,int sol[N][N]){
    return (new_x<N && new_x>=0 && new_y<N && new_y>=0 && sol[new_x][new_y]==-1);
        
}

int solveUtil(int x,int y,int moveI,int sol[N][N],int xMove[8],int yMove[8]){
    int new_x,new_y,k;
    if(moveI==N*N){
        return 1;
    }

    for(k=0;k<8;k++){
        new_x=x+xMove[k];
        new_y=y+yMove[k];
        if(isSafe(new_x,new_y,sol)){
        sol[new_x][new_y]=moveI;
        if(solveUtil(new_x,new_y,moveI+1,sol,xMove,yMove)==1){
            return 1;
        }
        else{
            sol[new_x][new_y]=-1;
        }
      }
    }
    return 0;
}

void printBoard(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }cout<<endl;
    }
}

void solvekT(){
    int sol[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sol[i][j]=-1;
        }
    }

    sol[0][0]=0;
    int xMove[8]={2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8]={1, 2, 2, 1, -1, -2, -2, -1};
    int moveI=0;
    if(solveUtil(0,0,moveI+1,sol,xMove,yMove)==0){
        cout<<"no solution!!"<<endl;
    }else{
        printBoard(sol);
    }
}



int main(){

    
    solvekT();

	return 0;
}