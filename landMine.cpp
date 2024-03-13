#include <bits/stdc++.h>
using namespace std;

#define R 12
#define C 10

bool isValid(int x,int y, int mat[R][C]){
    if(x<R && x>=0 && y<C && y>=0 ){
        return true;
    }
    return false;
}

bool isSafe(int x,int y,int mat[R][C],int visited[R][C]){
    if(mat[x][y]==0 || visited[x][y]) return false;

    return true;
}

void makeValidMat(int mat[R][C],int rowNum[],int colNum[]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==0){
                for(int k=0;k<4;k++){
                    if(isValid(i+rowNum[k],j+colNum[k],mat)){
                        mat[i+rowNum[k]][j+colNum[k]]=-1;
                    }
                }
            }
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j]==-1){
                mat[i][j]=0;
            }
        }
    }
}


void findShortestPathUtil(int i,int col,int rowNum[],int colNum[],int mat[R][C],int visited[R][C],int &min_dist,int dist){
        if(col==C-1){
            min_dist=min(dist,min_dist);
            return;
        }
        if(dist>min_dist){
            return ;
        }

        visited[i][col]=1;

        for(int k=0;k<4;k++){
            if(isValid(i+rowNum[k],col+colNum[k],mat)&&isSafe(i+rowNum[k],col+colNum[k],mat,visited)){
                findShortestPathUtil(i+rowNum[k],col+colNum[k],rowNum,colNum,mat,visited,min_dist,dist+1);
            }
        }

        visited[i][col]=0;

}


void findShortestPath(int mat[R][C]){
    int rowNum[4]={-1,0,0,1};
    int colNum[4]={0,-1,1,0};

    int min_dist=INT_MAX;
    makeValidMat(mat,rowNum,colNum);


    int visited[R][C];

    for(int i=0;i<R;i++){
        if(mat[i][0]==1){
            memset(visited,0,sizeof(visited));
            
            findShortestPathUtil(i,0,rowNum,colNum,mat,visited,min_dist,0);

            if(min_dist==C-1){
                break;
            }
        }
    }

    if(min_dist!=INT_MAX){
        cout<<"the shortest distance between first and last column without distance is :"<<min_dist<<endl;
    }else{
        cout<<"no shportest path"<<endl;
    }
}


int main(){

    
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

    findShortestPath(mat);

	return 0;
}