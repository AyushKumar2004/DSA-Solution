#include<bits/stdc++.h>
using namespace std;

int specificPair(vector<vector<int>> Mat,int n,int m){
    vector<vector<int>> maxArr(n,vector<int>(m,0));
    maxArr[n-1][m-1]=Mat[n-1][m-1];
    int maxV=Mat[n-1][m-1];
    for(int i=n-2;i>=0;i--){
        if(Mat[n-1][i]>maxV){
            maxV=Mat[n-1][i];
        }
        maxArr[n-1][i]=maxV;
    }
    maxV=Mat[n-1][m-1];
    for(int i=n-2;i>=0;i--){
        if(Mat[i][n-1]>maxV){
            maxV=Mat[i][n-1];
        }
        maxArr[i][n-1]=maxV;
    }
    int maxValue=INT_MIN;
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(maxArr[i+1][j+1]-Mat[i][j]>maxValue){
                maxValue=maxArr[i+1][j+1]-Mat[i][j];
            }
            maxArr[i][j]=max(Mat[i][j],max(maxArr[i+1][j],maxArr[i][j+1]));
        }
    }

    return maxValue;
}


int main(){
    vector<vector<int>> Mat={
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    int z=specificPair(Mat,5,5);
    cout<<z<<endl;

    return 0;
}